#include "save.h"
#include "ui_save.h"
#include <iostream>
#include <fstream>
#include"QString"
#include <QTextStream>
#include <QFile>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "QErrorMessage"
#include "funktiot.h"

using namespace std;

save::save(hahmo *taistelija, hahmo *enemy, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::save)
{
    ui->setupUi(this);
    soturi = taistelija;
    vihu = enemy;

    set_slot2();
    set_slot1();

}

save::~save()
{
    delete ui;
}

void save::load(int slot) {
    QFile file;
    if (slot == 1){
        file.setFileName("slot_1.txt");
    }else if(slot == 2){
        file.setFileName("slot_2.txt");
    }else{
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
 //   while (!in.atEnd()) {
        QString line = in.readLine();
        int luku =line.toInt();

        soturi->set_sot_lvl(luku);

        line = in.readLine();
         luku =line.toInt();
        soturi-> setMaxHp(luku);

        line = in.readLine();
         luku =line.toInt();
         soturi->setStr(luku);
         line = in.readLine();
          luku =line.toInt();
        soturi->setDexterity(luku);
        line = in.readLine();
         luku =line.toInt();
         soturi->setIntelligence(luku);
          line = in.readLine();
          luku =line.toInt();
         soturi->setPerception(luku);


         kirves = new item;
         haarniska = new item;

         line = in.readLine();
          luku =line.toInt();


               kirves->setStr(luku);
             line = in.readLine();
              luku =line.toInt();
               kirves->setdex(luku) ;
             line = in.readLine();
              luku =line.toInt();
               kirves->setint(luku);
             line = in.readLine();
              luku =line.toInt();
               kirves->setperc(luku);
             line = in.readLine();
              luku =line.toInt();
               kirves->setcritdmg(luku);
             line = in.readLine();
              luku =line.toInt();
               kirves->setcritrate(luku);
             line = in.readLine();
              luku =line.toInt();
               kirves->setDodge(luku);
             line = in.readLine();
              luku =line.toInt();
               kirves->setHitrate(luku);
             line = in.readLine();
              luku =line.toInt();
               kirves->setHp(luku);
             line = in.readLine();
              luku =line.toInt();
               kirves->setmana(luku);



             line = in.readLine();
              luku =line.toInt();


             haarniska->setStr(luku);
             line = in.readLine();
              luku =line.toInt();
              haarniska->setdex(luku);
             line = in.readLine();
              luku =line.toInt();
              haarniska->setint(luku);
             line = in.readLine();
              luku =line.toInt();
              haarniska->setperc(luku);
             line = in.readLine();
              luku =line.toInt();
              haarniska->setcritdmg(luku);
             line = in.readLine();
              luku =line.toInt();
              haarniska->setcritrate(luku);
             line = in.readLine();
              luku =line.toInt();
              haarniska->setDodge(luku);
             line = in.readLine();
              luku =line.toInt();
              haarniska->setHitrate(luku);
             line = in.readLine();
              luku =line.toInt();
              haarniska->setHp(luku);
             line = in.readLine();
              luku =line.toInt();
              haarniska->setmana(luku);






          line = in.readLine();
           luku =line.toInt();
          soturi->setVihuLevel(luku);

          line = in.readLine();
           luku =line.toInt();
          soturi->set_exp(luku);

          line = in.readLine();
           luku =line.toInt();
           kirves->set_type(luku);
          line = in.readLine();
           luku =line.toInt();
           haarniska->set_type(luku);
          line = in.readLine();
           luku =line.toInt();
           kirves->set_wep_type(luku);
           line = in.readLine();
           luku = line.toInt();
           soturi->setUnusedSP(luku);
  soturi->setArmor(*haarniska);
    soturi->setAse(*kirves);

          soturi->setMaxMana(soturi->getIntelligence()*2+soturi->getAse().getmana()+soturi->getArmor().getmana());

          soturi->setDodge(soturi->getDexterity()+soturi->getArmor().getDodge()+soturi->getAse().getDodge());
          soturi->setCritDmg((soturi->getDexterity()*0.05)+1+soturi->getAse().getcritdmg()+soturi->getArmor().getcritdmg());

          soturi->setHitrate(soturi->getPerception()*2+soturi->getAse().getHitrate()+soturi->getArmor().getHitrate());
          soturi->setCritRate(-4 + 8* log2(soturi->getPerception())+soturi->getAse().getcritrate()+soturi->getArmor().getcritrate());
          int stat;
          QVector<int> stats;

          for (int i = 0; i < 12; ++i){
            stat = in.read(1).toInt();
            stats.push_back(stat);
          }
          soturi->setWarrSkills(stats);
          stats.clear();
          for (int i = 0; i < 12; ++i){
            stat = in.read(1).toInt();
            stats.push_back(stat);
          }soturi->setMageSkills(stats);
          stats.clear();

          for (int i = 0; i < 12; ++i){
            stat = in.read(1).toInt();
            stats.push_back(stat);
          }soturi->setRogueSkills(stats);


close();
    emit returnmenu();
  //  }
}

void save::on_cancel_btn_clicked()
{
    close();
    emit returnmenu();
}

void save::on_slot_1_clicked()
{
    QFile file("slot_1.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
        QString line = in.readLine();
         int slot2 = line.toInt();
    if (slot2==0){
        writesave(1, soturi);
    }else if (slot2 !=0){
    load(1);
}
    set_slot2();
    set_slot1();

}




void save::on_slot_2_clicked()
{
    QFile file("slot_2.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
        QString line = in.readLine();
         int slot2 = line.toInt();
if (slot2 >0){
    load(2);
}
else{
    writesave(2,soturi);
}

set_slot2();
set_slot1();

}
void save::set_slot2(){

    bool testi = QFile::exists("slot_2.txt");
            if (testi == false){
                QFile data("slot_2.txt");
                if (data.open(QFile::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&data);


                    out << "0" ;
                    data.close();
                }
            }
    QFile file("slot_2.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
        QString line = in.readLine();
         int slot2 = line.toInt();

        if (slot2>0){
            ui->slot_2->setText("Hahmo tasolla\n" + QString::number(slot2));
        } else{

             ui->slot_2->setText("Empty Slot");

        }
}
void save::set_slot1(){

    bool testi = QFile::exists("slot_1.txt");
            if (testi == false){
                QFile data("slot_1.txt");
                if (data.open(QFile::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&data);


                    out << "0" ;
                    data.close();
                }
            }

    QFile file("slot_1.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
        QString line = in.readLine();
         int slot2 = line.toInt();

        if (slot2>0){
            ui->slot_1->setText("Hahmo tasolla\n" + QString::number(slot2));
        } else{

             ui->slot_1->setText("Empty Slot");

        }
}



void save::on_del_sav_clicked()
{
   QFile::remove("slot_1.txt");
   set_slot2();
   set_slot1();


}
