#include "item.h"
#include "funktiot.h"
item::item()
{
    str = 0;
    dodge = 0;
    hitrate = 0;
    hp = 0;
     armor = 0;
     tier =0;
     dice_amount = 0;
     dice_type =0;
     mana=0;
     critrate=0;
     critdmg=0;
     intelligence=0;
    dex=0;
    perc=0;



}

int item::getStr()
{
    return str;
}

int item::getDodge()
{
    return dodge;
}

int item::getHitrate()
{
    return hitrate;
}

void item::setHp(int x)
{
    hp = x;
}

void item::setDodge(int x)
{
    dodge = x;
}

void item::setHitrate(int x)
{
    hitrate = x;
}

void item::setStr(int x)
{
    str = x;
}

void item::setRarity(int x)
{
    tier = x;
}

void item::setint(int x)
{
    intelligence = x;
}

void item::setcritdmg(int x)
{
    critdmg = x;
}

void item::setcritrate(int x)
{
    critrate = x;
}

void item::setperc(int x)
{
    perc = x;
}

void item::setdex(int x)
{
    dex = x;
}

void item::setmana(int x)
{
    mana = x;
}



int item::getHp()
{
    return hp;
}

int item::getRarity()
{
    return tier;
}

int item::getdice_type()
{
    return dice_type;
}

int item::getdice_amount()
{
    return dice_amount;
}

int item::getint()
{
    return intelligence;
}

double item::getcritdmg()
{
    return critdmg;
}

int item::getcritrate()
{
    return critrate;
}

int item::getperc()
{
    return perc;
}

int item::getdex()
{
    return dex;
}

int item::getmana()
{
    return mana;
}

QString item::get_rarity()
{
    return item_rarity;
}

int item::get_type()
{
    return type;
}

int item::get_wep_type()
{
    return wep_type;
}

void item::set_type(int x)
{
    type= x;
}

void item::set_wep_type(int x)
{
    wep_type=x;
}


void item::rollaa_item(){

    type = dice3();

if (type == 2){

     wep_type = dice3();
    if (wep_type == 1){
        //kirves
    str = dice6()+dice6();
    }
    if (wep_type == 2){
        //dagger
        dex = dice6()+dice6();
    }
    if (wep_type==3){
     //staff
        intelligence = dice6()+dice6();
    }
    dice_type = 6;
}
if (type == 1){

    dice_type = 6;
}
if (type == 3){
    //what item

}


    int x = 0;


    int luku = dice100();

    if (luku <= 1){
        tier = 5;
        item_rarity = "Legendary";



    }
    else if (luku <= 10){
        tier = 4;
    item_rarity = "Epic";


    }
    else if (luku <= 20){
        tier = 3;

    item_rarity = "Rare";

    }
    else if (luku <= 50){
        tier = 2;

    item_rarity = "Uncommon";

    }
    else {
        tier = 1;
    item_rarity = "Common";


    }
    while ( tier > x){


    int luku_2 = dice20() % 10;

    if (luku_2 == 1 && str == 0){

     str = dice6();
     x++;

    }
    if (luku_2 == 2 && intelligence == 0){
        intelligence = dice6();
        x++;
    }
    if (luku_2 == 3 && dex == 0){
        x++;
        dex = dice6();
    }
    if (luku_2 == 4 && perc == 0){
         x++;
        perc = dice6();
    }
    if (luku_2 == 5 && mana == 0){
         x++;
        mana = 2*dice6();
    }
    if (luku_2 == 6 && hp == 0){
         x++;
        hp = 2*dice6();
    }
    if (luku_2 == 7 && critrate == 0){
         x++;
        critrate = dice6();
    }
    if (luku_2 == 8 && critdmg == 0){
         x++;
        critdmg = dice6()*0.05;
    }
    if (luku_2 == 9 && dodge == 0){
         x++;
        dodge = dice6();
    }
    if (luku_2 == 0 && hitrate == 0){
         x++;
        hitrate = dice6();
    }

    }

     dice_amount = tier;

}
