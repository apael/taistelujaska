#include "hahmo.h"
#include "math.h"

hahmo::hahmo()
{
    hitrate = 10;
    dodge = 2;

    str = 2;
    mana = 10;
    MaxHp = 40;
    hp = 40;
    inviskesto = 0;
    super_pot = 0;
    mp_pot = 0;
    hp_pot = 0;
    mana = 0;
    MaxMana = 10;
    intelligence =2;
    critDmg = 1;

    forzen = 0;
    poison = 0;
    stunned = 0;
    burn = 0;
    p4life = 0;

    warrSkills = QVector<int>() << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    rogueSkills = QVector<int>() << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;
    mageSkills = QVector<int>() << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0 << 0;

    hpbonus=0;
    strbonus=0;
    hitbonus=0;
    VihuLevel=0;
    soturi_lvl=0;
    dexterity=2;
    perception=5;

    critRate=5;

    unusedSP = 0;






}


int hahmo::getHp(){
return hp;
}


int hahmo::getStr(){
return str;
}


int hahmo::getMana(){
return mana;
}


int hahmo::getDodge(){
return dodge;
}


int hahmo::getHitrate(){
    return hitrate;
}

int hahmo::getInvis()
{
    return invis;
}

int hahmo::getInvisKesto()
{
    return inviskesto;
}

int hahmo::getVihuLevel()
{
    return VihuLevel;
}

int hahmo::getVihuRound()
{
    return VihuRound;
}

QVector<int> hahmo::getRogueSkills()
{
    return rogueSkills;
}

QVector<int> hahmo::getMageSkills()
{
    return mageSkills;
}

QVector<int> hahmo::getWarrSkills()
{
    return warrSkills;
}

int hahmo::getIntelligence()
{
    return intelligence;
}

int hahmo::getDexterity()
{
    return dexterity;
}

int hahmo::getPerception()
{
 return perception;
}

int hahmo::getCritRate()
{
    return critRate;
}

double hahmo::getCritDmg()
{
    return critDmg;
}

void hahmo::setIntelligence(int x)
{
    intelligence = x;
}

void hahmo::setDexterity(int x)
{

    dexterity = x;

}

void hahmo::setPerception(int x)
{
    perception = x;
}

void hahmo::setCritRate(int x)
{
    critRate = x;
}

void hahmo::setCritDmg(double x)
{
    critDmg = x;
}

void hahmo::set_hp_pot(int x)
{
    hp_pot = x;
}

void hahmo::set_mp_pot(int x)
{
    mp_pot = x;
}

int hahmo::getMaxMana()
{
    return MaxMana;
}

void hahmo::setMaxMana(int x)
{
    MaxMana = x;
}

item hahmo::getAse()
{
    return ase;
}

item hahmo::getArmor()
{
    return panssari;
}

int hahmo::get_hp_pot()
{
    return hp_pot;
}

int hahmo::get_mp_pot()
{
    return mp_pot;
}

int hahmo::get_super_pot()
{
    return super_pot;
}

int hahmo::get_total_str()
{
    return str+ase.getStr()+panssari.getStr()+(warrSkills.at(9)*2);
}

int hahmo::get_total_dex()
{
        return dexterity+ase.getdex()+panssari.getdex();

}

int hahmo::get_total_int()
{
        return intelligence+ase.getint()+panssari.getint();
}

int hahmo::get_total_perc()
{
        return perception+ase.getperc()+panssari.getperc();
}

int hahmo::get_total_hp()
{
        return MaxHp+ase.getHp()+panssari.getHp();
}

int hahmo::get_total_mp()
{
        return MaxMana+ase.getmana()+panssari.getmana();
}

int hahmo::get_total_dodge()
{
        return dodge+ase.getDodge()+panssari.getDodge();
}

int hahmo::get_total_critrate()
{
        return critRate+ase.getcritrate()+panssari.getcritrate();
}

double hahmo::get_total_critdmg()
{
        return critDmg+ase.getcritdmg()+panssari.getcritdmg();
}

int hahmo::get_total_hitrate()
{
    return hitrate+ase.getHitrate()+panssari.getHitrate()+(warrSkills.at(0)*3);
}

int hahmo::getArmor_buff()
{
    return armor_buff    ;
}

void hahmo::setArmor_buff(int x)
{
    armor_buff = x;
}

int hahmo::getp4life()
{
    return p4life;
}

void hahmo::setp4life(int x)
{
    p4life = x;
}

void hahmo::set_poison(int x)
{
    poison = x;
}

void hahmo::set_forzen(int x)
{
    forzen = x;
}

void hahmo::set_stunned(int x)
{
    stunned = x;
}

void hahmo::set_burn(int x)
{
    burn = x;
}

int hahmo::get_poison()
{
    return poison;
}

int hahmo::get_forzen()
{
    return forzen;
}

int hahmo::get_stunned()
{
    return stunned;
}

int hahmo::get_burn()
{
    return burn;
}

void hahmo::sethitbonus(int x)
{
    hitbonus = x;
}

int hahmo::gethitbonus()
{
    return hitbonus;
}

void hahmo::setstrbonus(int x)
{
    strbonus = x;
}

int hahmo::getstrbonus()
{
    return strbonus;
}

void hahmo::sethpbonus(int x)
{
    hpbonus = x;
}

int hahmo::gethpbonus()
{
    return hpbonus;
}

void hahmo::setUnusedSP(int x)
{
    unusedSP = x;
}

int hahmo::getUnusedSP()
{
   return unusedSP;
}

void hahmo::setDodge(int x)
{
    dodge = x;
}

void hahmo::setMana(int x)
{
    if (x > MaxMana){
    mana = MaxMana ;
    }
    else {mana = x;}

}


void hahmo::setInvis(int x)
{
    invis = x;
}

void hahmo::setInvisKesto(int x)
{
    inviskesto = x;
}

void hahmo::setVihuLevel(int x)
{
    VihuLevel = x;
}

void hahmo::setVihuRound(int x)
{
    VihuRound = x;
}

void hahmo::set_super_pot(int x)
{
    super_pot = x;
}

void hahmo::inc_exp(int x)
{
    experience = experience+x;
}

void hahmo::set_exp(int x)
{
    experience = x;
}

int hahmo::get_exp()
{
    return experience;
}

int hahmo::get_sot_lvl()
{
    return soturi_lvl;
}

void hahmo::set_sot_lvl(int x)
{
    soturi_lvl = x;
}

int hahmo::next_lvl()
{
  // xp_needed = (5 * pow(2,(soturi_lvl)));
   xp_needed= ((soturi_lvl+1)*600);
   return xp_needed;
}

void hahmo::setWarrSkills(QVector<int> newSkills)
{
    warrSkills = newSkills;
}

void hahmo::setMageSkills(QVector<int> newSkills)
{
    mageSkills = newSkills;
}

void hahmo::setRogueSkills(QVector<int> newSkills)
{
    rogueSkills = newSkills;
}



void hahmo::setAse(item uusiase)
{

    str = str-ase.getStr();
    dexterity = dexterity-ase.getdex();
    intelligence = intelligence-ase.getint();
    perception = perception-ase.getperc();

    MaxHp = MaxHp-ase.getHp();
    MaxMana = MaxMana-ase.getmana();

    hitrate = hitrate-ase.getHitrate();
    critRate = str-ase.getcritrate();
    critDmg = str-ase.getcritdmg();
    dodge = str-ase.getDodge();







         ase = uusiase;

         str = str+ase.getStr();
         dexterity = dexterity+ase.getdex();
         intelligence = intelligence+ase.getint();
         perception = perception+ase.getperc();

         MaxHp = MaxHp+ase.getHp();
         MaxMana = MaxMana+ase.getmana();

         hitrate = hitrate+ase.getHitrate();
         critRate = str+ase.getcritrate();
         critDmg = str+ase.getcritdmg();
         dodge = str+ase.getDodge();


}

hahmo::~hahmo()
{

}

void hahmo::setArmor(item uusiarmor)
{

    str = str-panssari.getStr();
    dexterity = dexterity-panssari.getdex();
    intelligence = intelligence-panssari.getint();
    perception = perception-panssari.getperc();

    MaxHp = MaxHp-panssari.getHp();
    MaxMana = MaxMana-panssari.getmana();

    hitrate = hitrate-panssari.getHitrate();
    critRate = str-panssari.getcritrate();
    critDmg = str-panssari.getcritdmg();
    dodge = str-panssari.getDodge();







         panssari = uusiarmor;

         str = str+panssari.getStr();
         dexterity = dexterity+panssari.getdex();
         intelligence = intelligence+panssari.getint();
         perception = perception+panssari.getperc();

         MaxHp = MaxHp+panssari.getHp();
         MaxMana = MaxMana+panssari.getmana();

         hitrate = hitrate+panssari.getHitrate();
         critRate = str+panssari.getcritrate();
         critDmg = str+panssari.getcritdmg();
         dodge = str+panssari.getDodge();




}

void hahmo::setHp(int x)
{
    if (x > MaxHp){
    hp = MaxHp ;
    }
    else {hp = x;}

}

void hahmo::setHitrate(int x)
{
    hitrate = x;
}

void hahmo::setMaxHp(int x)
{
    MaxHp = x;
}


void hahmo::setStr(int x)
{
    str = x ;
}






int hahmo::getMaxHp()
{
    return MaxHp;
}
