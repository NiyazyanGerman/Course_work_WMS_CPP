#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"add_new_product_form.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_add_new_product_clicked()
{
    add_new_product_form* form = new add_new_product_form(this);
    form->exec();
}

