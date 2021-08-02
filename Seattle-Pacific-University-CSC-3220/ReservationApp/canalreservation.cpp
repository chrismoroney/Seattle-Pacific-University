#include "canalreservation.h"
#include "ui_canalreservation.h"

#include <QMessageBox>

// primary constructor
CanalReservation::CanalReservation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CanalReservation)
{
    ui->setupUi(this);
/*
// ** INITIAL SETUP ** \\
*/
    // All images loaded into app
    loadStandardQueen();
    loadAtriumQueen();
    loadStandardKing();
    loadAtriumKing();
    loadBackImage();
    loadWhiteBack();

    // Number of nights defaulted to one, assuming user must stay at least one night
    numNights = 1;

    // disable moving of spinbox without selecting room first
    ui->numGuests->setMaximum(1);


    // colors of buttons used to move between pages, only accents for a professional black and white

    // forward buttons = {254, 233, 185} -- I tried to match a sandy color for a "resort"
    // backs and exits = {249, 119, 119} -- These colors help pop and maintain black font, indicates exiting.

    ui->nextButton->setStyleSheet("background-color: rgb(254, 233, 185); color: rgb(0, 0, 0)");
    ui->finalConfirmButton->setStyleSheet("background-color: rgb(254, 233, 185); color: rgb(0, 0, 0)");

    ui->backButton->setStyleSheet("background-color: rgb(249, 119, 119); color: rgb(0, 0, 0)");
    ui->exitButton->setStyleSheet("background-color: rgb(249, 119, 119); color: rgb(0, 0, 0)");

    // start on first page
    ui->stackedWidget->setCurrentIndex(0);

    // default number of guests and children
    ui->numGuests->setValue(1);
    ui->numChildren->setValue(0);

    // hide label in first page until checked
    ui->numChildrenLabel->hide();
    ui->numChildren->hide();

    // set up title background in all three pages
    ui->backImageLabel->setPixmap(backIm);
    ui->backImageLabel2->setPixmap(backIm);
    ui->backImageLabel3->setPixmap(backIm);

    // set up white background, I couldn't figure out how to set up white color background
    ui->whiteBackground1->setPixmap(whiteIm);
    ui->whiteBackground2->setPixmap(whiteIm);
    ui->whiteBackground3->setPixmap(whiteIm);

    // default card max length, designed for someone to click a card type first
    ui->cardNumber->setMaxLength(0);

    // default date to todays date, not intended to pick a date before then
    QDate date = QDate::currentDate();
    ui->calenderDate->setDate(date);

/*
\\ ** END OF INITIAL SETUP ** //
*/
}

// destructor
CanalReservation::~CanalReservation()
{
    delete ui;
}

// ** IMAGE LOADING ** \\

// loading images: load all of my images from my resources files
// load image for standard queen
void CanalReservation::loadStandardQueen()
{
    QString roomType1 = ":/room.jpeg";
    if(room1.load(roomType1))
    {
        room1 = room1.scaled(ui->roomImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
}
// load image for atrium queen
void CanalReservation::loadAtriumQueen()
{
    QString roomType2 = ":/room2.jpeg";
    if(room2.load(roomType2))
    {
        room2 = room2.scaled(ui->roomImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
}
// load image for standard king
void CanalReservation::loadStandardKing()
{
    QString roomType3 = ":/room3.jpeg";
    if(room3.load(roomType3))
    {
        room3 = room3.scaled(ui->roomImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
}
// load image for atrium King
void CanalReservation::loadAtriumKing()
{
    QString roomType4 = ":/room4.jpeg";
    if(room4.load(roomType4))
    {
        room4 = room4.scaled(ui->roomImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
}
// load image for beach in top section
void CanalReservation::loadBackImage()
{
    QString backImage = ":/beach.jpeg";
    if(backIm.load(backImage))
    {
        backIm = backIm.scaled(ui->backImageLabel->size(), Qt::KeepAspectRatioByExpanding);
    }
}
// load image for background white color
void CanalReservation::loadWhiteBack(){
    QString whiteBack = ":/White.jpg";
    if(whiteIm.load(whiteBack))
    {
        whiteIm = whiteIm.scaled(ui->whiteBackground1->size(), Qt::KeepAspectRatioByExpanding);
    }
}
/*
// ** END OF IMAGE LOADING ** \\
*/

// ** PUSH BUTTONS ** \\

// next button on first page, lots of things are set and appear
void CanalReservation::on_nextButton_clicked()
{
    // take contents of line edit and make them string values
    customerFirstName = ui->firstNameEdit->toPlainText();
    customerLastName = ui->lastNameEdit->toPlainText();
    // red color to establish if we need to make more fields
    QPalette palette = ui->completeFieldsLabel->palette();
    palette.setColor(QPalette::WindowText, Qt::red);
    // black color to switch in case we switch from red
    QPalette original = ui->completeFieldsLabel->palette();
    original.setColor(QPalette::WindowText, Qt::black);

    // cases are set in order to check if we should move to the second page
    bool case1 = customerFirstName.isEmpty();
    bool case2 = !ui->standardQueen->isChecked() && !ui->atriumQueen->isChecked() &&
        !ui->standardKing->isChecked() && !ui->atriumKing->isChecked();
    bool case3 = !ui->childrenYes->isChecked() && !ui->childrenNo->isChecked();
    bool case4 = !ui->parkingYes->isChecked() && !ui->parkingNo->isChecked();
    bool case5 = customerLastName.isEmpty();

    // if we have any of the cases, we don't move on to second page
    if (case1 || case2 || case3 || case4 || case5){
        // create message box to say that user needs to complete all fields
        QMessageBox completeAll;
        completeAll.setText("Please complete all fields");
        completeAll.setWindowTitle("Error");
        completeAll.exec();
        // create the text that says to complete all fields, and set it red
        ui->completeFieldsLabel->setText("Please complete all fields");
        ui->completeFieldsLabel->setPalette(palette);
    }

    // for each specific case that is shown as above, we set it either as red or black, depending if the field is empty or unselected

    // if the first name of customer is empty
    if (case1){
        ui->firstNameLabel->setPalette(palette);
    }
    else
    {
        ui->firstNameLabel->setPalette(original);
    }
    // if no roomtype is selected
    if (case2)
    {
        ui->roomGroupBox->setPalette(palette);
    }
    else
    {
        ui->roomGroupBox->setPalette(original);
    }
    // if no child selection is picked (or rather is unchecked)
    if (case3)
    {
        ui->childrenConfirmLabel->setPalette(palette);
    }
    else
    {
        ui->childrenConfirmLabel->setPalette(original);
    }
    // if no parking selection is picked or unpicked
    if (case4)
    {
        ui->parkingLabel->setPalette(palette);
    }
    else
    {
        ui->parkingLabel->setPalette(original);
    }
    // if customer last name is empty
    if (case5)
    {
        ui->lastNameLabel->setPalette(palette);
    }
    else
    {
        ui->lastNameLabel->setPalette(original);
    }

    // if we dont have any of the cases, then we can move onto next page
    if (!case1 && !case2 && !case3 && !case4 && !case5)
    {
        // in case we go back, get rid of text saying to complete all fields, set it to black right now
        ui->completeFieldsLabel->setPalette(original);
        ui->completeFieldsLabel->setText("");
        // move to page 2
        ui->stackedWidget->setCurrentIndex(1);
        // customer name combined from both line edits
        ui->resName->setText(customerFirstName + " " + customerLastName);
        // number of nights made from into to field, set in text
        ui->numNightsConfirm->setText(QString::number(numNights));
        // date is put into page as string
        QDate theDate = ui->calenderDate->date();
        QString theDateString = theDate.toString();
        ui->confirmDate->setText(theDateString);

        // calculate cost for number of nights, is put in if loop only for the night vs nights text
        if (numNights == 1)
        {
            ui->roomCostLabel->setText("Room Cost (" + QString::number(numNights) + " night):");
            ui->parkingFeeLabel->setText("Parking Cost (" + QString::number(numNights) + " night):");
            ui->resortFeeLabel->setText("Resort Cost (" + QString::number(numNights) + " night): ");
        }
        else
        {
            ui->roomCostLabel->setText("Room Cost (" + QString::number(numNights) + " nights):");
            ui->parkingFeeLabel->setText("Parking Cost (" + QString::number(numNights) + " nights):");
            ui->resortFeeLabel->setText("Resort Cost (" + QString::number(numNights) + " nights): ");
        }

        // call all of these functions, using const data types (methods all found below)
        roomCost = calculateCostRoom(roomType, numNights);
        roomCostWithTax = calculateCostRoomWithTax(roomType, numNights);
        parkCost = calculateCostParking(numNights, parkingNeeded);
        resortCost = calculateCostResort(numNights);
        calculateTotal = calculateCostTotal(roomType, numNights, parkingNeeded);

        // show all fees as a double. We use QString::number to change int to string, 'f' represents float, and to 2 decimal places
        ui->roomLabelCost->setText("$" + QString::number(roomCost, 'f', 2) + " ($" + QString::number(roomCostWithTax, 'f', 2) + ")");
        ui->resortFeeCost->setText("$" + QString::number(resortCost, 'f', 2));
        ui->parkingFeeCost->setText("$" + QString::number(parkCost, 'f', 2));
        ui->calcTotalCost->setText("$" + QString::number(calculateTotal, 'f', 2));

        // number of adults and children, info grabbed from spinbox on first page
        numAdults = ui->numGuests->value() - ui->numChildren->value();
        numChildren = ui->numChildren->value();

        // int to string for number of adult and children
        ui->numAdultNum->setText(QString::number(numAdults));
        ui->numChildrenNum->setText(QString::number(numChildren));
    }
}
// final button on second page to confirm total payment and info
void CanalReservation::on_finalConfirmButton_clicked()
{
    // create red for fields that need to be completed
    QPalette palette = ui->completeFieldsLabel->palette();
    palette.setColor(QPalette::WindowText, Qt::red);
    // when completed, can turn back into black
    QPalette original = ui->completeFieldsLabel->palette();
    original.setColor(QPalette::WindowText, Qt::black);
    // card number value from line edit is made as a string for putting into a label
    QString cardNumber = ui->cardNumber->text();

    // cases made for any empty fields on the second page
    bool case1 = !ui->americanExpressButton->isChecked() && !ui->visaButton->isChecked() &&
        !ui->masterCardButton->isChecked() && !ui->discoverButton->isChecked();
    bool case2 = cardNumber.length() < ui->cardNumber->maxLength();

    // for first case, if card is not selected, then we display this message first to pick a card
    if (case1)
    {
        // message box comes up telling user to pick a card option
        QMessageBox completeAll1;
        completeAll1.setText("Please select payment option");
        completeAll1.setWindowTitle("Error");
        completeAll1.exec();

        // set text area to red and to select an option
        ui->paymentReminder->setText("Please select payment option");
        ui->paymentReminder->setPalette(palette);
        ui->cardOptions->setPalette(palette);
    }
    // once user does this, the card option area will turn black, indicating that card is selected
    else
    {
        ui->cardOptions->setPalette(original);
    }
    // for second case, the card information is not filled in completely, so messages indicate this
    if (case2)
    {
        // message box comes up telling user to complete card info
        QMessageBox completeAll2;
        completeAll2.setText("Please enter full card number");
        completeAll2.setWindowTitle("Error");
        completeAll2.exec();

        // set text area to red and to fill in blank areas
        ui->paymentReminder->setText("Please enter full card number");
        ui->paymentReminder->setPalette(palette);
        ui->cardNumberLabel->setPalette(palette);

    }
    // once this is complete, set card area back to black
    else
    {
        ui->cardNumberLabel->setPalette(original);

    }
    // if neither of these cases come up, then we can move to final page
    if (!case1 && !case2)
    {
        // go to second page
        ui->stackedWidget->setCurrentIndex(2);

        // if parking is needed, then we indicate this on the last page. Otherwise everything else in this section is the same
        // we retrieve all of the values from out UI and put them into our summary
        if (parkingNeeded){
            QString resInfo = customerFirstName + " " + customerLastName + "\n" + ui->roomStyle->text() + "\n"
                + ui->calenderDate->date().toString() + "\n" + QString::number(numNights) + " night(s) with " + QString::number(numAdults) +
                " adult(s) and " + QString::number(numChildren) + " child(s)\nInclude parking ($12.75 / night)";
            ui->resInfoPt1->setText(resInfo);
        }
        else
        {
            QString resInfo = customerFirstName + " " + customerLastName + "\n" + ui->roomStyle->text() + "\n"
                + ui->calenderDate->date().toString() + "\n" + QString::number(numNights) + " night(s) with " + QString::number(numAdults) +
                " adult(s) and " + QString::number(numChildren) + " child(s)\nNo parking";
            ui->resInfoPt1->setText(resInfo);
        }

        // retrieve card info in form of string
        QString cardNum = ui->cardNumber->text();
        // we want last 5 numbers to put in summary (last page), if its not A. E., then we want only last 4 numbers
        QString lastFew = cardNum.right(5);
        if (!cardType.contains("American Express"))
        {
            lastFew = lastFew.right(4);
        }
        // put this all in our summary in the money area
        ui->resInfoPt2->setText("Paid: $" + QString::number(calculateTotal, 'f', 2) + "\nPaid with " + cardType +
            " ending in "+ lastFew + "\nExpires on " + QString::number(ui->expireMonth->value()) +
            " / " + QString::number(ui->expireYear->value()));
    }
}
// if our back button is hit on the 2nd page, we go back to first page to edit any info
void CanalReservation::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
// when exit button is clicked on last page, we exit the app
void CanalReservation::on_exitButton_clicked()
{
    QApplication::quit();
}
/*
\\ ** END OF PUSH BUTTONS ** //
*/

/*
// ** RADIO BUTTONS IN GROUP BOXS ** \\
*/

// ROOM RADIO BUTTONS

// when Standard Queen Room is selected
void CanalReservation::on_standardQueen_clicked()
{
    // roomType = const int type in h file, which is the price (ROOM_1 = 284)
    roomType = ROOM_1;
    ui->roomImageLabel->setPixmap(room1);

    // reset the minimum number of guests, in case someone selects to have children in one room, but then not in another
    ui->numGuests->setMinimum(1);

    // this room allows for maximum number of 4 guests
    ui->numGuests->setMaximum(4);
    ui->maxGuestsLabel->setText("(Maximum of 4 Guests)");

    // right now, allowed to have 0 children
    ui->numChildren->setMinimum(0);
    // default each selection to no children
    ui->childrenNo->setChecked(true);

    // set text later on second page to this text
    ui->roomStyle->setText("Standard 2-Queen: $284 / night");
}
// when Atrium Queen Room is selected
void CanalReservation::on_atriumQueen_clicked()
{
    // roomType = const int type in h file, which is the price (ROOM_2 = 325)
    roomType = ROOM_2;
    ui->roomImageLabel->setPixmap(room2);

    // reset the minimum number of guests, in case someone selects to have children in one room, but then not in another
    ui->numGuests->setMinimum(1);
    // this room allows for maximum number of 4 guests
    ui->numGuests->setMaximum(4);
    ui->maxGuestsLabel->setText("(Maximum of 4 Guests)");

    // right now, allowed to have 0 children
    ui->numChildren->setMinimum(0);
    // default each selection to no children
    ui->childrenNo->setChecked(true);

    ui->roomStyle->setText("Atrium 2-Queen: $325 / night");
}

// when Standard King Room is selected
void CanalReservation::on_standardKing_clicked()
{
    // roomType = const int type in h file, which is the price (ROOM_3 = 290)
    roomType = ROOM_3;
    ui->roomImageLabel->setPixmap(room3);

    // reset the minimum number of guests, in case someone selects to have children in one room, but then not in another
    ui->numGuests->setMinimum(1);

    // this room allows for maximum number of 3 guests
    ui->numGuests->setMaximum(3);
    ui->maxGuestsLabel->setText("(Maximum of 3 Guests)");

    // right now, allowed to have 0 children
    ui->numChildren->setMinimum(0);
    // default each selection to no children
    ui->childrenNo->setChecked(true);

    ui->roomStyle->setText("Standard 1-King: $290 / night");
}

// when Atrium King Room is selected
void CanalReservation::on_atriumKing_clicked()
{
    // roomType = const int type in h file, which is the price (ROOM_4 = 350)
    roomType = ROOM_4;
    ui->roomImageLabel->setPixmap(room4);

    // reset the minimum number of guests, in case someone selects to have children in one room, but then not in another
    ui->numGuests->setMinimum(1);

    // this room allows for maximum number of 3 guests
    ui->numGuests->setMaximum(3);
    ui->maxGuestsLabel->setText("(Maximum of 3 Guests)");

    // right now, allowed to have 0 children
    ui->numChildren->setMinimum(0);
    // default each selection to no children
    ui->childrenNo->setChecked(true);

    ui->roomStyle->setText("Atrium 1-King: $350 / night");
}

// CARD RADIO BUTTONS

// when American Express is selected
void CanalReservation::on_americanExpressButton_clicked()
{
    // max length of card set to 15
    ui->cardNumber->setMaxLength(15);
    // clear the current contents when switching cards
    ui->cardNumber->clear();
    // follows this mask, starts with 3
    ui->cardNumber->setInputMask("3999-999999-99999;_");
    cardType = "American Express";
}

// when VISA is selected
void CanalReservation::on_visaButton_clicked()
{
    // max length of card is set to 16
    ui->cardNumber->setMaxLength(16);
    // clear the current contents when switching cards
    ui->cardNumber->clear();
    // follows this mask, starts with 4
    ui->cardNumber->setInputMask("4999-9999-9999-9999;_");
    cardType = "VISA";
}

void CanalReservation::on_masterCardButton_clicked()
{
    // max length of card is set to 16
    ui->cardNumber->setMaxLength(16);
    // clear the current contents when switching cards
    ui->cardNumber->clear();
    // follows this mask, starts with 5
    ui->cardNumber->setInputMask("5999-9999-9999-9999;_");
    cardType = "Mastercard";
}

void CanalReservation::on_discoverButton_clicked()
{
    // max length of card is set to 16
    ui->cardNumber->setMaxLength(16);
    // clear the current contents when switching cards
    ui->cardNumber->clear();
    // follows this mask, starts with 6
    ui->cardNumber->setInputMask("6999-9999-9999-9999;_");
    cardType = "Discover";
}

/*
\\ ** END OF RADIO BUTTONS IN GROUP BOXES ** //
*/

/*
\\ ** CHECK BOXES ** //
*/

// CHILD CHECK BOXES

// when child is checked to yes
void CanalReservation::on_childrenYes_toggled(const bool checked)
{
    if (checked)
    {
        // set inital value of children to 1
        if (ui->numGuests->value() == 1)
        {
            // we must move number of guests to 2 if we are at 1 to account for at least 1 adult for the room
            ui->numGuests->setValue(ui->numGuests->value() + 1);
        }
        // show min number of adults
        ui->minChildrenLabel->setText("(Minimum of 1 Adult)");
        // account for min number of total guests, for one adult
        ui->numGuests->setMinimum(2);
        // set number of children to 1, which was originally 0
        ui->numChildren->setValue(1);
        // show children labels
        ui->numChildrenLabel->show();
        ui->numChildren->show();
        // set other check box to false, so that both boxes can't be checked.
        ui->childrenNo->setChecked(false);
    }
    // yes option to children is not checked, or if no is checked, this happens
    else
    {
        // disappear text to show min adults
        ui->minChildrenLabel->setText("");
        // set min guests to 1
        ui->numGuests->setMinimum(1);
        // hide the children label and spinbox
        ui->numChildrenLabel->hide();
        ui->numChildren->hide();
        // set children value to 0
        ui->numChildren->setValue(0);
    }
}
// when child is checked to no
void CanalReservation::on_childrenNo_toggled(const bool checked)
{
    if(checked)
    {
        // set number of children to 0 here as well (in case of uncheck instead of check opposite)
        ui->numChildren->setValue(0);
        // set other checkbox to be unchecked
        ui->childrenYes->setChecked(false);
    }
}

// PARKING CHECK BOXES

// when check box for parking is checked for yes
void CanalReservation::on_parkingYes_toggled(const bool checked)
{
    if (checked)
    {
        // set this bool to true
        parkingNeeded = true;
        // make this text appear on second page
        ui->overNightParkingLabel->setText("Yes ($12.75 per night).");
        // set other checkbox for uncheck to prevent both boxes being checked
        ui->parkingNo->setChecked(false);
    }
}
// when check box for parking is checked for no
void CanalReservation::on_parkingNo_toggled(const bool checked)
{
    if (checked)
    {
        // set this bool to false
        parkingNeeded = false;
        // make this text appear on second page
        ui->overNightParkingLabel->setText("No.");
        // set other checkbox for uncheck to prevent both boxes being checked
        ui->parkingYes->setChecked(false);
    }
}

/*
\\ ** END OF CHECK BOXES ** //
*/


/*
// ** SPIN BOX INT UPDATE ** \\
*/

// when number of guests changes, we need to actively update the max for number of children
void CanalReservation::on_numGuests_valueChanged(const int arg1)
{
    ui->numChildren->setMaximum(arg1 - 1);
}

// when number of nights change, we actively update the value for number of nights (referenced in many methods)
// I only updated this one this much because the number of nights is dependent on many different calculations, so I wanted
// to use a uniform number, as opposed to writing out ui->getValue() etc.
void CanalReservation::on_numNights_valueChanged(const int arg1)
{
    numNights = arg1;
}

/*
\\ ** END OF SPIN BOX INT UPDATE ** //
*/


/*
// ** CALCULATIONS ** \\
*/

// calculates cost of room without tax
double CanalReservation::calculateCostRoom(const int roomType, const int numNights)
{
    return (double)roomType * numNights;
}
// calculates cost of room with tax
double CanalReservation::calculateCostRoomWithTax(const int roomType, const int numNights)
{
    return (double)roomType * numNights * 1.15;
}
// calculates cost of resort fees per night
double CanalReservation::calculateCostResort(const int numNights)
{
    return (double) 15.00 * numNights;
}
// calculates cost of parking per night if parking is desired
double CanalReservation::calculateCostParking(const int numNights, const bool parkingNeeded){
    // if we want parking, then calculate parking per nights * nights
    if (parkingNeeded)
    {
        return (double) 12.75 * numNights;
    }
    else
    {
        // change the label to not portray total price with number of nights. Updated here
        ui->parkingFeeLabel->setText("Parking Cost:");
        return 0;
    }
}
// calculates total cost of everything
double CanalReservation::calculateCostTotal(const int roomType, const int numNights, const bool parkingNeeded)
{
    return calculateCostRoomWithTax(roomType, numNights) + calculateCostResort(numNights) + calculateCostParking(numNights, parkingNeeded);
}

/*
// ** END OF CALCULATIONS ** \\
*/
