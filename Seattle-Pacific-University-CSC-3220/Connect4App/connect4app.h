#ifndef CONNECT4APP_H
#define CONNECT4APP_H

#include <QMainWindow>
#include <QLabel>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class connect4App; }
QT_END_NAMESPACE

class connect4App : public QMainWindow
{
    Q_OBJECT

public:
    connect4App(QWidget *parent = nullptr);
    ~connect4App();

private slots:
    void on_instructionsButton_clicked();

    void on_firstColButton_clicked();

    void on_secondColButton_clicked();

    void on_thirdColButton_clicked();

    void on_fourthColButton_clicked();

    void on_fifthColButton_clicked();

    void on_sixthButtonCol_clicked();

    void on_seventhColButton_clicked();

    void on_nextButton_clicked();

    void on_nextButton_2_clicked();

    void on_nextButton_3_clicked();

    void on_redButton_clicked();

    void on_greenButton_clicked();

    void on_cyanButton_clicked();

    void on_blueButton_clicked();

    void on_magentaButton_clicked();

    void on_yellowButton_clicked();

    void on_whiteButton_clicked();

    void on_blackButton_clicked();

    void on_goldButton_clicked();

    void on_maroonButton_clicked();

    void on_darkGreenButton_clicked();

    void on_darkMagButton_clicked();

    void on_blackButton_2_clicked();

    void on_redButton_2_clicked();

    void on_greenButton_2_clicked();

    void on_cyanButton_2_clicked();

    void on_blueButton_2_clicked();

    void on_magentaButton_2_clicked();

    void on_yellowButton_2_clicked();

    void on_whiteButton_2_clicked();

    void on_goldButton_2_clicked();

    void on_maroonButton_2_clicked();

    void on_darkGreenButton_2_clicked();

    void on_darkMagButton_2_clicked();

    void on_name1Button_clicked();

    void on_name2Button_clicked();

    void on_spuMaroonTheme_clicked();

    void on_spuWhiteTheme_clicked();

    void on_arcticTheme_clicked();

    void on_stPatricksTheme_clicked();

    void on_valentinesDayTheme_clicked();

    void on_halloweenTheme_clicked();

    void on_nextButtontoChars_clicked();

    void on_goToThemesButton_clicked();


    void on_actionClose_Application_3_triggered();

private:
    Ui::connect4App *ui;

    QColor red;
    QColor green;
    QColor cyan;
    QColor blue;
    QColor magenta;
    QColor yellow;
    QColor white;
    QColor black;
    QColor gold;
    QColor maroon;
    QColor darkGreen;
    QColor darkMagenta;

    QColor selectedColor1;
    QColor selectedColor2;
    QColor selectedTextColor1;
    QColor selectedTextColor2;
    QColor textColor;

    QString name1;
    QString name2;


    int numClicks = -1;
    int changeNumThemes = 0;


    QList<QList<QLabel*>*> spaces;
    QList<int> lastRows;

    void play(int columnNumber);

    bool check(int firstColumn, int firstRow, int horizontalMove, int verticalMove);

    QString getColor(int column, int row);


};
#endif // CONNECT4APP_H
