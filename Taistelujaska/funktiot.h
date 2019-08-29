#ifndef FUNKTIOT_H
#define FUNKTIOT_H

#include "hahmo.h"
#include"item.h"

void writesave(int slot, hahmo *soturi);
int dice100();
int dice20(int x = 1);
int dice6(int x = 1);
int dice3();
int spell_kill_all( int str);
int attack(hahmo *taistelija, hahmo *vihu);
int vihu1_attack(int str);
int vihu_attack(int hitrate, int dodge, int str, int VihuLevel, int VihuRound);
int spell_heal( int str);
int vihu2_attack(int str,int VihuRound);
QString printtaa_arm(hahmo *soturi);
QString printtaa(hahmo *soturi);
QString rollaapotu(hahmo *soturi);
QString printtaa2_arm(item ase,hahmo *soturi);
QString p4life_buff(hahmo *soturi);
QString palamisfunktio(hahmo *vihu, hahmo *soturi);
void warr_dispel_pass(hahmo *soturi);
int warr_dmg_redu(hahmo *soturi);
int warr_leach();
void warr_burn_skill(hahmo *vihu, hahmo *soturi);
QString printtaa2(item ase, hahmo *soturi);


#endif // FUNKTIOT

