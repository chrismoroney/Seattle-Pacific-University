#ifndef MYADDRESSBOOKMODEL_H
#define MYADDRESSBOOKMODEL_H

#include <QAbstractTableModel>
#include <vector>

class MyAddressBookModel: public QAbstractTableModel
{
public:
    MyAddressBookModel(QObject *parent);


    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void openFile(QString filePath);

    QString getPhoneNumber(int index);
    // my methods
    QString getFirstName(int index);
    QString getLastName(int index);
    // my methods
    QString getNumberForString(QString loadName);
    QChar convertCharToNum(int numFromChar);
    // my method with two passed in strings
    void setFilterString(QString fStr, QString fStr2);

 private:
    std::vector<QString> firstNames;
    std::vector<QString> lastNames;
    std::vector<QString> phoneNumbers;
    // included from me
    std::vector<QString> firstNameNumbers;
    std::vector<QString> lastNameNumbers;

    std::vector<int> filteredIndex;

};

#endif // MYADDRESSBOOKMODEL_H
