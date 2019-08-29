

#include "levelup.h"
#include "ui_levelup.h"

#include"areena.h"
#include "hahmo.h"
#include"funktiot.h"
#include <QString>
#include "item.h"
#include<mainwindow.cpp>
#include "math.h"
#include<QPixmap>
#include<QResource>


int statpoints = 15;




void levelup::printtaastatit(){


        soturi->setMaxMana(soturi->getIntelligence()*2);

        soturi->setDodge(soturi->getDexterity());
        soturi->setCritDmg((soturi->getDexterity()*0.05)+1);

        soturi->setHitrate(soturi->getPerception()*2+(soturi->gethitbonus()*3));
        soturi->setCritRate(-4 + 8* log2(soturi->getPerception()));

    ui->heroStats2->setText("hp: " + QString::number(soturi->getHp()) +"\n"+
                           "str: " + QString::number(soturi->getStr()) +"\n"+

                            "dex: " + QString::number(soturi->getDexterity()) +"\n"+
                            "int: " + QString::number(soturi->getIntelligence()) +"\n"+
                            "perc: " + QString::number(soturi->getPerception())+"\n""\n"+


                           "dod: " + QString::number(soturi->getDodge()) +"\n"+
                          "mana: " + QString::number(soturi->getMana()) +"\n"+
                           "hit: " + QString::number(soturi->getHitrate())+"\n""\n"+

                            "cDmg: " + QString::number(soturi->getCritDmg()) +"\n"+
                           "crit %: " + QString::number(soturi->getCritRate()) +"\n"+


                            "SP: " + QString::number(statpoints)
                           );
}


levelup::levelup(hahmo *taistelija,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::levelup)
{

    ui->setupUi(this);
    soturi = taistelija;
    soturi->setMaxHp(soturi->getMaxHp()+10);

     statpoints = 5;
  //  soturi->setHp(soturi->getMaxHp);
    soturi->setHp(soturi->getMaxHp());

     current_hp = soturi->getHp();
     current_Str = soturi->getStr();
     current_Dex = soturi->getDexterity();
     current_Int = soturi->getIntelligence();
     current_Perc = soturi->getPerception();

printtaastatit();





}



levelup::~levelup()
{
    delete ui;
}

//lisää statteja
void levelup::on_pushButton_clicked()
{
    if (statpoints > 0){
soturi->setMaxHp(soturi->getMaxHp()+5);
    soturi->setHp(soturi->getMaxHp());
   statpoints--;
  // int inchp++;
    printtaastatit();
    }

}


void levelup::on_pushButton_2_clicked()
{
    if (statpoints > 0){
soturi->setStr(soturi->getStr()+1);
   statpoints--;
    printtaastatit();

    }

}




void levelup::on_pushButton_3_clicked()
{
    if (statpoints > 0){
soturi->setDexterity(soturi->getDexterity()+1);
   statpoints--;
    printtaastatit();

    }

}

void levelup::on_pushButton_4_clicked()
{
    if (statpoints > 0){
soturi->setIntelligence(soturi->getIntelligence()+1);

soturi->setMaxMana(soturi->getIntelligence()*2);
soturi->setMana(soturi->getMaxMana());

   statpoints--;
    printtaastatit();

    }

}

void levelup::on_pushButton_7_clicked()
{
    if (statpoints > 0){
soturi->setPerception(soturi->getPerception()+1);
   statpoints--;
     printtaastatit();

    }

}


//vähennä statteja

void levelup::on_pushButton_14_clicked()
{
    if (statpoints < 5 && current_hp < soturi->getMaxHp() ){
soturi->setMaxHp(soturi->getMaxHp()-5);
    soturi->setHp(soturi->getMaxHp());
   statpoints++;
    printtaastatit();

    }

}


void levelup::on_pushButton_13_clicked()
{
    if (statpoints < 5 && current_Str < soturi->getStr()){
soturi->setStr(soturi->getStr()-1);
   statpoints++;
    printtaastatit();

    }

}


void levelup::on_pushButton_9_clicked()
{
    if (statpoints < 5 && current_Dex < soturi->getDexterity()){
soturi->setDexterity(soturi->getDexterity()-1);
   statpoints++;
    printtaastatit();

    }

}

void levelup::on_pushButton_16_clicked()
{
    if (statpoints < 5 && current_Int < soturi->getIntelligence()){
soturi->setIntelligence(soturi->getIntelligence()-1);


soturi->setMaxMana(soturi->getIntelligence()*2);
soturi->setMana(soturi->getMaxMana());

    statpoints++;
    printtaastatit();

    }

}
void levelup::on_pushButton_15_clicked()
{
    if (statpoints < 5 && current_Perc < soturi->getPerception()){
soturi->setPerception(soturi->getPerception()-1);
   statpoints++;
    printtaastatit();

    }

}

void levelup::on_pushButton_17_clicked()
{
   // if (statpoints == 0){
        skillTree_ = new skilltree(soturi);
        skillTree_->show();

        emit valueChanged();
        levelup::close();
   // }

  //  else{
  //        ui->heroStats2->setText("sinulla on käyttämättömiä SPeitä");
  //  }
}






