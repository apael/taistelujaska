
#include "areena.h"
#include "ui_areena.h"

#include "hahmo.h"
#include "funktiot.cpp"
#include <QString>
#include "item.h"
#include<mainwindow.h>
#include"math.h"
#include <QHoverEvent>
#include"save.h"


void areena::hahmo_lvlup(){

    paivita_stats();
                         }





areena::areena(hahmo *taistelija,hahmo *enemy,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::areena)
{

   // setMouseTracking(true);
    ui->setupUi(this);

   soturi = taistelija;
    vihu = enemy;

    ui->spell_box->hide();
    ui->Item_box->hide();

stunni = 0;


    ui->Hero_mp_bar->setStyleSheet("::chunk {"
                                   "background-color: #2E9AFE;"
                                                "}"
                                   );

    ui->Enemy_mp_bar->setStyleSheet("::chunk {"
                                   "background-color: #2E9AFE;"
                                                "}"
                                   );





    kirves = new item;
    haarniska = new item;

     ui->xp_bar->setMaximum(soturi->next_lvl());
      ui->xp_bar->setValue(soturi->get_exp());


//ui->xp_bar->setValue(warr_dmg_redu(soturi));

    ui->pushButton->setskill(ui->tekstiboksi, 1);
    ui->lyoButton->setskill(ui->tekstiboksi, 2);
    ui->warr_findpot_btn->setskill(ui->tekstiboksi, 3);
    ui->warr_armup_btn->setskill(ui->tekstiboksi, 4);
    ui->warr_p4life_btn->setskill(ui->tekstiboksi, 5);
    ui->warr_trollstrike_btn->setskill(ui->tekstiboksi, 6);
    ui->warr_ultimate_btn->setskill(ui->tekstiboksi, 7);







    soturi->setHp(soturi->getMaxHp());
    soturi->setMana(soturi->getMaxMana());





    paivita_stats();



}

areena::~areena()
{
    delete ui;
    delete vihu;
    delete soturi;

}


void areena::openlevelup()
{
    mlevelup = new levelup(soturi);

    QObject::connect(mlevelup, SIGNAL(valueChanged()),
                     this, SLOT(hahmo_lvlup()));
   // areena::close();
   // MainWindow::MainWindow.show();
    mlevelup->show();


}



void areena::on_lyoButton_clicked()
{   


    kuka_Vastassa();

if (soturi->getHp()>0 && vihu->getHp()>0){
    //jos kumpikaan ei ole kuollut


    int damage = attack(soturi, vihu);

    ui->tekstiboksi->setText(teksti);
    int uusihp = vihu->getHp() - damage;

    vihu->setHp(uusihp);

    tapahtuma = "urhea soturi löi vihua " + QString::number(damage);

    if (damage == 0){
           tapahtuma =  vihuteksti_kuka + " väisti urhean soturin hyökkäysyrityksen";}

    warrskills_ll(damage);
    warr_burn_skill(vihu, soturi);
        vihunVuoro();

}
}
void areena::vihunVuoro(){

    if( vihu->getHp() <= 0){

    vihu_kuollut();


    }

    vihu->setVihuRound(vihu->getVihuRound()+1);
if (stunni == 0){


    //vihu attack laskee vihun tekemän damagen
    puredmg = vihu_attack(vihu->getHitrate(),soturi->getDodge(),vihu->getStr(),vihu->getVihuLevel(),vihu->getVihuRound());
    if (soturi->getWarrSkills().at(7) > 0){
      puredmg = puredmg-warr_dmg_redu(soturi);
    }
    if (soturi->getArmor_buff()  > 0){
        int dmgredu =(puredmg/100)*(soturi->getWarrSkills().at(5)*5);
        puredmg = puredmg-dmgredu;
    }

    if (puredmg == 0){
        vihuteksti = "Urhea sankari väisti hyökkäyksen";


    }else{
        vihuteksti =  vihuteksti_kuka + " iski soturia "+ QString::number(puredmg);

    }
    teksti = tapahtuma + "\n\n" + vihuteksti;

        uusihp = soturi->getHp()-puredmg;
        ui->tekstiboksi->setText(teksti);

         soturi->setHp(uusihp);
          paivita_stats();


        if(soturi->getHp() <= 0){

            QFont f("Arial", 20,QFont::Bold);
            ui->tekstiboksi->setText( Vihuteksti_lost + " SANKARIN KUOLIAAKSI");
            ui->tekstiboksi->setFont(f);
            remove_buffs();
            paivita_stats();
            close();
            emit returnmenu();
         }
    }
if (stunni > 0){
    vihuteksti =   "Vihu keräilee itseään " + QString::number(stunni) + " vuoroa";
     teksti = tapahtuma + "\n\n" + vihuteksti;
     ui->tekstiboksi->setText(teksti);
    stunni--;
     paivita_stats();



}
}

void areena::on_resetButton_clicked()
{




    QFont f("Arial", 8);
    ui->tekstiboksi->setText("");
    ui->tekstiboksi->setFont(f);

close();
    emit returnmenu();
}

void areena::on_taioButton_clicked()
{
    if (soturi->getMana() >= 5 ){
        soturi->setMana(soturi->getMana()-5);


    int damage = spell_kill_all(soturi->getIntelligence());
    tapahtuma =  "Urhea soturi taikoi vihuun "+ QString::number(damage) +" vahinkoa";
     int uusihp = vihu->getHp() - damage;

     vihu->setHp(uusihp);

     if( uusihp <= 0){

vihu_kuollut();


     }else{
         vihunVuoro();

     }
    }else {
        ui->tekstiboksi->setText("Taika vaatii 5 manapistetta");
    }
}


//päivittää statsit labeleihin
void areena::paivita_stats(){
    check_warrskills();
    statuscheck();


    ui->Hero_mp_bar->setMaximum(soturi->getMaxMana());
    ui->Hero_hp_bar->setMaximum(soturi->getMaxHp());

    ui->Hero_mp_bar->setValue(soturi->getMana());
    ui->Hero_hp_bar->setValue(soturi->getHp());


    ui->Enemy_mp_bar->setMaximum(vihu->getMana());
    ui->Enemy_hp_bar->setMaximum(vihu->getMaxHp());
    ui->Enemy_mp_bar->setValue(vihu->getMana());
    ui->Enemy_hp_bar->setValue(vihu->getHp());


    ui->Hp_pot->setText(QString::number(soturi->get_hp_pot())+ " Health Potion");
    ui->Mp_pot->setText(QString::number(soturi->get_mp_pot())+ " Mana Potion");
    ui->super_pot->setText(QString::number(soturi->get_super_pot())+ " Super Potion");



    soturi->setCritDmg((soturi->getDexterity()*0.05)+1+soturi->getAse().getcritdmg()+soturi->getArmor().getcritdmg());
    soturi->setCritRate(-4 + 8* log2(soturi->getPerception())+soturi->getAse().getcritrate()+soturi->getArmor().getcritrate());

    ui->heroStats->setText("hp: " + QString::number(soturi->getHp()) +"\n"+
                          // "hp: " + QString::number(soturi->getAse().getStr()) +"\n"+
                           "str: " + QString::number(soturi->getStr())+"\n"+
                           "dod: " + QString::number(soturi->getDodge()) +"\n"+
                           "man: " + QString::number(soturi->getMana()) +"\n"+
                           "hit: " + QString::number(soturi->getHitrate())+"\n"+
                           "int: " + QString::number(soturi->getIntelligence())+"\n"+
                             "dex: " + QString::number(soturi->getDexterity()) +"\n"+
                             "cDmg: " + QString::number(soturi->getCritDmg()) +"\n"+
                             "crit %: " + QString::number(soturi->getCritRate()) +"\n"+
                             "perc: " + QString::number(soturi->getPerception())+"\n""\n"+

                           "invis: " + QString::number(soturi->getInvisKesto())+"\n"
                           "burn: " + QString::number(soturi->get_burn())+"\n"
                           "freez: " + QString::number(soturi->get_forzen())+"\n"
                           "psn: " + QString::number(soturi->get_poison())+"\n"

                           "p4life: " + QString::number(soturi->getp4life())+"\n"

                           //"ase: " + QString::number(ase.getStr())
                           );

    ui->vihuStats->setText("hp: " + QString::number(vihu->getHp()) +"\n"+
                           "str: " + QString::number(vihu->getStr()) +"\n"+
                           "dod: " + QString::number(vihu->getDodge()) +"\n"+
                           "man: " + QString::number(vihu->getMana()) +"\n"+

                           "perc: " + QString::number(vihu->getPerception()) +"\n"+

                           "burn: " + QString::number(vihu->get_burn()) +"\n"+
                           "freeze: " + QString::number(vihu->get_forzen()) +"\n"+
                           "psn: " + QString::number(vihu->get_poison()) +"\n"+
                           "stunned: " + QString::number(stunni) +"\n"+

                           "hit: " + QString::number(vihu->getHitrate()));



    ui->spell_box->hide();
    ui->Item_box->hide();

    ui->tekstiboksi->setText(tapahtuma+ "\n\n" + vihuteksti);
}



//näkymättömyysviita
void areena::on_pushButton_2_clicked()
{

    if (soturi->getHp()>0 && vihu->getHp()>0){


    if (soturi->getInvisKesto()==0){
    if (soturi->getMana() >= 5 ){
        soturi->setMana(soturi->getMana()-5);

        int kesto = dice3()+dice3();
        int voima = dice6()+dice6();

        soturi->setInvis(voima);
        soturi->setInvisKesto(kesto);
        soturi->setDodge(soturi->getDodge()+soturi->getInvis());

        tapahtuma = "Sankari heitti nakymattomyys viitan paallensa";
        vihunVuoro();

    }
    else {
                ui->tekstiboksi->setText("Taika vaatii 5 manapistetta");
            }
}else{
        ui->tekstiboksi->setText("Sinulla on jo nakymattomyysviitta paallasi");
    }
}
}



void areena::statuscheck(){

    if (soturi->getInvisKesto() > 0){

        soturi->setInvisKesto(soturi->getInvisKesto()-1);
    if (soturi->getInvisKesto() == 0){
        soturi->setDodge(soturi->getDodge()-soturi->getInvis());
    }
    }

    if (soturi->getArmor_buff() > 0){
        soturi->setArmor_buff(soturi->getArmor_buff()-1);
    }

    if (soturi->getp4life() > 0){
        soturi->setp4life(soturi->getp4life()-1);


        tapahtuma = p4life_buff(soturi)+"\n""\n"+tapahtuma;
    }
    if (ulti_cd > 0){
        ulti_cd--;
    }
    tapahtuma = tapahtuma +"\n"+ palamisfunktio(vihu, soturi);

}

void areena::on_pushButton_clicked()
{
    openlevelup();
}

void areena::on_heal_btn_clicked()
{
if (soturi->getHp()>0 && vihu->getHp()>0){

        if (soturi->getMana() >= 5 ){

                    soturi->setMana(soturi->getMana()-5);

                    int heal = spell_heal(soturi->getIntelligence());

                    int uusihp = soturi->getHp() + heal;

                    soturi->setHp(uusihp);


    tapahtuma = "parasit itseasi " + QString::number(heal);
            vihunVuoro();

        }
        else {
        ui->tekstiboksi->setText("Taika vaatii 5 manapistetta");
    }
}
}


//katsoo kuka vihu vastassa muokkaa tekstit sen mukaan
void areena::kuka_Vastassa(){
int vihu_level = vihu->getVihuLevel();
if (vihu_level == 0){
    vihuteksti_kuka = "Ketterä rotta";
    vihuteksti_won = "ROTAN";
            Vihuteksti_lost = "ROTTA PURAISI";
}
     if (vihu_level >= 1){
    vihuteksti_kuka = "Vikkelä Haisoturi";
    vihuteksti_won = "HAISOTURIN";
            Vihuteksti_lost = "HAISOTURI LÖI";
     }
}

void areena::remove_buffs(){
if (soturi->getInvisKesto() > 0){
    soturi->setInvisKesto(0);
    soturi->setDodge(soturi->getDodge()-soturi->getInvis());

}

if (soturi->getArmor_buff() > 0){
    soturi->setArmor_buff(0);

}

if (soturi->getp4life() > 0){
    soturi->setp4life(0);

}
}
//palaa menuun lisää vihun tasoa +1
void areena::vihu_kuollut(){

    paivita_stats();
    remove_buffs();
    areena::close();
    soturi->inc_exp(500+(vihu->getVihuLevel()*100));
    soturi->setVihuLevel(vihu->getVihuLevel()+1);

    if (vihu->getVihuLevel() % 5 == 0){
        writesave(2,soturi);
    }
    vihu->setVihuLevel(vihu->getVihuLevel()+1);




   // if (soturi->get_exp() >= (5 * pow(2,(soturi->get_sot_lvl()))))
    if (soturi->get_exp() >= ((soturi->get_sot_lvl()+1)*600))
    {
                soturi->set_exp(soturi->get_exp()-soturi->next_lvl());
                soturi->set_sot_lvl(soturi->get_sot_lvl()+1);


            openlevelup();
    }
    emit returnmenu();
}


void areena::mouseMoveEvent(QMouseEvent * ){



ui->spell_box->hide();
ui->Item_box->hide();

}
void areena::warrskills_ll(int damage){
if (soturi->getWarrSkills().at(3) > 0 && damage > 0){
 int heal = warr_leach();
 uusihp = soturi->getHp()+heal;
 soturi->setHp(uusihp);
tapahtuma = tapahtuma + " vampirismi paranti sinua " + QString::number(heal);
}
}


void areena::on_Spells_btn_clicked()
{
    ui->spell_box->show();
   // ui->Spells_btn->hide();
}
void areena::on_Item_storage_clicked()
{
 ui->Item_box->show();
}


void areena::on_Hp_pot_clicked()
{
if (soturi->getHp()>0 && vihu->getHp()>0){

        if (soturi->get_hp_pot() > 0 ){



                    int heal = (dice20())*(soturi->get_sot_lvl()+1);

                    int uusihp = soturi->getHp() + heal;

                    soturi->setHp(uusihp);

                    soturi->set_hp_pot(soturi->get_hp_pot()-1);

    tapahtuma = "Potioni paranti sinua " + QString::number(heal);
            vihunVuoro();

        }
        else {
        ui->tekstiboksi->setText("Sinulla ei ole potuja");
    }
}
}
void areena::on_Mp_pot_clicked()
{
    if (soturi->getHp()>0 && vihu->getHp()>0){

            if (soturi->get_mp_pot() > 0 ){



                        int healmp = (dice20())*(soturi->get_sot_lvl()+1);

                        int uusimp = soturi->getMana() + healmp;

                        soturi->setMana(uusimp);

                        soturi->set_mp_pot(soturi->get_mp_pot()-1);

        tapahtuma = "Potioni palautti manaa " + QString::number(healmp);
                vihunVuoro();

            }
            else {
            ui->tekstiboksi->setText("Sinulla ei ole potuja");
        }
    }
}
void areena::on_super_pot_clicked()
{
    if (soturi->getHp()>0 && vihu->getHp()>0){

            if (soturi->get_hp_pot() > 0 ){

                int healmp = (dice20())*(soturi->get_sot_lvl()+1);

                int uusimp = soturi->getMana() + healmp;

                soturi->setMana(uusimp);


                        int heal = (dice20())*(soturi->get_sot_lvl()+1);

                        int uusihp = soturi->getHp() + heal;

                        soturi->setHp(uusihp);

                        soturi->set_super_pot(soturi->get_super_pot()-1);

        tapahtuma = "Potioni paranti sinua " + QString::number(heal)+ " ja palautti manaa " + QString::number(healmp);
                vihunVuoro();

            }
            else {
            ui->tekstiboksi->setText("Sinulla ei ole potuja");
        }
    }
}
void areena::on_warr_findpot_btn_clicked()
{

    if (soturi->getHp()>0 && vihu->getHp()>0){

            if (soturi->getMana() >= 5 ){

                        soturi->setMana(soturi->getMana()-5);

                        int y = 0;
                        while (soturi->getWarrSkills().at(8) > y)
                        {
                         tapahtuma =  rollaapotu(soturi);
                        y++;
                        if (y > 1){
                           tapahtuma = "Löysit " + QString::number(y)+ " erilaista potionia";
                        }

                            }







                vihunVuoro();

            }
            else {
            ui->tekstiboksi->setText("Taika vaatii 5 manapistetta");
        }
    }


}
void areena::on_warr_armup_btn_clicked()
{

    if (soturi->getHp()>0 && vihu->getHp()>0){


    if (soturi->getArmor_buff()==0){
    if (soturi->getMana() >= 5 ){
        soturi->setMana(soturi->getMana()-5);

        int kesto = dice3()+dice3();
        //int voima = dice6()*2;

        soturi->setArmor_buff(kesto);

        //soturi->setDodge(soturi->getDodge()+soturi->getInvis());

        tapahtuma = "Sankari pumppasi panssaria " + QString::number(kesto) + " vuoroksi";
        vihunVuoro();

    }
    else {
                ui->tekstiboksi->setText("Taika vaatii 5 manapistetta");
            }
}else{
        ui->tekstiboksi->setText("Armorisi kestää vielä "+ QString::number(soturi->getArmor_buff()) +" vuoroa" );
    }
}
}
void areena::on_warr_p4life_btn_clicked()
{

    if (soturi->getHp()>0 && vihu->getHp()>0){


    if (soturi->getp4life()==0){
    if (soturi->getMana() >= 5 ){
        soturi->setMana(soturi->getMana()-5);

        int kesto = dice3()+soturi->getWarrSkills().at(6);


        soturi->setp4life(kesto);



        tapahtuma = "Sankari siunattiin " + QString::number(kesto) + " vuoroksi";


        vihunVuoro();

    }
    else {
                ui->tekstiboksi->setText("Taika vaatii 5 manapistetta");
            }
}else{
        ui->tekstiboksi->setText("Siunauksesi kestää vielä "+ QString::number(soturi->getp4life()) +" vuoroa" );
    }
}
}
void areena::on_warr_trollstrike_btn_clicked()
{

    if (soturi->getHp()>0 && vihu->getHp()>0){

            if (soturi->getMana() >= 5 ){

                        soturi->setMana(soturi->getMana()-5);
                kuka_Vastassa();


                        int aseen_noppaluku,dmgroll, i = 0;

                    if (soturi->getAse().getdice_type() > 0  && soturi->getAse().getdice_amount() > 0){

                       while (soturi->getAse().getdice_amount() > i ){
                        aseen_noppaluku = (rand () % soturi->getAse().getdice_type()+1)+aseen_noppaluku;
                                i++;
                    }

                    }else {
                        aseen_noppaluku = 0;
                    }

                        if(soturi->getHitrate()*dice6() > vihu->getDodge()*dice20())
                    { //osuma


                        if (soturi->getCritRate() <= dice100() && soturi->getCritRate() > 0){
                            dmgroll = ((soturi->getStr()*soturi->getWarrSkills().at(10))+ dice20() + aseen_noppaluku)*soturi->getCritDmg();

                            int uusihp = vihu->getHp() - dmgroll;

                            vihu->setHp(uusihp);

                            tapahtuma = "urhea soturi osui kriittisen raivolyönnin tehden " + QString::number(dmgroll);

                                warrskills_ll(dmgroll);
                                warr_burn_skill(vihu,soturi);
                             vihunVuoro();

                        }

                        else {

                        dmgroll = soturi->getStr()*soturi->getWarrSkills().at(10)+ dice20();


                        int uusihp = vihu->getHp() - dmgroll;

                        vihu->setHp(uusihp);

                        tapahtuma = "urhea soturi osui raivolyönnin tehden " + QString::number(dmgroll);

                        warrskills_ll(dmgroll);
                        warr_burn_skill(vihu, soturi);
                        vihunVuoro();

                        }
                        }
                        else {
                            dmgroll = 0;
                        }
                        if (dmgroll == 0){

                               tapahtuma =  vihuteksti_kuka + " väisti raivoisan soturin iskun";
                                warrskills_ll(dmgroll);

                        }

                            vihunVuoro();


            }
            else {
            ui->tekstiboksi->setText("Taika vaatii 5 manapistetta");
        }
    }




}
void areena::on_warr_ultimate_btn_clicked()
{
if (ulti_cd == 0){
    ulti_cd = 4;

    if (dice20() > 5+soturi->getWarrSkills().at(11)){
        stunni = dice3();
    }
    if (soturi->getHp()>0 && vihu->getHp()>0){

            if (soturi->getMana() >= 5 ){

                        soturi->setMana(soturi->getMana()-5);
                kuka_Vastassa();


                        int aseen_noppaluku,dmgroll, i = 0;

                    if (soturi->getAse().getdice_type() > 0  && soturi->getAse().getdice_amount() > 0){

                       while (soturi->getAse().getdice_amount() > i ){
                        aseen_noppaluku = (rand () % (soturi->getAse().getdice_type()+1))+aseen_noppaluku;
                                i++;
                    }

                    }else {
                        aseen_noppaluku = 0;
                    }

                        if(soturi->getHitrate()*dice20() > vihu->getDodge()*dice20())
                    { //osuma



                        if (soturi->getCritRate() <= dice100() && soturi->getCritRate() > 0){
                            dmgroll = ((soturi->getStr()/2)+ dice20());

                            int uusihp = vihu->getHp() - dmgroll;

                            vihu->setHp(uusihp);

                            tapahtuma = "urhea soturi osui kriittisen superiskun tehden " + QString::number(dmgroll);


                            warrskills_ll(dmgroll);
                            warr_burn_skill(vihu,soturi);
                             vihunVuoro();

                        }

                        else {

                        dmgroll = (soturi->getStr()*2+1);


                        int uusihp = vihu->getHp() - dmgroll;

                        vihu->setHp(uusihp);

                        tapahtuma = "urhea soturi osui raivolyönnin tehden " + QString::number(dmgroll);

                        warrskills_ll(dmgroll);
                        warr_burn_skill(vihu, soturi);


                        vihunVuoro();


                        }



                        }
                        else {
                            dmgroll = 0;
                        }
                        if (dmgroll == 0){

                               tapahtuma =  vihuteksti_kuka + " väisti raivoisan soturin iskun";
                        warrskills_ll(dmgroll);
                        }


                        vihunVuoro();

            }
            else {
            ui->tekstiboksi->setText("Taika vaatii 5 manapistetta");
        }

}
}
    else{
    ui->tekstiboksi->setText("Taito cooldownilla" + QString::number(ulti_cd));
}
}

void areena::check_warrskills(){
    if (soturi->getWarrSkills().at(5) > 0){
        ui->warr_armup_btn->show();
    }else {
        ui->warr_armup_btn->hide();
    }
    if (soturi->getWarrSkills().at(6) > 0){
        ui->warr_p4life_btn->show();
    }else {
        ui->warr_p4life_btn->hide();
    }
    if (soturi->getWarrSkills().at(10) > 0){
        ui->warr_trollstrike_btn->show();
    }else {
        ui->warr_trollstrike_btn->hide();
    }
    if (soturi->getWarrSkills().at(11) > 0){
        ui->warr_ultimate_btn->show();
    }else {
        ui->warr_ultimate_btn->hide();
    }
    if (soturi->getWarrSkills().at(8) > 0){
        ui->warr_findpot_btn->show();
    }else {
        ui->warr_findpot_btn->hide();
    }


}


