#include "dialerapp.h"
#include "ui_dialerapp.h"

#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

DialerApp::DialerApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DialerApp),
    myModel(new MyAddressBookModel(this))
{
    ui->setupUi(this);
    ui->phoneBook->setModel(myModel);

    QString numberCont = "";

    // set background and font colors
    ui->button0->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->button0_2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->button1->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->buttonABC2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->button2_2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->buttonDEF3->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->button3_2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->buttonGHI4->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->button4_2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->buttonJKL5->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->button5_2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->buttonMNO6->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->button6_2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->buttonPQRS7->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->button7_2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->buttonTUV8->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->button8_2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->buttonWXYZ9->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");
    ui->button9_2->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->callButton->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(38, 212, 64 )");
    ui->contactsButton->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(65, 70, 66)");
    ui->backButton->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(65, 70, 66)");
    ui->buttonAster->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->buttonHashtag->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(174, 180, 175)");
    ui->backgroundDialer->setStyleSheet("background-color: rgb(3, 90, 23); color: rgb(3, 137, 23)");
    ui->backgroundDialer_2->setStyleSheet("background-color: rgb(3, 90, 23); color: rgb(3, 137, 23)");
    ui->whitebackDialer->setStyleSheet("background-color: rgb(255, 255, 255); color: rgb(3, 137, 23)");

    // I attempted to load in images to fit in a small space to make symbols
    // representing contacts, back, etc. But i couldn't figure it out, so I used
    // words on the buttons and just commented these out
/*
    ui->contactImage->setPixmap(contacts);
    ui->phoneImage->setPixmap(phone);
    ui->backImage->setPixmap(back);
    */
}

DialerApp::~DialerApp()
{
    delete ui;
} 

// method to load a csv file into program (list of contacts from files) from menu
void DialerApp::on_actionOpen_an_Address_Book_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Address Book"), "",
        tr("Address Book (*.csv);;All Files (*)"));

    std::cout << fileName.toStdString() << std::endl;

    myModel->openFile(fileName);
}

// method to quit application from menu
void DialerApp::on_actionClose_Application_triggered()
{
    QApplication::quit();
}

// method that displays the contact info on the dialer page of a selected contact in the contactbook
void DialerApp::on_phoneBook_pressed(const QModelIndex &index)
{
    std::cout << index.row() << "," << index.column() << std::endl;
    // displays the full name of the person highlighted in contact book
    ui->nameReveal->setText(myModel->getFirstName(index.row()) + " " + myModel->getLastName(index.row()));
    // displays phone number of person highlighted
    ui->numberReveal_2->setText(myModel->getPhoneNumber(index.row()));
}

// method that displays buttons pushed as they are pushed. Passes in a string that
// is continually building on another string, so eventually the string will look like
// a phone number
void DialerApp::handleButton(QString buttonNumber)
{
    // keep adding onto the string, which will display the string of numbers
    numberCont = numberCont + buttonNumber;

    // if length is 3 or 7, we need to insert hyphens for phone number to look like XXX-XXX-XXXX
    if (numberCont.length() == 3 || numberCont.length() == 7)
    {
        numberCont = numberCont + "-";
    }
    // pass two copies of the string into setFilterString
    myModel->setFilterString(numberCont, numberCont);
    // set the text of this label to the phone number currently entered in
    ui->numberDisplay->setText(numberCont);
}

// button that enters a 1
void DialerApp::on_button1_clicked()
{
    handleButton("1");
}

// button that enters a 2
void DialerApp::on_buttonABC2_clicked()
{
    handleButton("2");
}

// button that enters a 3
void DialerApp::on_buttonDEF3_clicked()
{
    handleButton("3");
}

// button that enters a 4
void DialerApp::on_buttonGHI4_clicked()
{
    handleButton("4");
}

// button that enters a 5
void DialerApp::on_buttonJKL5_clicked()
{
    handleButton("5");
}

// button that enters a 6
void DialerApp::on_buttonMNO6_clicked()
{
    handleButton("6");
}

// button that enters a 7
void DialerApp::on_buttonPQRS7_clicked()
{
    handleButton("7");
}

// button that enters a 8
void DialerApp::on_buttonTUV8_clicked()
{
    handleButton("8");
}

// button that enters a 9
void DialerApp::on_buttonWXYZ9_clicked()
{
    handleButton("9");
}

// button that enters a 0
void DialerApp::on_button0_clicked()
{
    handleButton("0");
}

// alternate button that enters a 2
void DialerApp::on_button2_2_clicked()
{
    handleButton("2");
}

// alternate button that enters a 3
void DialerApp::on_button3_2_clicked()
{
    handleButton("3");
}

// alternate button that enters a 4
void DialerApp::on_button4_2_clicked()
{
    handleButton("4");
}

// alternate button that enters a 5
void DialerApp::on_button5_2_clicked()
{
    handleButton("5");
}

// alternate button that enters a 6
void DialerApp::on_button6_2_clicked()
{
    handleButton("6");
}

// alternate button that enters a 7
void DialerApp::on_button7_2_clicked()
{
    handleButton("7");
}

// alternate button that enters a 8
void DialerApp::on_button8_2_clicked()
{
    handleButton("8");
}

// alternate button that enters a 9
void DialerApp::on_button9_2_clicked()
{
    handleButton("9");
}

// alternate button that enters a 0
void DialerApp::on_button0_2_clicked()
{
    handleButton("0");
}

// button that deletes last character entered
void DialerApp::on_backButton_clicked()
{
    // remove last number entered into string
    numberCont = numberCont.remove(numberCont.length() - 1, 1);
    // if the length is 3 after removing, we need to also remove the hyphon, so delete one more char
    if (numberCont.length() == 3 || numberCont.length() == 7)
    {
        numberCont = numberCont.remove(numberCont.length() - 1, 1);
    }
    // send number to setFilterString
    myModel->setFilterString(numberCont, numberCont);
    // set text to new number
    ui->numberDisplay->setText(numberCont);
}

// when we hit call button, displays message that indicates we are calling that person
void DialerApp::on_callButton_clicked()
{
    QMessageBox call;
    call.setText("Calling " + ui->nameReveal->text() + " ...");
    call.setWindowTitle("Calling");
    call.exec();
}

// ATTEMPTED to load images to represent call, contacts, back etc, but didn't work.

/*
void DialerApp::loadContactImage()
{
    QString contactImage = ":/contacts.png";
    if(contacts.load(contactImage))
    {
        contacts = contacts.scaled(ui->contactsButton->size(), Qt::KeepAspectRatioByExpanding);
    }
}
void DialerApp::loadPhoneImage()
{
    QString callImage = ":/callButton.png";
    if(phone.load(callImage))
    {
        phone = phone.scaled(ui->callButton->size(), Qt::KeepAspectRatioByExpanding);
    }
}
void DialerApp::backButtonImage()
{
    QString backImage = ":/backArrow.png";
    if(back.load(backImage))
    {
        back = back.scaled(ui->backButton->size(), Qt::KeepAspectRatioByExpanding);
    }
}
*/




