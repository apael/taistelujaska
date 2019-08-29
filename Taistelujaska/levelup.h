#pragma once

#ifndef LEVELUP_H
#define LEVELUP_H

#include <QWidget>
#include "hahmo.h"
#include <QString>
#include <QMainWindow>

//#include""
#include "skilltree.h"





namespace Ui {
class levelup;
}

class levelup : public QWidget
{
    Q_OBJECT

public:
    explicit levelup(hahmo *taistelija,QWidget *parent = 0);


    ~levelup();


public slots:
   //     void openareenalvlup();
      //  QString printtaa();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void printtaastatit();

    void on_pushButton_17_clicked();


signals:
    void valueChanged();

protected:

private:
    Ui::levelup *ui;
    // int statpoints;
    QString tapahtuma;
    //inventory *mAreena2;

    hahmo *soturi;

    skilltree *skillTree_;

    int current_hp ;
    int current_Str ;
    int current_Dex;
    int current_Int ;
    int current_Perc ;




};

#endif // LEVELUP_H
