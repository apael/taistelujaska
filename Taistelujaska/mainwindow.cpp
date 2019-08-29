#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "areena.h"
#include "hahmo.h"
#include "funktiot.h"
#include <QString>
#include "item.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Taso_2_btn->hide();
    ui->inventory_btn->hide();
    ui->replay_btn->hide();

    soturi = new hahmo;
    vihu = new hahmo;

    soturi->setMaxHp(100);
    soturi->setHp(100);
    soturi->setArmor_buff(0);
    soturi->setStr(5);
    soturi->set_sot_lvl(0);
    soturi->set_exp(0);





    soturi->setIntelligence(15);
        soturi->setMaxMana(soturi->getIntelligence()*2);

    soturi->setDexterity(15);
        soturi->setDodge(soturi->getDexterity());




    soturi->setPerception(15);
        soturi->setHitrate(soturi->getPerception()*2);
        soturi->setCritRate(soturi->getPerception()+5);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::openAreena()
{

    soturi = new hahmo;
    vihu = new hahmo;
    kirves = new item;
    haarniska = new item;

    soturi->setMaxHp(100);
    soturi->setHp(100);
    soturi->setArmor_buff(0);
    soturi->setStr(5);
    soturi->set_sot_lvl(0);
    soturi->set_exp(0);



    soturi->setArmor(*haarniska);
       soturi->setAse(*kirves);



    soturi->setIntelligence(15);
        soturi->setMaxMana(soturi->getIntelligence()*2);

    soturi->setDexterity(15);
        soturi->setDodge(soturi->getDexterity());
  //      soturi->setCritDmg((soturi->getDexterity()*0.05)+1);



    soturi->setPerception(15);
        soturi->setHitrate(soturi->getPerception()*2);
        soturi->setCritRate(soturi->getPerception()+5);
   // soturi->setStatpoints(0);

    vihu->setMaxHp(50);
    vihu->setHp(50);
    vihu->setStr(2);

    vihu->setVihuRound(0);
    vihu->setVihuLevel(0);

    vihu->setIntelligence(2);
        vihu->setMaxMana(vihu->getIntelligence()*2);
        vihu->setMana(vihu->getMaxMana());

    vihu->setDexterity(2);
        vihu->setDodge(vihu->getDexterity());

    vihu->setPerception(5);
        vihu->setHitrate(vihu->getPerception()*2);
        vihu->setCritRate(vihu->getPerception()+5);


    mAreena = new areena(soturi, vihu);

    mAreena->show();

}



void MainWindow::on_pushButton_2_clicked()
{
  close();
}


void MainWindow::show_menu( ){

    vihu->setVihuLevel(soturi->getVihuLevel());


    if (vihu->getVihuLevel()>0){
    ui->Aloita_btn->hide();
    ui->Taso_2_btn->show();
    ui->replay_btn->show();
    ui->inventory_btn->show();
}
     MainWindow::show();
int testi = vihu->getVihuLevel();


     if (testi == 1){
     ui->tekstiboksi->setText("Sankari voitti tason "+ QString::number(vihu->getVihuLevel()-1) + "\n""\n" "Pystytkö voittamaan seuraavan");
                        }
     if (testi >= 2){
    ui->tekstiboksi->setText("Sankari voitti tason "+ QString::number(vihu->getVihuLevel()-1) + "\n""\n" "Pystytkö voittamaan seuraavan");

                        }

    ui->Taso_2_btn->setText("Taso "+QString::number(vihu->getVihuLevel()));
    if (soturi->getHp()<=0){
    ui->tekstiboksi->setText("Sankarisi menehtyi hänen saavutuksistaan ei kirjoiteta kirjaa eikä häntä muisteta tulevaisuudessa :(");
    ui->Taso_2_btn->hide();
    ui->inventory_btn->hide();
    ui->replay_btn->hide();
    }
}



void MainWindow::on_Taso_2_btn_clicked()
{


    vihu->setMaxHp(vihu->getMaxHp()+15);
    vihu->setHp(vihu->getMaxHp());
    vihu->setStr(vihu->getStr()+2);



    vihu->setVihuRound(0);
    vihu->setIntelligence(vihu->getIntelligence()+1);
        vihu->setMaxMana(vihu->getIntelligence()*2);
         vihu->setMana(vihu->getMaxMana());

    vihu->setDexterity(vihu->getDexterity()+2);
        vihu->setDodge(vihu->getDexterity());




    vihu->setPerception(vihu->getPerception()+2);
        vihu->setHitrate(vihu->getPerception()*2);
        vihu->setCritRate(vihu->getPerception()+5);





    mAreena = new areena(soturi, vihu);

    mAreena->show();

    QObject::connect(mAreena, SIGNAL(returnmenu()),
                     this, SLOT(show_menu()));
}

void MainWindow::on_Aloita_btn_clicked()
{
      // vihu->setVihuLevel(0);

    MainWindow::close();
    openAreena();
    QObject::connect(mAreena, SIGNAL(returnmenu()),
                     this, SLOT(show_menu()));

    ui->Aloita_btn->hide();
    ui->Taso_2_btn->show();
    ui->replay_btn->show();
    ui->inventory_btn->show();


}

void MainWindow::on_inventory_btn_clicked()
{


    minventory = new newwindow(soturi);

    minventory->show();
    QObject::connect(minventory, SIGNAL(returnmenu()),
                     this, SLOT(show_menu()));
    MainWindow::hide();
    ui->Taso_2_btn->show();
   // ui->inventory_btn->hide();
}

void MainWindow::on_replay_btn_clicked()
{

    vihu->setMaxHp(vihu->getMaxHp());
    vihu->setHp(vihu->getMaxHp());
    vihu->setStr(vihu->getStr());



    vihu->setVihuRound(0);
    vihu->setVihuLevel(vihu->getVihuLevel()-1);
    vihu->setIntelligence(vihu->getIntelligence());
        vihu->setMaxMana(vihu->getIntelligence());
         vihu->setMana(vihu->getMaxMana());

    vihu->setDexterity(vihu->getDexterity());
        vihu->setDodge(vihu->getDexterity());




    vihu->setPerception(vihu->getPerception());
        vihu->setHitrate(vihu->getPerception());
        vihu->setCritRate(vihu->getPerception());





    mAreena = new areena(soturi, vihu);

    mAreena->show();

    QObject::connect(mAreena, SIGNAL(returnmenu()),
                     this, SLOT(show_menu()));
}

void MainWindow::on_save_load_btn_clicked()
{

    mSave = new save(soturi, vihu);

    mSave->show();

    QObject::connect(mSave, SIGNAL(returnmenu()),
                     this, SLOT(show_menu()));
}
