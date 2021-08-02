#include "firstwidgetapp.h"
#include "ui_firstwidgetapp.h"

firstWidgetApp::firstWidgetApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::firstWidgetApp)
{
    ui->setupUi(this);
}

firstWidgetApp::~firstWidgetApp()
{
    delete ui;
}


void firstWidgetApp::on_updateButton_clicked()
{
    QString message = ui->messageTextBox->toPlainText();
    if (message.isEmpty())
    {
        ui->targetTextLabel->setText("Enter non-empty message.");
    }
    else
    {
        ui->targetTextLabel->setText(message);
    }
}

void firstWidgetApp::on_backgroundBlueButton_clicked()
{

    QPalette palette = ui->targetTextLabel->palette();
    QColor color = {83, 124, 124};
    palette.setColor(QPalette::Window, color);

    ui->targetTextLabel->setAutoFillBackground(true);
    ui->targetTextLabel->setPalette(palette);
}

void firstWidgetApp::on_backgroundRedButton_clicked()
{
    QPalette palette = ui->targetTextLabel->palette();
    QColor color = {255, 100, 104};
    palette.setColor(QPalette::Window, color);

    ui->targetTextLabel->setAutoFillBackground(true);
    ui->targetTextLabel->setPalette(palette);
}

void firstWidgetApp::on_backgroundYellowButton_clicked()
{
    QPalette palette = ui->targetTextLabel->palette();
    QColor color = {255, 228, 152};
    palette.setColor(QPalette::Window, color);

    ui->targetTextLabel->setAutoFillBackground(true);
    ui->targetTextLabel->setPalette(palette);
}

void firstWidgetApp::on_backgroundGreenButton_clicked()
{
    QPalette palette = ui->targetTextLabel->palette();
    QColor color = {31, 176, 0};
    palette.setColor(QPalette::Window, color);

    ui->targetTextLabel->setAutoFillBackground(true);
    ui->targetTextLabel->setPalette(palette);
}

void firstWidgetApp::on_foregroundBlueButton_clicked()
{
    QPalette palette = ui->targetTextLabel->palette();
    QColor color = {55, 69, 103};
    palette.setColor(QPalette::WindowText, color);

    ui->targetTextLabel->setPalette(palette);
}

void firstWidgetApp::on_foregroundRedButton_clicked()
{
    QPalette palette = ui->targetTextLabel->palette();
    QColor color = {104, 0, 5};
    palette.setColor(QPalette::WindowText, color);

    ui->targetTextLabel->setPalette(palette);
}

void firstWidgetApp::on_foregroundYellowButton_clicked()
{
    QPalette palette = ui->targetTextLabel->palette();
    QColor color {209, 155, 15};
    palette.setColor(QPalette::WindowText, color);

    ui->targetTextLabel->setPalette(palette);
}

void firstWidgetApp::on_foregroundGreenButton_clicked()
{
    QPalette palette = ui->targetTextLabel->palette();
    QColor color = {108, 135, 67};
    palette.setColor(QPalette::WindowText, color);

    ui->targetTextLabel->setPalette(palette);
}

void firstWidgetApp::on_leftButton_clicked()
{
    ui->targetTextLabel->setAlignment(Qt::AlignLeft);
}

void firstWidgetApp::on_centerButton_clicked()
{
    ui->targetTextLabel->setAlignment(Qt::AlignHCenter);
}

void firstWidgetApp::on_rightButton_clicked()
{
    ui->targetTextLabel->setAlignment(Qt::AlignRight);
}

void firstWidgetApp::on_endButton_clicked()
{
    QApplication::quit();
}

void firstWidgetApp::on_resetButton_clicked()
{
    QPalette paletteBack = ui->targetTextLabel->palette();
    paletteBack.setColor(QPalette::Window, Qt::darkGray);

    ui->targetTextLabel->setAutoFillBackground(true);
    ui->targetTextLabel->setPalette(paletteBack);

    QPalette paletteFore = ui->targetTextLabel->palette();
    paletteFore.setColor(QPalette::WindowText, Qt::white);

    ui->targetTextLabel->setPalette(paletteFore);

    ui->targetTextLabel->setText("Hi There");

    ui->targetTextLabel->setAlignment(Qt::AlignLeft);
}
