#ifndef funktiot
#define funktiot

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "item.h"
#include "funktiot.h"
#include "hahmo.h"
#include "QFile"
#include "QTextStream"
//#include <random>

int dice100(){
    int d100;



d100= rand() % 100+1;

return d100;
}


//d20 noppa
int dice20(int x){
    int d20 = 0;

    for(int y = 0;y < x;++y){
        d20= d20 + rand() % 20+1;
    }
return d20;
}


int dice6(int x){

    int d6 = 0;

    for(int y = 0;y < x;++y){
        d6= d6 + rand() % 6+1;
    }
return d6;
}

int dice3(){
    int d3;



d3= rand() % 3+1;

return d3;
}



int spell_kill_all( int str){
    int dmgroll;
    dmgroll = (dice20()+str);
            return dmgroll;
}

int spell_heal( int str){
   int dmgroll;
    dmgroll = (dice20()+str);
                return dmgroll;
}








int attack(hahmo *taistelija, hahmo *vihu){
    int aseen_noppaluku, i = 0;

   // aseen_noppaluku = taistelija->getAse().getStr();
   while (taistelija->getAse().getdice_amount() > i){
   // aseen_noppaluku = (rand () % taistelija->getAse().getdice_type()+1)+aseen_noppaluku;
       aseen_noppaluku = taistelija->getAse().getStr()+taistelija->getAse().getdice_type()+taistelija->getAse().getdice_amount();
            i++;
}
    if(taistelija->getHitrate()*dice20() > vihu->getDodge()*dice20())
{ //osuma
    int dmgroll;
    if (taistelija->getCritRate() <= dice100()){
        dmgroll = (taistelija->getStr()/2+dice20()+aseen_noppaluku)*taistelija->getCritDmg();
        return dmgroll;
    }


    dmgroll = taistelija->getStr()/2+dice20()+aseen_noppaluku;
    //dmgroll = aseen_noppaluku;

return dmgroll;

}else {
    //missed
    return 0;
}
}



int vihu1_att(int str){
    int dmgroll;
    int v4;
    v4= rand() % 5;

    if (v4>1){
        //perushyökkäys 3/5
    int dmgroll = dice20()/2;
        return str+dmgroll;
    }
    if (v4==0){
        //parempi hyökkäys 1/5
    dmgroll = dice20();
        return str+dmgroll;
    }

    if (v4==1){
        //tuuri hyökkäys 1/5
    dmgroll = (dice20()+dice20()+dice20())/2;
        return dmgroll;
    }
return 0;
}




int vihu_attack(int hitrate, int dodge, int str, int VihuLevel,int VihuRound){
    //vihun hitrate, sankarin dodge


if(hitrate*dice20() > dodge*dice20())
{ //osuma
    if (VihuLevel == 0){
        return vihu1_att(str);
    }
   if (VihuLevel >= 1){
       return vihu2_attack(str,VihuRound);
    }

   } else {
        return 0;
    //missed
}

return 0;
//vihua ei ole olemassa
}



int vihu2_attack(int str, int VihuRound){
    int dmgroll;
    int v4;

    v4= rand() % 4;

    if (VihuRound % 4 == 0){

        dmgroll = str*2;
            return dmgroll;
    }

    if (v4>1){
        //perushyökkäys 3/5
    int dmgroll = dice20()/2;
        return str+dmgroll;

    }
    if (v4==0){
        //parempi hyökkäys 1/5
    dmgroll = dice20();
        return str+dmgroll;
        ;
    }

    if (v4==1){
        //tuuri hyökkäys 1/5
    dmgroll = (dice20()+dice20()+dice20())/2+str;

    return dmgroll;
}


return 0;
}


QString printtaa_arm(hahmo *soturi){
       QString final_txt = "";
        if (soturi->getArmor().getHp() >0){
         final_txt = "hp: " + QString::number(soturi->getArmor().getHp()) +"\n";
        }
        if (soturi->getArmor().getStr() >0){
         final_txt = final_txt + "str: " + QString::number(soturi->getArmor().getStr())+"\n";
        }
         if (soturi->getArmor().getdex() >0){
          final_txt = final_txt + "dex: " + QString::number(soturi->getArmor().getdex()) +"\n";
         }
         if (soturi->getArmor().getperc() >0){
          final_txt = final_txt + "per: " + QString::number(soturi->getArmor().getperc()) +"\n";
         }
         if (soturi->getArmor().getint() >0){
          final_txt = final_txt + "int: " + QString::number(soturi->getArmor().getint())+"\n";
         }
         if (soturi->getArmor().getmana() >0){
          final_txt = final_txt + "mp: " + QString::number(soturi->getArmor().getmana())+"\n";
         }
         if (soturi->getArmor().getcritrate() >0){
          final_txt = final_txt + "cRate: " + QString::number(soturi->getArmor().getcritrate()) +"\n";
         }
         if (soturi->getArmor().getcritdmg() >0){
          final_txt = final_txt +  "cDmg: " + QString::number(soturi->getArmor().getcritdmg()) +"\n";
         }
         if (soturi->getArmor().getHitrate() >0){
          final_txt = final_txt +  "hit : " + QString::number(soturi->getArmor().getHitrate()) +"\n";
         }
         if (soturi->getArmor().getDodge() >0){
          final_txt = final_txt + "Dod: " + QString::number(soturi->getArmor().getDodge())+"\n";
         }
        final_txt = final_txt + QString(soturi->getArmor().get_rarity());


         return final_txt;


}
//palauttaa sen hetkisen equipatun aseen statit
QString printtaa(hahmo *soturi){
       QString final_txt = "";
        if (soturi->getAse().getHp() >0){
         final_txt = "hp: " + QString::number(soturi->getAse().getHp()) +"\n";
        }
        if (soturi->getAse().getStr() >0){
         final_txt = final_txt + "str: " + QString::number(soturi->getAse().getStr())+"\n";
        }
         if (soturi->getAse().getdex() >0){
          final_txt = final_txt + "dex: " + QString::number(soturi->getAse().getdex()) +"\n";
         }
         if (soturi->getAse().getperc() >0){
          final_txt = final_txt + "per: " + QString::number(soturi->getAse().getperc()) +"\n";
         }
         if (soturi->getAse().getint() >0){
          final_txt = final_txt + "int: " + QString::number(soturi->getAse().getint())+"\n";
         }
         if (soturi->getAse().getmana() >0){
          final_txt = final_txt + "mp: " + QString::number(soturi->getAse().getmana())+"\n";
         }
         if (soturi->getAse().getcritrate() >0){
          final_txt = final_txt + "cRate: " + QString::number(soturi->getAse().getcritrate()) +"\n";
         }
         if (soturi->getAse().getcritdmg() >0){
          final_txt = final_txt +  "cDmg: " + QString::number(soturi->getAse().getcritdmg()) +"\n";
         }
         if (soturi->getAse().getHitrate() >0){
          final_txt = final_txt +  "hit : " + QString::number(soturi->getAse().getHitrate()) +"\n";
         }
         if (soturi->getAse().getDodge() >0){
          final_txt = final_txt + "Dod: " + QString::number(soturi->getAse().getDodge())+"\n";
         }
        final_txt = final_txt + QString(soturi->getAse().get_rarity());


         return final_txt;
}

QString rollaapotu(hahmo *soturi){

int pottu = rand() % 4;
QString tapahtuma = "";
if (pottu <=2 && pottu > 0) {
    tapahtuma = "loysit hp potun";
    soturi->set_hp_pot(soturi->get_hp_pot()+1);
}
if(pottu > 2){
    tapahtuma = "loysit mana potun";
    soturi->set_mp_pot(soturi->get_mp_pot()+1);
}
if (pottu == 0){
    soturi->set_super_pot(soturi->get_super_pot()+1);
    tapahtuma = "loysit super potun";
}
return tapahtuma;
}


QString printtaa2_arm(item ase,hahmo *soturi){
       QString final_txt = "";
        if (ase.getHp() > soturi->getArmor().getHp()){
         final_txt  = "hp: + " + QString::number(ase.getHp()) +"\n";
        }if (ase.getHp() < soturi->getArmor().getHp()){
            final_txt = "hp - " + QString::number(soturi->getArmor().getHp()) +"\n";
           }
        if (ase.getStr() > soturi->getArmor().getStr()){
         final_txt = final_txt +"str: + " + QString::number(ase.getStr()) +"\n";
        }if (ase.getStr() < soturi->getArmor().getStr()){
            final_txt = final_txt +"str - " + QString::number(soturi->getArmor().getStr()) +"\n";
           }

        if (ase.getdex() > soturi->getArmor().getdex()){
         final_txt = final_txt +"dex: + " + QString::number(ase.getdex()) +"\n";
        }if (ase.getdex() < soturi->getArmor().getdex()){
            final_txt = final_txt +"dex - " + QString::number(soturi->getArmor().getdex()) +"\n";
           }

        if (ase.getperc() > soturi->getArmor().getperc()){
         final_txt = final_txt +"per: + " + QString::number(ase.getperc()) +"\n";
        }if (ase.getperc() < soturi->getArmor().getperc()){
            final_txt = final_txt +"per - " + QString::number(soturi->getArmor().getperc()) +"\n";
           }

        if (ase.getint() > soturi->getArmor().getint()){
         final_txt = final_txt +"int: + " + QString::number(ase.getint()) +"\n";
        }if (ase.getint() < soturi->getArmor().getint()){
            final_txt = final_txt +"int - " + QString::number(soturi->getArmor().getint()) +"\n";
           }

        if (ase.getmana() > soturi->getArmor().getmana()){
         final_txt = final_txt +"mp: + " + QString::number(ase.getmana()) +"\n";
        }if (ase.getmana() < soturi->getArmor().getmana()){
            final_txt = final_txt +"mp - " + QString::number(soturi->getArmor().getmana()) +"\n";
           }

        if (ase.getcritrate() > soturi->getArmor().getcritrate()){
         final_txt = final_txt +"cRate: + " + QString::number(ase.getcritrate()) +"\n";
        }if (ase.getcritrate() < soturi->getArmor().getcritrate()){
            final_txt = final_txt +"cRate - " + QString::number(soturi->getArmor().getcritrate()) +"\n";
           }

        if (ase.getcritdmg() > soturi->getArmor().getcritdmg()){
         final_txt = final_txt +"cDmg: + " + QString::number(ase.getcritdmg()) +"\n";
        }  if (ase.getcritdmg() < soturi->getArmor().getcritdmg()){
            final_txt = final_txt +"cDmg - " + QString::number(soturi->getArmor().getcritdmg()) +"\n";
           }

        if (ase.getHitrate() > soturi->getArmor().getHitrate()){
         final_txt = final_txt +"hit: + " + QString::number(ase.getHitrate()) +"\n";
        } if (ase.getHitrate() < soturi->getArmor().getHitrate()){
            final_txt = final_txt +"hit - " + QString::number(soturi->getArmor().getHitrate()) +"\n";
           }

        if (ase.getDodge() > soturi->getArmor().getDodge()){
            final_txt = final_txt +"dod: + " + QString::number(ase.getDodge()) +"\n";
           }if (ase.getDodge() < soturi->getArmor().getDodge()){
               final_txt = final_txt +"dod - " + QString::number(soturi->getArmor().getDodge()) +"\n";
              }



        final_txt = final_txt + QString(ase.get_rarity());


         return final_txt;


}


QString p4life_buff(hahmo *soturi){

    int heal = dice20(((soturi->get_sot_lvl()/2)+1));
    QString tapahtuma = "Siunauksen voimasta sankari parani"+ QString::number(heal);
            int uusihp = soturi->getHp() + heal;

    soturi->setHp(uusihp);

    return tapahtuma;
}

int warr_dmg_redu(hahmo *soturi){
    return dice6(soturi->getWarrSkills().at(7));
}

int warr_leach(){
    return dice6();
}


void warr_dispel_pass(hahmo *soturi){
int warr_dp = soturi->getWarrSkills().at(1);
    if (dice6() < warr_dp){
        soturi->set_poison(0);
         soturi->set_burn(0);
         soturi->set_forzen(0);
         soturi->set_stunned(0);
    }

}
void warr_burn_skill(hahmo *vihu, hahmo *soturi){

    if (dice100() <= 5 * soturi->getWarrSkills().at(2) && vihu->get_burn() == 0){
        vihu->set_burn(dice6());

    }
}

QString palamisfunktio(hahmo *vihu, hahmo *soturi){
    QString tapahtuma = "";
    if (vihu->get_burn() > 0){
        int burn_dmg = (vihu->getHp() / 10);
                vihu->setHp(vihu->getHp()-burn_dmg);
                vihu->set_burn(vihu->get_burn()-1);
                tapahtuma = "Vihu otti " + QString::number(burn_dmg)+ " palamisvahinkoa ";

    }
    if (soturi->get_burn() > 0){
        int burn_dmg = (soturi->getHp() / 10);
                soturi->setHp(soturi->getHp()-burn_dmg);
                soturi->set_burn(soturi->get_burn()-1);
                tapahtuma = tapahtuma +"Sankari otti " + QString::number(burn_dmg)+ " palamisvahinkoa ";
    }
    return tapahtuma;
}
QString printtaa2(item ase, hahmo *soturi){
       QString final_txt = "";
        if (ase.getHp() > soturi->getAse().getHp()){
         final_txt  = "hp: + " + QString::number(ase.getHp()) +"\n";
        }if (ase.getHp() < soturi->getAse().getHp()){
            final_txt = "hp - " + QString::number(soturi->getAse().getHp()) +"\n";
           }
        if (ase.getStr() > soturi->getAse().getStr()){
         final_txt = final_txt +"str: + " + QString::number(ase.getStr()) +"\n";
        }if (ase.getStr() < soturi->getAse().getStr()){
            final_txt = final_txt +"str - " + QString::number(soturi->getAse().getStr()) +"\n";
           }

        if (ase.getdex() > soturi->getAse().getdex()){
         final_txt = final_txt +"dex: + " + QString::number(ase.getdex()) +"\n";
        }if (ase.getdex() < soturi->getAse().getdex()){
            final_txt = final_txt +"dex - " + QString::number(soturi->getAse().getdex()) +"\n";
           }

        if (ase.getperc() > soturi->getAse().getperc()){
         final_txt = final_txt +"per: + " + QString::number(ase.getperc()) +"\n";
        }if (ase.getperc() < soturi->getAse().getperc()){
            final_txt = final_txt +"per - " + QString::number(soturi->getAse().getperc()) +"\n";
           }

        if (ase.getint() > soturi->getAse().getint()){
         final_txt = final_txt +"int: + " + QString::number(ase.getint()) +"\n";
        }if (ase.getint() < soturi->getAse().getint()){
            final_txt = final_txt +"int - " + QString::number(soturi->getAse().getint()) +"\n";
           }

        if (ase.getmana() > soturi->getAse().getmana()){
         final_txt = final_txt +"mp: + " + QString::number(ase.getmana()) +"\n";
        }if (ase.getmana() < soturi->getAse().getmana()){
            final_txt = final_txt +"mp - " + QString::number(soturi->getAse().getmana()) +"\n";
           }

        if (ase.getcritrate() > soturi->getAse().getcritrate()){
         final_txt = final_txt +"cRate: + " + QString::number(ase.getcritrate()) +"\n";
        }if (ase.getcritrate() < soturi->getAse().getcritrate()){
            final_txt = final_txt +"cRate - " + QString::number(soturi->getAse().getcritrate()) +"\n";
           }

        if (ase.getcritdmg() > soturi->getAse().getcritdmg()){
         final_txt = final_txt +"cDmg: + " + QString::number(ase.getcritdmg()) +"\n";
        }  if (ase.getcritdmg() < soturi->getAse().getcritdmg()){
            final_txt = final_txt +"cDmg - " + QString::number(soturi->getAse().getcritdmg()) +"\n";
           }

        if (ase.getHitrate() > soturi->getAse().getHitrate()){
         final_txt = final_txt +"hit: + " + QString::number(ase.getHitrate()) +"\n";
        } if (ase.getHitrate() < soturi->getAse().getHitrate()){
            final_txt = final_txt +"hit - " + QString::number(soturi->getAse().getHitrate()) +"\n";
           }

        if (ase.getDodge() > soturi->getAse().getDodge()){
            final_txt = final_txt +"dod: + " + QString::number(ase.getDodge()) +"\n";
           }if (ase.getDodge() < soturi->getAse().getDodge()){
               final_txt = final_txt +"dod - " + QString::number(soturi->getAse().getDodge()) +"\n";
              }



        final_txt = final_txt + QString(ase.get_rarity());


         return final_txt;


}

#endif // HAHMO_H


void writesave(int slot, hahmo *soturi)
{
    QFile file;
    if (slot == 1){
        file.setFileName("slot_1.txt");
    }else if (slot == 2){
        file.setFileName("slot_1.txt");

    }else{
        return;
    }
    if (file.open(QFile::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);


        out << soturi->get_sot_lvl()<< "\n" ;
        out << soturi->getMaxHp()<< "\n" ;

        out << soturi->getStr()<< "\n";
       out << soturi->getDexterity()<< "\n";
        out << soturi->getIntelligence()<< "\n";
        out << soturi->getPerception()<< "\n";



            out << soturi->getAse().getStr()<< "\n" ;
            out << soturi->getAse().getdex()<< "\n" ;
            out << soturi->getAse().getint()<< "\n" ;
            out << soturi->getAse().getperc()<< "\n" ;

            out << soturi->getAse().getcritdmg()<< "\n" ;
            out << soturi->getAse().getcritrate()<< "\n" ;
            out << soturi->getAse().getDodge()<< "\n" ;
            out << soturi->getAse().getHitrate()<< "\n" ;

            out << soturi->getAse().getHp()<< "\n" ;
            out << soturi->getAse().getmana()<< "\n" ;



            out << soturi->getArmor().getStr()<< "\n" ;
            out << soturi->getArmor().getdex()<< "\n" ;
            out << soturi->getArmor().getint()<< "\n" ;
            out << soturi->getArmor().getperc()<< "\n" ;

            out << soturi->getArmor().getcritdmg()<< "\n" ;
            out << soturi->getArmor().getcritrate()<< "\n" ;
            out << soturi->getArmor().getDodge()<< "\n" ;
            out << soturi->getArmor().getHitrate()<< "\n" ;

            out << soturi->getArmor().getHp()<< "\n" ;
            out << soturi->getArmor().getmana()<< "\n" ;

            out << soturi->getVihuLevel()<< "\n" ;
             out << soturi->get_exp()<< "\n" ;

              out << soturi->getAse().get_type()<< "\n" ;
               out << soturi->getArmor().get_type()<< "\n" ;
               out << soturi->getAse().get_wep_type()<< "\n" ;
               out << soturi->getUnusedSP() << "\n";
                for(int i = 0; i < 12; ++i){
                    out << soturi->getWarrSkills().at(i);
                }

                for(int i = 0; i < 12; ++i){
                    out << soturi->getMageSkills().at(i);
                }
                for(int i = 0; i < 12; ++i){
                    out << soturi->getRogueSkills().at(i);
                }



        }
    else {return;}


}
