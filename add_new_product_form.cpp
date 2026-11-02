#include "add_new_product_form.h"
#include "ui_add_new_product_form.h"
#include"ZXingQt.h"
#include<QPainter>

add_new_product_form::add_new_product_form(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_new_product_form)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->lineEdit_barcode, &QLineEdit::textChanged, this, [this](const QString& barcode) {
        try {
            if (barcode.isEmpty()) {
                ui->label_barcode_preview->clear();
                return;
            }

            auto barcode_ = ZXingQt::Barcode::fromText(barcode, ZXingQt::BarcodeFormat::Code128);
            QImage barcodeImage = barcode_.toImage();

            const int textHeight = 24;
            const int padding    = 4;
            const int fontPx     = 16;

            QImage result(barcodeImage.width(),
                          barcodeImage.height() + textHeight + padding,
                          QImage::Format_ARGB32);
            result.fill(Qt::white);

            QPainter painter(&result);
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setRenderHint(QPainter::TextAntialiasing, true);
            painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

            painter.drawImage(0, 0, barcodeImage);

            QFont font = painter.font();
            font.setPixelSize(fontPx);
            font.setBold(false);
            painter.setFont(font);
            painter.setPen(Qt::black);

            QRect textRect(0,
                           barcodeImage.height() + padding / 2,
                           result.width(),
                           textHeight);

            painter.drawText(textRect,
                             Qt::AlignHCenter | Qt::AlignVCenter,
                             barcode);

            painter.end();

            QSize targetSize = ui->label_barcode_preview->size();
            if (targetSize.isEmpty()) {
                targetSize = QSize(350, 120);
            }

            QPixmap pixmap = QPixmap::fromImage(
                result.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

            ui->label_barcode_preview->setPixmap(pixmap);
        }
        catch (const std::invalid_argument& ia) {
            ui->label_barcode_preview->setText(ia.what());
        }
    });
}

add_new_product_form::~add_new_product_form()
{
    delete ui;
}
