#ifndef CANALRESERVATION_H
#define CANALRESERVATION_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class CanalReservation; }
QT_END_NAMESPACE

class CanalReservation : public QMainWindow
{
    Q_OBJECT
    // const int data set to price in reference to the room types
    const int ROOM_1 = 284;
    const int ROOM_2 = 325;
    const int ROOM_3 = 290;
    const int ROOM_4 = 350;

public:
    CanalReservation(QWidget *parent = nullptr);
    ~CanalReservation();

private slots:

    // push buttons
    void on_nextButton_clicked();

    void on_finalConfirmButton_clicked();

    void on_backButton_clicked();

    void on_exitButton_clicked();

    // radio buttons
    void on_standardQueen_clicked();

    void on_atriumQueen_clicked();

    void on_standardKing_clicked();

    void on_atriumKing_clicked();

    void on_americanExpressButton_clicked();

    void on_visaButton_clicked();

    void on_masterCardButton_clicked();

    void on_discoverButton_clicked();

    // check boxes
    void on_childrenYes_toggled(bool checked);

    void on_childrenNo_toggled(bool checked);

    void on_parkingYes_toggled(bool checked);

    void on_parkingNo_toggled(bool checked);

    // spin box update
    void on_numGuests_valueChanged(int arg1);

    void on_numNights_valueChanged(int arg1);

    // calculations
    double calculateCostRoom(const int roomType, const int numNights);

    double calculateCostRoomWithTax(const int roomType, const int numNights);

    double calculateCostResort(const int numNights);

    double calculateCostParking(const int numNights, const bool parkingNeeded);

    double calculateCostTotal(const int roomType, const int numNights, const bool parkingNeeded);

private:
    Ui::CanalReservation *ui;

    // images
    QPixmap room1;
    QPixmap room2;
    QPixmap room3;
    QPixmap room4;
    QPixmap backIm;
    QPixmap whiteIm;

    // variables used that I can reference without initializing (other than setting equal to)
    int cost;
    QString customerFirstName;
    QString customerLastName;
    int roomType;
    int numNights;
    int numAdults;
    int numChildren;
    bool parkingNeeded;
    QString cardType;
    double roomCost;
    double roomCostWithTax;
    double parkCost;
    double resortCost;
    double calculateTotal;

    // load images
    void loadStandardQueen();
    void loadAtriumQueen();
    void loadStandardKing();
    void loadAtriumKing();
    void loadBackImage();
    void loadWhiteBack();
};
#endif // CANALRESERVATION_H
