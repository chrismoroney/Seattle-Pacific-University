#include "myaddressbookmodel.h"
#include "dialerapp.h"
#include <QFile>
#include <QMessageBox>
#include <iostream>
#include <QTextStream>

MyAddressBookModel::MyAddressBookModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

// method that records the number of rows we have in the csv
int MyAddressBookModel::rowCount(const QModelIndex &parent) const
{
    return filteredIndex.size();
}

// method that records number of columns we want to record (3)
int MyAddressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

// method that contains all of our data from the csv
QVariant MyAddressBookModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        switch(index.column())
        {
            case 0:
                return firstNames.at(filteredIndex[index.row()] - 1);
            case 1:
                return lastNames.at(filteredIndex[index.row()] - 1);
            case 2:
                return phoneNumbers.at(filteredIndex[index.row()] - 1);
        }
    }

    return QVariant();
}

// method that allows us to be able to open our file
void MyAddressBookModel::openFile(QString filePath)
{
    QFile file(filePath);
    // display error message if we couldn't open the file
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QTextStream in(&file);

    firstNames.clear();
    lastNames.clear();
    phoneNumbers.clear();

    // I added these vectors in to be able to convert all names to number sequences according to the dialer
    firstNameNumbers.clear();
    lastNameNumbers.clear();

    for (int i = 0; (!in.atEnd()); i++)
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if (i == 0) continue;

        for(int j = 0; j < fields.length(); j++)
        {
            std::cout << "[" << j << "]" << fields[j].toStdString();
        }
        std::cout << std::endl;

        firstNames.push_back(fields[0]);
        lastNames.push_back(fields[1]);
        phoneNumbers.push_back(fields[7]);

        // created a method that will return the number sequence of each first name, then put it into the created vector
        QString firstNameNumber = getNumberForString(fields[0]);
        firstNameNumbers.push_back(firstNameNumber);

        // created a method that will return the number sequence of each last name, then put it into the created vector
        QString lastNameNumber = getNumberForString(fields[1]);
        lastNameNumbers.push_back(lastNameNumber);

        filteredIndex.push_back(i);
    }

    file.close();

    emit layoutChanged();
}

// created method that creates and returns a string according to the name entered as a parameter.
QString MyAddressBookModel::getNumberForString(QString loadName)
{
    // empty return string to start
    QString returnStr = "";
    // for each letter in the parameter name
    for(int i = 0; i < loadName.length(); i++)
    {   
        // extract a char and set it as upper case. We set it as upper case to reduce
        // the total number of ASCII values we have to keep track of in convertCharToNum
        QChar numFromChar = loadName.at(i).toUpper();
        // set an int equal to the int number of the char at position i for the name
        int charValue = numFromChar.toLatin1();
        // char is turned into a number using convertCharToNum.
        QChar convertedVal = convertCharToNum(charValue);
        // add the char to a continual string of chars turned into numbers
        returnStr = returnStr + convertedVal;
    }
    // name now turned into sequence of numbers
    return returnStr;
}

// created method that takes the ASCII values from getNumberForString characters, and assigns
// them number values related to the dialer's letters
QChar MyAddressBookModel::convertCharToNum(int numFromChar){
    QChar returnVal;
    switch(numFromChar){
        // ABC = 2
        case 65:
        case 66:
        case 67:
            returnVal='2';
            break;
        // DEF = 3
        case 68:
        case 69:
        case 70:
            returnVal='3';
            break;
        // GHI = 4
        case 71:
        case 72:
        case 73:
            returnVal='4';
            break;
        // JKL = 5
        case 74:
        case 75:
        case 76:
            returnVal='5';
            break;
        // MNO = 6
        case 77:
        case 78:
        case 79:
            returnVal='6';
            break;
        // PQRS = 7
        case 80:
        case 81:
        case 82:
        case 83:
            returnVal='7';
            break;
        // TUV = 8
        case 84:
        case 85:
        case 86:
            returnVal='8';
            break;
        // WXYZ = 9
        case 87:
        case 88:
        case 89:
        case 90:
            returnVal='9';
            break;
        // default set to one in case we have an emergency (unlikely)
         default:
            returnVal='1';
            break;
    }
    // return the dialer number according to sent in charaxter
    return returnVal;

}

// returns phone number of a contact
QString MyAddressBookModel::getPhoneNumber(int index)
{
    return phoneNumbers.at(filteredIndex[index] - 1);
}

// returns first name of a contact
QString MyAddressBookModel::getFirstName(int index)
{
    return firstNames.at(filteredIndex[index] - 1);
}
// returns last name of a contact
QString MyAddressBookModel::getLastName(int index)
{
    return lastNames.at(filteredIndex[index] - 1);
}

// sets filter on contact based on what we type into dialer.
void MyAddressBookModel::setFilterString(QString fStr, QString fStr2)
{
    // check if phone numbers are starting with fStr
    filteredIndex.clear();

    // extra copy of sent in string from dialerapp.cpp is because if the sequence
    // of numbers from names have no hyphones, so the extra copy of the string has no hyphens,
    // while the other string does. We use the string with hyphens to compare the phone numbers,
    // and the string without hyphens to compare names
    fStr2.remove("-");

    // check all contacts to see if it matches our input from dialer
    for (int i = 1; i < phoneNumbers.size(); i++)
    {
        if (phoneNumbers[i-1].startsWith(fStr) || firstNameNumbers[i-1].startsWith(fStr2) || lastNameNumbers[i-1].startsWith(fStr2))
        {
            filteredIndex.push_back(i);
        }
    }

    emit layoutChanged();
}

