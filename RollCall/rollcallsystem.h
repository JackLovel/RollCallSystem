#ifndef ROLLCALLSYSTEM_H
#define ROLLCALLSYSTEM_H

#include <QMainWindow>
#include <QtWidgets>

class RollCallSystem : public QMainWindow
{
    Q_OBJECT

public:
    RollCallSystem(QWidget *parent = 0);
    ~RollCallSystem();
    //const QString dataFilePath = ":/names";
    int total = 5;

private slots:
    void startSlot();
    void stopSlot();
    void srand();

private:
    void readJson();
    void initUI();

    QTextEdit *displayEdit;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QWidget *widget;

    QTimer *timer;
    QStringList name_data;
};

#endif // ROLLCALLSYSTEM_H
