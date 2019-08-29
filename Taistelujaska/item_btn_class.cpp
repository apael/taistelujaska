#include "item_btn_class.h"
#include"newwindow.h"
#include"funktiot.h"
#include"item.h"
#include"hahmo.h"


item_btn_class::item_btn_class(QWidget *parent)
    : QPushButton(parent)
   {
    setMouseTracking(true);

    ase1= NULL;
    soturi = NULL;


}

void item_btn_class::enterEvent(QEvent *event)
{
this->QPushButton::enterEvent(event);
//ui->setText(printtaa());

    if (hyokkays_nappi==1){
        ui->setText("tämä on hyökkäys 1");
    }
    if (hyokkays_nappi==2){
        ui->setText("tämä on hyökkäys 2");
    }
    if (hyokkays_nappi==3){
        ui->setText("tämä on hyökkäys 3");
    }
    if (hyokkays_nappi==4){
        ui->setText("tämä on hyökkäys 4");
    }
    if (hyokkays_nappi==5){
        ui->setText("tämä on hyökkäys 5");
    }
    if (hyokkays_nappi==6){
        ui->setText("tämä on hyökkäys 6");
    }
    if (hyokkays_nappi==7){
        ui->setText("tämä on hyökkäys 7");
    }



    if (ase1 != NULL){
   if (ase1->get_type() == 1){


 ui->setText(printtaa2_arm(*ase1, soturi));
    }if (ase1->get_type() == 2){

ui->setText(printtaa2(*ase1, soturi));
       }
if (ase1->get_type() == 3){
    ui->setText("potion");
}

if ((printtaa2(*ase1, soturi) == soturi->getAse().get_rarity() )){
    ui->setText(printtaa(soturi));
}

if ((printtaa2_arm(*ase1, soturi) == soturi->getArmor().get_rarity() )){
        ui->setText(printtaa_arm(soturi));


}
    }
//setIcon(QIcon(":/kuvat/panssari.png"));
}

void item_btn_class::leaveEvent(QEvent *event)
{
this->QPushButton::leaveEvent(event);
//setIcon(QIcon(":/kuvat/panssari2.png"));
    ui->setText("");
}

void item_btn_class::sethahmo(hahmo *uusisoturi, item *uusiase,QLabel *uusiui ){

    soturi = uusisoturi;
    ui = uusiui;
             ase1 =uusiase;


}

void item_btn_class::setskill(QLabel *uusiui,int numero){


    ui = uusiui;
    hyokkays_nappi = numero;

}
