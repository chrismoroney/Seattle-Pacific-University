#ifndef DIALERAPP_H
#define DIALERAPP_H

#include <QMainWindow>
#include "myaddressbookmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DialerApp; }
QT_END_NAMESPACE

class DialerApp : public QMainWindow
{
    Q_OBJECT

public:
    DialerApp(QWidget *parent = nullptr);
    ~DialerApp();

private slots:
    void on_actionOpen_an_Address_Book_triggered();

    void on_actionClose_Application_triggered();

    void on_phoneBook_pressed(const QModelIndex &index);

    void handleButton(QString buttonNumber);

    void on_button1_clicked();

    void on_buttonABC2_clicked();

    void on_buttonDEF3_clicked();

    void on_buttonGHI4_clicked();

    void on_buttonJKL5_clicked();

    void on_buttonMNO6_clicked();

    void on_buttonPQRS7_clicked();

    void on_buttonTUV8_clicked();

    void on_buttonWXYZ9_clicked();

    void on_button0_clicked();

    void on_button2_2_clicked();

    void on_button3_2_clicked();

    void on_button4_2_clicked();

    void on_button5_2_clicked();

    void on_button6_2_clicked();

    void on_button7_2_clicked();

    void on_button8_2_clicked();

    void on_button9_2_clicked();

    void on_button0_2_clicked();

    void on_backButton_clicked();

    void on_callButton_clicked();

private:
    Ui::DialerApp *ui;
    MyAddressBookModel *myModel;
    QString numberCont;

    // ATTEMPTED to load in images
/*
    QPixmap contacts;
    QPixmap phone;
    QPixmap back;

    void loadContactImage();
    void loadPhoneImage();
    void backButtonImage();
*/
};
#endif // DIALERAPP_H
