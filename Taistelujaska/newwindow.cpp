#include "newwindow.h"
#include "ui_newwindow.h"
#include<hahmo.h>
#include"item.h"
#include "levelup.h"
#include"math.h"
#include"funktiot.h"


newwindow::newwindow(hahmo *taistelija, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newwindow)
{
    ui->setupUi(this);

  //  openareenalvlup();
    soturi = taistelija;

    uusiase = new item ;
    uusiase->rollaa_item();

    uusiase2 = new item ;
    uusiase2->rollaa_item();

    newwep = new item;
    *newwep = soturi->getAse();

    newarm = new item;
    *newarm = soturi->getArmor();


    ui->item_btn_1->sethahmo(soturi, uusiase, ui->infobox_lbl);
    ui->item_btn_2->sethahmo(soturi, uusiase2, ui->infobox_lbl);

    ui->current_item_3->sethahmo(soturi, newwep , ui->infobox_lbl);
    ui->current_item_2->sethahmo(soturi, newarm , ui->infobox_lbl);

    ui->current_item_3->setIconSize(QSize(60,60));
    ui->current_item_3->setFixedSize(QSize(60,60));

    ui->current_item_2->setIconSize(QSize(60,60));
    ui->current_item_2->setFixedSize(QSize(60,60));

    ui->item_btn_1->setIconSize(QSize(51,51));
    ui->item_btn_1->setFixedSize(QSize(51,51));

    ui->item_btn_2->setIconSize(QSize(51,51));
    ui->item_btn_2->setFixedSize(QSize(51,51));

    printtaastatit();

    ui->xp_bar->setMaximum(soturi->next_lvl());
     ui->xp_bar->setValue(soturi->get_exp());
     ui->hero_lvl_lbl->setText("lvl " + QString::number(soturi->get_sot_lvl()));


    current_item_kuva();



            if (uusiase2->get_type() == 1){
                ui->item_btn_2->setIcon(QIcon(":/kuvat/panssari.png"));

            }if (uusiase2->get_type() == 2){
                if (uusiase2->get_wep_type()==1){
                 ui->item_btn_2->setIcon(QIcon(":/kuvat/miekka.png"));
            }if (uusiase2->get_wep_type()==2){
                    ui->item_btn_2->setIcon(QIcon(":/kuvat/dagger.png"));
               }if (uusiase2->get_wep_type()==3){
                    ui->item_btn_2->setIcon(QIcon(":/kuvat/staff.png"));
               }

                //ui->item_btn_2->setIcon(QIcon(":/kuvat/miekka.png"));


            }if (uusiase2->get_type() == 3){

                int pottu = rand() % 4;

                if (pottu <=2 && pottu > 0) {
                    soturi->set_hp_pot(soturi->get_hp_pot()+1);
                    ui->item_btn_2->setIcon(QIcon(":/kuvat/potion.png"));


                }
                if(pottu > 2){
                    soturi->set_mp_pot(soturi->get_mp_pot()+1);
                    ui->item_btn_2->setIcon(QIcon(":/kuvat/mp_pot.png"));


                }
                if (pottu == 0){
                    soturi->set_super_pot(soturi->get_super_pot()+1);

                ui->item_btn_2->setIcon(QIcon(":/kuvat/sup_pot.png"));


                }
            }

if (uusiase->get_type() == 1){
    ui->item_btn_1->setIcon(QIcon(":/kuvat/panssari.png"));
}if (uusiase->get_type() == 2){
    if (uusiase->get_wep_type()==1){
     ui->item_btn_1->setIcon(QIcon(":/kuvat/miekka.png"));
}if (uusiase->get_wep_type()==2){
        ui->item_btn_1->setIcon(QIcon(":/kuvat/dagger.png"));
   }if (uusiase->get_wep_type()==3){
        ui->item_btn_1->setIcon(QIcon(":/kuvat/staff.png"));
   }
}if (uusiase->get_type() == 3){

    int pottu = rand() % 4;

    if (pottu <=2 && pottu > 0) {
        soturi->set_hp_pot(soturi->get_hp_pot()+1);
        ui->item_btn_1->setIcon(QIcon(":/kuvat/potion.png"));

    }
    if(pottu > 2){
        soturi->set_mp_pot(soturi->get_mp_pot()+1);
        ui->item_btn_1->setIcon(QIcon(":/kuvat/mp_pot.png"));

    }
    if (pottu == 0){
        soturi->set_super_pot(soturi->get_super_pot()+1);

    ui->item_btn_1->setIcon(QIcon(":/kuvat/sup_pot.png"));
    }
}

}

newwindow::~newwindow()
{
    delete ui;
}







void newwindow::printtaastatit(){


        soturi->setMaxMana(soturi->getIntelligence()*2+soturi->getAse().getmana()+soturi->getArmor().getmana());

        soturi->setDodge(soturi->getDexterity()+soturi->getArmor().getDodge()+soturi->getAse().getDodge());
        soturi->setCritDmg((soturi->getDexterity()*0.05)+1+soturi->getAse().getcritdmg()+soturi->getArmor().getcritdmg());

        soturi->setHitrate(soturi->getPerception()*2+soturi->getAse().getHitrate()+soturi->getArmor().getHitrate());
        soturi->setCritRate(-4 + 8* log2(soturi->getPerception())+soturi->getAse().getcritrate()+soturi->getArmor().getcritrate());

    ui->heroStats2->setText("hp: " + QString::number(soturi->getHp()+soturi->getAse().getHp()+soturi->getArmor().getHp()) +"\n"+
                           "str: " + QString::number(soturi->getStr()) +"\n"+

                            "dex: " + QString::number(soturi->getDexterity()) +"\n"+
                            "int: " + QString::number(soturi->getIntelligence()) +"\n"+
                            "perc: " + QString::number(soturi->getPerception())+"\n""\n"+


                           "dod: " + QString::number(soturi->getDodge()) +"\n"+
                          "mana: " + QString::number(soturi->getMana()+soturi->getAse().getmana()+soturi->getArmor().getmana()) +"\n"+
                           "hit: " + QString::number(soturi->getHitrate())+"\n""\n"+

                            "cDmg: " + QString::number(soturi->getCritDmg()) +"\n"+
                           "crit %: " + QString::number(soturi->getCritRate()) +"\n"


                           );
}

void newwindow::on_return_btn_clicked()
{
    emit returnmenu();;
    close();
}

void newwindow::on_item_btn_2_clicked()
{
    if (uusiase2->get_type()==2){
    soturi->setAse(*uusiase2);
    ui->item_btn_2->hide();



    ui->current_item_3->setIcon(QIcon(":/kuvat/miekka.png"));

    printtaastatit();
    }
    if (uusiase2->get_type()==1){
    soturi->setArmor(*uusiase2);
    ui->item_btn_2->hide();


     ui->current_item_2->setIcon(QIcon(":/kuvat/panssari.png"));


    printtaastatit();
    }
    if (uusiase2->get_type() == 3 ){
    //rollaapotu(soturi);
    ui->item_btn_2->hide();
    printtaastatit();

    }
    *newwep = soturi->getAse();
    *newarm = soturi->getArmor();
ui->current_item_3->sethahmo(soturi, newwep , ui->infobox_lbl);
ui->current_item_2->sethahmo(soturi, newarm , ui->infobox_lbl);
current_item_kuva();
}

void newwindow::on_item_btn_1_clicked()
{

    if (uusiase->get_type() == 2 ){
    soturi->setAse(*uusiase);
    ui->item_btn_1->hide();

     ui->current_item_3->setIcon(QIcon(":/kuvat/miekka.png"));
    printtaastatit();
    }

    if (uusiase->get_type() == 1 ){
    soturi->setArmor(*uusiase);
    ui->item_btn_1->hide();


     ui->current_item_2->setIcon(QIcon(":/kuvat/panssari.png"));
    printtaastatit();

    }

    if (uusiase->get_type() == 3 ){
   // rollaapotu(soturi);
    ui->item_btn_1->hide();
    printtaastatit();

    }


    *newwep = soturi->getAse();
    *newarm = soturi->getArmor();
ui->current_item_3->sethahmo(soturi, newwep , ui->infobox_lbl);
ui->current_item_2->sethahmo(soturi, newarm , ui->infobox_lbl);

current_item_kuva();
}


void newwindow::current_item_kuva()
{

    if (soturi->getArmor().get_type()== 1){
        ui->current_item_2->setIcon(QIcon(":/kuvat/panssari.png"));
    }

    if (soturi->getAse().get_type()== 2){
        if (soturi->getAse().get_wep_type()==1){
         ui->current_item_3->setIcon(QIcon(":/kuvat/miekka.png"));
    }if (soturi->getAse().get_wep_type()==2){
            ui->current_item_3->setIcon(QIcon(":/kuvat/dagger.png"));
       }if (soturi->getAse().get_wep_type()==3){
            ui->current_item_3->setIcon(QIcon(":/kuvat/staff.png"));
       }


    }
}
