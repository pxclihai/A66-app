#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "programdb.h"
#include "step.h"
#include "moulds.h"
#include "manual.h"
#include "runstate.h"
#include "systemsetting.h"
#include "easybend.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initWindow();
public slots:

    void ReturnProgramdb();
    void ReFlashProgName();

private slots:

    void on_pushButton_T3_clicked();

    void on_pushButton_T2_clicked();



    void on_toolButton_B0_clicked();

    void on_toolButton_B1_clicked();

    void on_toolButton_B2_clicked();

    void on_toolButton_B3_clicked();

    void on_toolButton_B4_clicked();

    void on_toolButton_B5_clicked();

    void on_toolButton_Start_clicked();

signals:
    void openStepWidget();
    void openProgramWidget();
    void openMouldsWidget();
    void openManualWidget();
    void openRunStateWidget();
    void openSystemSettingWidget();
    void openEasyBendWidget();
    
private:
    void timerEvent(QTimerEvent *t); //定时器事件
    Ui::MainWindow *ui;
    int ProgramName_Scan;
};

#endif // MAINWINDOW_H
