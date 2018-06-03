#include "textpluscontiuedialog.h"
#include "ui_textpluscontiuedialog.h"

textPlusContiueDialog::textPlusContiueDialog(QString text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::textPlusContiueDialog)
{
    ui->setupUi(this);

    ui->textLabel->setAlignment(Qt::AlignCenter);
    ui->textLabel->setText(text);
}

textPlusContiueDialog::~textPlusContiueDialog()
{
    delete ui;
}

void textPlusContiueDialog::on_pushButton_clicked()
{
    this->close();
}
