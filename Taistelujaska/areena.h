#pragma once

#ifndef AREENA_H
#define AREENA_H

#include "levelup.h"
#include <QWidget>
#include "hahmo.h"
#include <QString>
#include <QMainWindow>
#include "item.h"





namespace Ui {
class areena;
}

class areena : public QMainWindow
{
    Q_OBJECT

public:
    explicit areena(hahmo *taistelija,hahmo *enemy,QWidget *parent = 0);
    ~areena();
    void vihunVuoro();
    void paivita_stats();
    void statuscheck();
    void kuka_Vastassa();
    void vihu_kuollut();
    void remove_buffs();
    void mouseMoveEvent(QMouseEvent *);
public slots:
    void openlevelup();
    void hahmo_lvlup();
signals:
   void returnmenu();
private slots:
    void on_lyoButton_clicked();

    void on_resetButton_clicked();

    void on_taioButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_heal_btn_clicked();

    void on_Item_storage_clicked();


    void on_Spells_btn_clicked();

    void on_Hp_pot_clicked();

    void on_warr_findpot_btn_clicked();

    void on_warr_armup_btn_clicked();

    void on_warr_p4life_btn_clicked();

    void on_warr_trollstrike_btn_clicked();

    void on_warr_ultimate_btn_clicked();

    void on_Mp_pot_clicked();

    void on_super_pot_clicked();

    void warrskills_ll(int damage);

    void check_warrskills();

private:
    Ui::areena *ui;
    levelup *mlevelup;
    hahmo *soturi;
    hahmo *vihu;
    QString tapahtuma;
    QString vihuteksti_kuka;
    QString vihuteksti_won;
    QString Vihuteksti_lost;
    QString lopputeksti;
    QString teksti;
        QString vihuteksti;
            int uusihp;
                int puredmg;
    item *kirves;
    item *haarniska;
    int stunni;
    int ulti_cd;
    int warrskills_redu;


    int damage;
  //  areena *mAreena;

};

#endif // AREENA_H
