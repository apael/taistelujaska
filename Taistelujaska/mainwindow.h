#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QObject>
#include <areena.h>
#include <QString>
#include"newwindow.h"
#include"save.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void openAreena();
    void show_menu();
signals:
        void returnmenu();

private slots:


    void on_pushButton_2_clicked();


    void on_Taso_2_btn_clicked();

    void on_Aloita_btn_clicked();

    void on_inventory_btn_clicked();

    void on_replay_btn_clicked();

    void on_save_load_btn_clicked();

private:
    Ui::MainWindow *ui;
   areena *mAreena;
    hahmo *soturi;
    hahmo *vihu;
    item *kirves;
    QString lopputeksti;
    newwindow *minventory;
    item *haarniska;
    save *mSave;
};

#endif // MAINWINDOW_H
