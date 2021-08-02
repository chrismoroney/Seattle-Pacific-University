#ifndef FIRSTWIDGETAPP_H
#define FIRSTWIDGETAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class firstWidgetApp; }
QT_END_NAMESPACE

class firstWidgetApp : public QMainWindow
{
    Q_OBJECT

public:
    firstWidgetApp(QWidget *parent = nullptr);
    ~firstWidgetApp();

private slots:
    void on_updateButton_clicked();

    void on_backgroundBlueButton_clicked();

    void on_backgroundRedButton_clicked();

    void on_foregroundBlueButton_clicked();

    void on_foregroundRedButton_clicked();

    void on_foregroundYellowButton_clicked();

    void on_foregroundGreenButton_clicked();

    void on_backgroundYellowButton_clicked();

    void on_backgroundGreenButton_clicked();

    void on_leftButton_clicked();

    void on_centerButton_clicked();

    void on_rightButton_clicked();

    void on_endButton_clicked();

    void on_resetButton_clicked();

private:
    Ui::firstWidgetApp *ui;
};
#endif // FIRSTWIDGETAPP_H
