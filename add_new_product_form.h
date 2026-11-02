#ifndef ADD_NEW_PRODUCT_FORM_H
#define ADD_NEW_PRODUCT_FORM_H

#include <QDialog>

namespace Ui {
class add_new_product_form;
}

class add_new_product_form : public QDialog
{
    Q_OBJECT
public:
    explicit add_new_product_form(QWidget *parent = nullptr);
    ~add_new_product_form();

private:
    Ui::add_new_product_form *ui;
};

#endif // ADD_NEW_PRODUCT_FORM_H
