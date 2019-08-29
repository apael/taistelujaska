#ifndef HAHMO_H
#define HAHMO_H
#include <QString>
#include <QPixmap>
#include "item.h"


class hahmo
{
public:
    hahmo();

    int getHp();
    int getMaxHp();
    int getStr();
    int getDodge();
    int getMana();
    //QPixmap getKuva();
    int getHitrate();
    int getInvis();
    int getInvisKesto();
    int getVihuLevel();
    int getVihuRound();
    QVector<int> getRogueSkills();
    QVector<int> getMageSkills();
    QVector<int> getWarrSkills();

    int getIntelligence ();
    int getDexterity ();
    int getPerception ();
    int getCritRate ();
    double getCritDmg ();

    int getMaxMana();
    void setMaxMana(int x);

    void setDodge(int x);
    void setHp(int x);

    void setHitrate(int x);
    void setMaxHp(int x);
    void setStr(int x);
    void setMana(int x);
    void setInvis(int x);
    void setInvisKesto(int x);
    void setVihuLevel(int x);
    void setVihuRound(int x);
    void set_super_pot(int x);

    void inc_exp(int x);
    void set_exp(int x);
    int get_exp();
    int get_sot_lvl();
    void set_sot_lvl(int x);

    int next_lvl();
    void setWarrSkills(QVector<int> newSkills);
    void setMageSkills(QVector<int> newSkills);
    void setRogueSkills(QVector<int> newSkills);


    void setDexterity (int x);
    void setIntelligence (int x);
    void setPerception (int x);
    void setCritRate (int x);
    void setCritDmg (double x);
    void set_hp_pot(int x);
    void set_mp_pot(int x);

    void setArmor(item uusiarmor);

    void setAse(item uusiase);
    ~hahmo();
    item getAse();
    item getArmor();

    int get_hp_pot();
    int get_mp_pot();
    int get_super_pot();




    int get_total_str();
    int get_total_dex();
    int get_total_int();
    int get_total_perc();

    int get_total_hp();
    int get_total_mp();

    int get_total_dodge();
    int get_total_critrate();
    double get_total_critdmg();
    int get_total_hitrate();

    int getArmor_buff();
    void setArmor_buff(int x);


   int getp4life();
   void setp4life(int x);

   void set_poison(int x);
   void set_forzen(int x);
   void set_stunned(int x);
   void set_burn(int x);


   int get_poison();
   int get_forzen();
   int get_stunned();
   int get_burn();

   void sethitbonus(int x);
   int gethitbonus();

   void setstrbonus(int x);
   int getstrbonus();

   void sethpbonus(int x);
   int gethpbonus();

    void setUnusedSP(int x);
    int getUnusedSP();




private:
    QString nimi;
  //  QPixmap kuva;
    QVector<int> warrSkills;
    QVector<int> mageSkills;
    QVector<int> rogueSkills;


    int hitrate;
    int dodge;
    int hp;
    int str;
    int mana;
    int MaxHp;
    int statpoints;
    int MaxMana;
    int VihuLevel;
    int VihuRound;

    int experience;
    int soturi_lvl;

    int xp_needed;
    int hp_pot;
    int mp_pot;
    int super_pot;

    int armor_buff;
    int p4life;

    int hitbonus;
    int hpbonus;
    int strbonus;


    item panssari;
    item ase;
    item esineet;

    int poison;
    int burn;
    int forzen;
    int stunned;
    int invis;
    int inviskesto;
    int invisvoima;

    int perception;
    int intelligence;
    int dexterity;
    int critRate;
    double critDmg;

    int unusedSP;

};

#endif // HAHMO_H
