#ifndef ITEM_H
#define ITEM_H
#include <QPixmap>

class item
{
public:
    item();




    int getStr();

    int getDodge();
    int getHitrate();
    int getHp();
    int getKuva();
    int getRarity();
    int getdice_type();
    int getdice_amount();


    int getint ();
    double getcritdmg ();
    int getcritrate ();
    int getperc ();
    int getdex ();
    int getmana ();
    QString get_rarity();
    int get_type();
    int get_wep_type();

    void set_type(int x);
    void set_wep_type(int x);



    void setHp(int x);
    void setDodge(int x);
    void setHitrate(int x);
    void setStr(int x);
  //  void setKuva(QPixmap uusikuva);
    void setRarity(int x);

    void setint (int x);
    void setcritdmg (int x);
    void setcritrate (int x);
    void setperc (int x);
    void setdex (int x);
    void setmana (int x);



    void rollaa_item();


private:
    //QPixmap kuva;

    int str;
    int hp;
    int dodge;
    int hitrate;

    int armor;
    int tier;
    QString item_rarity;



    int dice_amount;
    int dice_type;


    int mana;
    int critrate;
    double critdmg;





    int intelligence;

   int dex;
   int perc;

   int manapotion;
   int healthpotion;



    int type; //0 item, 1 panssari, 2 ase
    int wep_type; //1 axe 2 dagger 3 staff
};

#endif // ITEM_H
