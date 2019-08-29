#include "skilltree.h"
#include "ui_skilltree.h"
#include "hahmo.h"
#include <QVector>
#include <qabstractspinbox.h>
#include <QLineEdit>
skilltree::skilltree(hahmo *sot, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::skilltree)
{
    ui->setupUi(this);
    ui->magebox->setVisible(false);
    ui->rogueBox->setVisible(false);
    totalPoints_ = 0;
    ui->warrSkillLbl->setToolTip("Your pansy warrior is blind no more \nHit chance increased by 1%");
    ui->warrSkillLbl_2->setToolTip("This is the skill you wouldnt like to get\nIncreases your resistance to status\neffects by 5%");
    ui->warrSkillLbl_3->setToolTip("Gives the mighty warrior chance of 5%\nto burn his puny opponents \nin to dust");
    ui->warrSkillLbl_4->setToolTip("Your hero will feast on blood of \nhis enemies");

    ui->warrSkillLbl_5->setToolTip("There will be blood\nbetter have enough of if...");
    ui->warrSkillLbl_6->setToolTip("Your warrior has found a way to solder\npieces to his armor");
    ui->warrSkillLbl_7->setToolTip("Where is that damn lazy healer again!?");
    ui->warrSkillLbl_8->setToolTip("Be like a tree sting like a cactus\nyour has learned the secret art of\nbeing a tree");
    ui->warrSkillLbl_9->setToolTip("Over the years and countless bars\nwarrior has acquired scent for\ncertain beverages");

    ui->warrSkillLbl_10->setToolTip("They say anabolic steroids are good for you\nWho am I to judge?");
    ui->warrSkillLbl_11->setToolTip("Are you feeling lucky?\nVegas simulator 2016");
    ui->warrSkillLbl_12->setToolTip("Are you ready to break the world?");

    soturi = sot;
    alustaValuet();
    ui->warrSkillSpin_1->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_2->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_3->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_4->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_5->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_6->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_7->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_8->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_9->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_10->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_11->findChild<QLineEdit*>()->setReadOnly(true);
    ui->warrSkillSpin_12->findChild<QLineEdit*>()->setReadOnly(true);


    ui->mageSkillSpin_1->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_2->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_3->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_4->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_5->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_6->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_7->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_8->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_9->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_10->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_11->findChild<QLineEdit*>()->setReadOnly(true);
    ui->mageSkillSpin_12->findChild<QLineEdit*>()->setReadOnly(true);


    ui->rogueSkillSpin_1->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_2->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_3->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_4->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_5->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_6->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_7->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_8->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_9->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_10->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_11->findChild<QLineEdit*>()->setReadOnly(true);
    ui->rogueSkillSpin_12->findChild<QLineEdit*>()->setReadOnly(true);

    //skillien minimivalue on aikaisemmin laitettujen arvojen value
    ui->warrSkillSpin_1->setMinimum(soturi->getWarrSkills().at(0));
    ui->warrSkillSpin_2->setMinimum(soturi->getWarrSkills().at(1));
    ui->warrSkillSpin_3->setMinimum(soturi->getWarrSkills().at(2));
    ui->warrSkillSpin_4->setMinimum(soturi->getWarrSkills().at(3));
    ui->warrSkillSpin_5->setMinimum(soturi->getWarrSkills().at(4));
    ui->warrSkillSpin_6->setMinimum(soturi->getWarrSkills().at(5));
    ui->warrSkillSpin_7->setMinimum(soturi->getWarrSkills().at(6));
    ui->warrSkillSpin_8->setMinimum(soturi->getWarrSkills().at(7));
    ui->warrSkillSpin_9->setMinimum(soturi->getWarrSkills().at(8));
    ui->warrSkillSpin_10->setMinimum(soturi->getWarrSkills().at(9));
    ui->warrSkillSpin_11->setMinimum(soturi->getWarrSkills().at(10));
    ui->warrSkillSpin_12->setMinimum(soturi->getWarrSkills().at(11));

    ui->rogueSkillSpin_1->setMinimum(soturi->getRogueSkills().at(0));
    ui->rogueSkillSpin_2->setMinimum(soturi->getRogueSkills().at(1));
    ui->rogueSkillSpin_3->setMinimum(soturi->getRogueSkills().at(2));
    ui->rogueSkillSpin_4->setMinimum(soturi->getRogueSkills().at(3));
    ui->rogueSkillSpin_5->setMinimum(soturi->getRogueSkills().at(4));
    ui->rogueSkillSpin_6->setMinimum(soturi->getRogueSkills().at(5));
    ui->rogueSkillSpin_7->setMinimum(soturi->getRogueSkills().at(6));
    ui->rogueSkillSpin_8->setMinimum(soturi->getRogueSkills().at(7));
    ui->rogueSkillSpin_9->setMinimum(soturi->getRogueSkills().at(8));
    ui->rogueSkillSpin_10->setMinimum(soturi->getRogueSkills().at(9));
    ui->rogueSkillSpin_11->setMinimum(soturi->getRogueSkills().at(10));
    ui->rogueSkillSpin_12->setMinimum(soturi->getRogueSkills().at(11));


    ui->mageSkillSpin_1->setMinimum(soturi->getMageSkills().at(0));
    ui->mageSkillSpin_2->setMinimum(soturi->getMageSkills().at(1));
    ui->mageSkillSpin_3->setMinimum(soturi->getMageSkills().at(2));
    ui->mageSkillSpin_4->setMinimum(soturi->getMageSkills().at(3));
    ui->mageSkillSpin_5->setMinimum(soturi->getMageSkills().at(4));
    ui->mageSkillSpin_6->setMinimum(soturi->getMageSkills().at(5));
    ui->mageSkillSpin_7->setMinimum(soturi->getMageSkills().at(6));
    ui->mageSkillSpin_8->setMinimum(soturi->getMageSkills().at(7));
    ui->mageSkillSpin_9->setMinimum(soturi->getMageSkills().at(8));
    ui->mageSkillSpin_10->setMinimum(soturi->getMageSkills().at(9));
    ui->mageSkillSpin_11->setMinimum(soturi->getMageSkills().at(10));
    ui->mageSkillSpin_12->setMinimum(soturi->getMageSkills().at(11));

    //skillin max value on 5
    ui->warrSkillSpin_1->setMaximum(5);
    ui->warrSkillSpin_2->setMaximum(5);
    ui->warrSkillSpin_3->setMaximum(5);
    ui->warrSkillSpin_4->setMaximum(5);
    ui->warrSkillSpin_5->setMaximum(5);
    ui->warrSkillSpin_6->setMaximum(5);
    ui->warrSkillSpin_7->setMaximum(5);
    ui->warrSkillSpin_8->setMaximum(5);
    ui->warrSkillSpin_9->setMaximum(5);
    ui->warrSkillSpin_10->setMaximum(5);
    ui->warrSkillSpin_11->setMaximum(5);
    ui->warrSkillSpin_12->setMaximum(5);

    ui->mageSkillSpin_1->setMaximum(5);
    ui->mageSkillSpin_2->setMaximum(5);
    ui->mageSkillSpin_3->setMaximum(5);
    ui->mageSkillSpin_4->setMaximum(5);
    ui->mageSkillSpin_5->setMaximum(5);
    ui->mageSkillSpin_6->setMaximum(5);
    ui->mageSkillSpin_7->setMaximum(5);
    ui->mageSkillSpin_8->setMaximum(5);
    ui->mageSkillSpin_9->setMaximum(5);
    ui->mageSkillSpin_10->setMaximum(5);
    ui->mageSkillSpin_11->setMaximum(5);
    ui->mageSkillSpin_12->setMaximum(5);

    ui->rogueSkillSpin_1->setMaximum(5);
    ui->rogueSkillSpin_2->setMaximum(5);
    ui->rogueSkillSpin_3->setMaximum(5);
    ui->rogueSkillSpin_4->setMaximum(5);
    ui->rogueSkillSpin_5->setMaximum(5);
    ui->rogueSkillSpin_6->setMaximum(5);
    ui->rogueSkillSpin_7->setMaximum(5);
    ui->rogueSkillSpin_8->setMaximum(5);
    ui->rogueSkillSpin_9->setMaximum(5);
    ui->rogueSkillSpin_10->setMaximum(5);
    ui->rogueSkillSpin_11->setMaximum(5);
    ui->rogueSkillSpin_12->setMaximum(5);

    for(int i = 0; i < 12;++i){
        totalPoints_ = totalPoints_ + soturi->getWarrSkills().at(i);
        totalPoints_ = totalPoints_ + soturi->getMageSkills().at(i);
        totalPoints_ = totalPoints_ + soturi->getRogueSkills().at(i);
    }
    usedPoints_ = totalPoints_;
    pointsleft_ = soturi->getUnusedSP() + 25;
    totalPoints_ = totalPoints_ + pointsleft_;
    ui->textBrowser->setText(QString::number(pointsleft_));
    warrValueChanged();
    mageValueChanged();
    rogueValueChanged();

}

skilltree::~skilltree()
{
    delete ui;
}

int skilltree::calculateWSkills()
{
    return ui->warrSkillSpin_1->value() + ui->warrSkillSpin_2->value()
            + ui->warrSkillSpin_3->value()+ ui->warrSkillSpin_4->value()+ ui->warrSkillSpin_5->value()
            + ui->warrSkillSpin_6->value()+ ui->warrSkillSpin_7->value()+ ui->warrSkillSpin_8->value()
            + ui->warrSkillSpin_9->value()+ ui->warrSkillSpin_10->value()+ ui->warrSkillSpin_11->value()
            + ui->warrSkillSpin_12->value();
}

int skilltree::calculateMSkills()
{
    return ui->mageSkillSpin_1->value() + ui->mageSkillSpin_2->value()
            + ui->mageSkillSpin_3->value()+ ui->mageSkillSpin_4->value()+ ui->mageSkillSpin_5->value()
            + ui->mageSkillSpin_6->value()+ ui->mageSkillSpin_7->value()+ ui->mageSkillSpin_8->value()
            + ui->mageSkillSpin_9->value()+ ui->mageSkillSpin_10->value()+ ui->mageSkillSpin_11->value()
            + ui->mageSkillSpin_12->value();
}

int skilltree::calculateRSkills()
{
    return ui->rogueSkillSpin_1->value() + ui->rogueSkillSpin_2->value()
            + ui->rogueSkillSpin_3->value()+ ui->rogueSkillSpin_4->value()+ ui->rogueSkillSpin_5->value()
            + ui->rogueSkillSpin_6->value()+ ui->rogueSkillSpin_7->value()+ ui->rogueSkillSpin_8->value()
            + ui->rogueSkillSpin_9->value()+ ui->rogueSkillSpin_10->value()+ ui->rogueSkillSpin_11->value()
            + ui->rogueSkillSpin_12->value();
}

bool skilltree::warrValueChanged()
{
    if(calculateMSkills()+calculateRSkills()+calculateWSkills()> totalPoints_){

        return false;
    }
    else if(usedPoints_ < calculateMSkills() + calculateRSkills() + calculateWSkills()){
        pointsleft_--;
    }else if (usedPoints_ > calculateMSkills() + calculateRSkills() + calculateWSkills()){
        pointsleft_++;
    }
    //ENSIMMÄINEN WARR HAARA
    if(ui->warrSkillSpin_1->value()>= 3 &&
            ui->warrSkillSpin_5->value()+ ui->warrSkillSpin_1->value() +ui->warrSkillSpin_9->value() >= 5 ){
        ui->warrSkillSpin_2->setEnabled(true);
    }
    else{
        ui->warrSkillSpin_2->setEnabled(false);
        if (ui->warrSkillSpin_2->value() != 0){
            pointsleft_ = pointsleft_+ ui->warrSkillSpin_2->value()-1;
            ui->warrSkillSpin_2->setValue(0);
        }
    }

    if(ui->warrSkillSpin_2->value() >= 3 &&
             ui->warrSkillSpin_5->value()+ ui->warrSkillSpin_1->value() +ui->warrSkillSpin_9->value()+
            ui->warrSkillSpin_2->value()  + ui->warrSkillSpin_6->value()+ ui->warrSkillSpin_10->value()  >= 10 ){

        ui->warrSkillSpin_3->setEnabled(true);

    } else{
        ui->warrSkillSpin_3->setEnabled(false);
        if (ui->warrSkillSpin_3->value() != 0){
            pointsleft_ = pointsleft_+ ui->warrSkillSpin_3->value()-1;
            ui->warrSkillSpin_3->setValue(0);
        }
    }if( ui->warrSkillSpin_3->value() >= 1 &&
            ui->warrSkillSpin_5->value()+ ui->warrSkillSpin_1->value() +ui->warrSkillSpin_9->value()+
         ui->warrSkillSpin_2->value() + ui->warrSkillSpin_6->value()+ ui->warrSkillSpin_10->value() +
         ui->warrSkillSpin_3->value()+ ui->warrSkillSpin_7->value()+ ui->warrSkillSpin_11->value() >= 15){

        ui->warrSkillSpin_4->setEnabled(true);
        ui->warrSkillSpin_8->setEnabled(true);

    }else{
        ui->warrSkillSpin_4->setEnabled(false);
        ui->warrSkillSpin_8->setEnabled(false);
        if (ui->warrSkillSpin_4->value() != 0){
            pointsleft_ = pointsleft_+ ui->warrSkillSpin_4->value()-1;
            ui->warrSkillSpin_4->setValue(0);
        }if (ui->warrSkillSpin_8->value() != 0){
            pointsleft_ = pointsleft_+ ui->warrSkillSpin_8->value()-1;
            ui->warrSkillSpin_8->setValue(0);
        }


    }   //EKAN WARR HAARAN LOPPU

    //TOINEN WARR HAARA
    if(ui->warrSkillSpin_5->value()>= 1 &&
            ui->warrSkillSpin_5->value()+ ui->warrSkillSpin_1->value() +ui->warrSkillSpin_9->value() >= 5 ){
        ui->warrSkillSpin_6->setEnabled(true);

    }else{
        ui->warrSkillSpin_6->setEnabled(false);
        if (ui->warrSkillSpin_6->value() != 0){
                    pointsleft_ = pointsleft_+ ui->warrSkillSpin_6->value()-1;
                    ui->warrSkillSpin_6->setValue(0);
                }
    }
    if(ui->warrSkillSpin_6->value() >= 1 &&
         ui->warrSkillSpin_5->value() + ui->warrSkillSpin_1->value() +ui->warrSkillSpin_9->value()+
        ui->warrSkillSpin_2->value()  + ui->warrSkillSpin_6->value() + ui->warrSkillSpin_10->value()  >= 10 ){

        ui->warrSkillSpin_7->setEnabled(true);

    }else{
        ui->warrSkillSpin_7->setEnabled(false);
        if ( ui->warrSkillSpin_7->value() != 0){
            pointsleft_ = pointsleft_+ ui->warrSkillSpin_7->value()-1;
            ui->warrSkillSpin_7->setValue(0);
        }
    }
//VIKA HAARA
    if(ui->warrSkillSpin_9->value()>= 1 &&
            ui->warrSkillSpin_5->value()+ ui->warrSkillSpin_1->value() +ui->warrSkillSpin_9->value() >= 5 ){
        ui->warrSkillSpin_10->setEnabled(true);
    }else{
        ui->warrSkillSpin_10->setEnabled(false);
        pointsleft_ = pointsleft_+ ui->warrSkillSpin_10->value();
        ui->warrSkillSpin_10->setValue(0);
    }if(ui->warrSkillSpin_10->value() >= 1 &&
            ui->warrSkillSpin_5->value() + ui->warrSkillSpin_1->value() + ui->warrSkillSpin_9->value()+
           ui->warrSkillSpin_2->value()  + ui->warrSkillSpin_6->value() + ui->warrSkillSpin_10->value()  >= 10 ){

           ui->warrSkillSpin_11->setEnabled(true);

       }else{
        ui->warrSkillSpin_11->setEnabled(false);
        if (ui->warrSkillSpin_11->value() != 0){
            pointsleft_ = pointsleft_+ ui->warrSkillSpin_11->value()-1;
            ui->warrSkillSpin_11->setValue(0);
        }
       }
    //LINKKAUS WARRU VIKAAN SKILLIIN
    if(ui->warrSkillSpin_7->value() >= 1 && ui->warrSkillSpin_11->value() >= 1 &&
            ui->warrSkillSpin_5->value()+ ui->warrSkillSpin_1->value() +ui->warrSkillSpin_9->value()+
         ui->warrSkillSpin_2->value() + ui->warrSkillSpin_6->value() + ui->warrSkillSpin_10->value() +
         ui->warrSkillSpin_3->value()+ ui->warrSkillSpin_7->value() + ui->warrSkillSpin_11->value() >= 15){

        ui->warrSkillSpin_12->setEnabled(true);

    }else{
        ui->warrSkillSpin_12->setEnabled(false);
        if (
            ui->warrSkillSpin_12->value() != 0){
            pointsleft_ = pointsleft_+ ui->warrSkillSpin_12->value()-1;
            ui->warrSkillSpin_12->setValue(0);
        }
    }
    usedPoints_ = calculateMSkills() + calculateRSkills() + calculateWSkills();
    ui->textBrowser->setText(QString::number(pointsleft_));

    return true;
}

bool skilltree::mageValueChanged()
{
    if(calculateMSkills()+calculateRSkills()+calculateWSkills()> totalPoints_){
        return false;
    }
    else if(usedPoints_ < calculateMSkills() + calculateRSkills() + calculateWSkills()){
        pointsleft_--;
    }else if (usedPoints_ > calculateMSkills() + calculateRSkills() + calculateWSkills()){
        pointsleft_++;
    }
    usedPoints_ = calculateMSkills() + calculateRSkills() + calculateWSkills();
    //ENSIMMÄINEN mage HAARA
    if(ui->mageSkillSpin_1->value()>= 3 &&
            ui->mageSkillSpin_5->value()+ ui->mageSkillSpin_1->value() +ui->mageSkillSpin_9->value() >= 5 ){
        ui->mageSkillSpin_2->setEnabled(true);
    }
    else{
        ui->mageSkillSpin_2->setEnabled(false);
        if (ui->mageSkillSpin_2->value() != 0){
            pointsleft_ = pointsleft_+ ui->mageSkillSpin_2->value()-1;
            ui->mageSkillSpin_2->setValue(0);
        }
    }

    if(ui->mageSkillSpin_2->value() >= 3 &&
             ui->mageSkillSpin_5->value()+ ui->mageSkillSpin_1->value() +ui->mageSkillSpin_9->value()+
            ui->mageSkillSpin_2->value()  + ui->mageSkillSpin_6->value()+ ui->mageSkillSpin_10->value()  >= 10 ){

        ui->mageSkillSpin_3->setEnabled(true);

    } else{
        ui->mageSkillSpin_3->setEnabled(false);
        if (ui->mageSkillSpin_3->value() != 0){
            pointsleft_ = pointsleft_+ ui->mageSkillSpin_3->value()-1;
            ui->mageSkillSpin_3->setValue(0);
        }
    }if( ui->mageSkillSpin_3->value() >= 1 &&
            ui->mageSkillSpin_5->value()+ ui->mageSkillSpin_1->value() +ui->mageSkillSpin_9->value()+
         ui->mageSkillSpin_2->value() + ui->mageSkillSpin_6->value()+ ui->mageSkillSpin_10->value() +
         ui->mageSkillSpin_3->value()+ ui->mageSkillSpin_7->value()+ ui->mageSkillSpin_11->value() >= 15){

        ui->mageSkillSpin_4->setEnabled(true);
        ui->mageSkillSpin_8->setEnabled(true);

    }else{
        ui->mageSkillSpin_4->setEnabled(false);
        ui->mageSkillSpin_8->setEnabled(false);
        if (ui->mageSkillSpin_4->value() != 0){
            pointsleft_ = pointsleft_+ ui->mageSkillSpin_4->value()-1;

            ui->mageSkillSpin_4->setValue(0);
        }if (ui->mageSkillSpin_8->value() != 0){
            pointsleft_ = pointsleft_+ ui->mageSkillSpin_8->value()-1;
            ui->mageSkillSpin_8->setValue(0);
        }


    }   //EKAN mage HAARAN LOPPU

    //TOINEN mage HAARA
    if(ui->mageSkillSpin_5->value()>= 1 &&
            ui->mageSkillSpin_5->value()+ ui->mageSkillSpin_1->value() +ui->mageSkillSpin_9->value() >= 5 ){
        ui->mageSkillSpin_6->setEnabled(true);

    }else{
        ui->mageSkillSpin_6->setEnabled(false);
        if (ui->mageSkillSpin_6->value() != 0){
                    pointsleft_ = pointsleft_+ ui->mageSkillSpin_6->value()-1;
                    ui->mageSkillSpin_6->setValue(0);
                }
    }
    if(ui->mageSkillSpin_6->value() >= 1 &&
         ui->mageSkillSpin_5->value() + ui->mageSkillSpin_1->value() +ui->mageSkillSpin_9->value()+
        ui->mageSkillSpin_2->value()  + ui->mageSkillSpin_6->value() + ui->mageSkillSpin_10->value()  >= 10 ){

        ui->mageSkillSpin_7->setEnabled(true);

    }else{
        ui->mageSkillSpin_7->setEnabled(false);
        if ( ui->mageSkillSpin_7->value() != 0){
            pointsleft_ = pointsleft_+ ui->mageSkillSpin_7->value()-1;
            ui->mageSkillSpin_7->setValue(0);
        }
    }
    //Viimeinen mage haara
    if(ui->mageSkillSpin_9->value()>= 1 &&
            ui->mageSkillSpin_5->value()+ ui->mageSkillSpin_1->value() +ui->mageSkillSpin_9->value() >= 5 ){
        ui->mageSkillSpin_10->setEnabled(true);
    }else{
        ui->mageSkillSpin_10->setEnabled(false);
        pointsleft_ = pointsleft_+ ui->mageSkillSpin_10->value();
        ui->mageSkillSpin_10->setValue(0);
    }if(ui->mageSkillSpin_10->value() >= 1 &&
            ui->mageSkillSpin_5->value() + ui->mageSkillSpin_1->value() + ui->mageSkillSpin_9->value()+
           ui->mageSkillSpin_2->value()  + ui->mageSkillSpin_6->value() + ui->mageSkillSpin_10->value()  >= 10 ){

           ui->mageSkillSpin_11->setEnabled(true);

       }else{
        ui->mageSkillSpin_11->setEnabled(false);
        if (ui->mageSkillSpin_11->value() != 0){
            pointsleft_ = pointsleft_+ ui->mageSkillSpin_11->value()-1;
            ui->mageSkillSpin_11->setValue(0);
        }
       }
    //LINKKAUS mage VIKAAN SKILLIIN
    if(ui->mageSkillSpin_7->value() >= 1 && ui->mageSkillSpin_11->value() >= 1 &&
            ui->mageSkillSpin_5->value()+ ui->mageSkillSpin_1->value() +ui->mageSkillSpin_9->value()+
         ui->mageSkillSpin_2->value() + ui->mageSkillSpin_6->value()+ ui->mageSkillSpin_10->value() +
         ui->mageSkillSpin_3->value()+ ui->mageSkillSpin_7->value()+ ui->mageSkillSpin_11->value() >= 15){
        ui->mageSkillSpin_12->setEnabled(true);
    }else{
        ui->mageSkillSpin_12->setEnabled(false);
        if (ui->mageSkillSpin_12->value() != 0){
            pointsleft_ = pointsleft_+ ui->mageSkillSpin_12->value()-1;
            ui->mageSkillSpin_12->setValue(0);
        }
    }
    usedPoints_ = calculateMSkills() + calculateRSkills() + calculateWSkills();
    ui->textBrowser->setText(QString::number(pointsleft_));
    return true;
}
bool skilltree::rogueValueChanged()
{
    if(calculateMSkills()+calculateRSkills()+calculateWSkills()> totalPoints_){
        return false;
    }
    else if(usedPoints_ < calculateMSkills() + calculateRSkills() + calculateWSkills()){
        pointsleft_--;
    }else if (usedPoints_ > calculateMSkills() + calculateRSkills() + calculateWSkills()){
        pointsleft_++;
    }
    usedPoints_ = calculateMSkills() + calculateRSkills() + calculateWSkills();
    ui->textBrowser->setText(QString::number(pointsleft_));
    //ENSIMMÄINEN rogue HAARA
    if(ui->rogueSkillSpin_1->value()>= 3 &&
            ui->rogueSkillSpin_5->value()+ ui->rogueSkillSpin_1->value() +ui->rogueSkillSpin_9->value() >= 5 ){
        ui->rogueSkillSpin_2->setEnabled(true);
    }
    else{
        ui->rogueSkillSpin_2->setEnabled(false);
        if (ui->rogueSkillSpin_2->value() != 0){
            pointsleft_ = pointsleft_+ ui->rogueSkillSpin_2->value()-1;
            ui->rogueSkillSpin_2->setValue(0);
        }
    }

    if(ui->rogueSkillSpin_2->value() >= 3 &&
             ui->rogueSkillSpin_5->value()+ ui->rogueSkillSpin_1->value() +ui->rogueSkillSpin_9->value()+
            ui->rogueSkillSpin_2->value()  + ui->rogueSkillSpin_6->value()+ ui->rogueSkillSpin_10->value()  >= 10 ){

        ui->rogueSkillSpin_3->setEnabled(true);

    } else{
        ui->rogueSkillSpin_3->setEnabled(false);
        if (ui->rogueSkillSpin_3->value() != 0){
            pointsleft_ = pointsleft_+ ui->rogueSkillSpin_3->value()-1;
            ui->rogueSkillSpin_3->setValue(0);
        }
    }if( ui->rogueSkillSpin_3->value() >= 1 &&
            ui->rogueSkillSpin_5->value()+ ui->rogueSkillSpin_1->value() +ui->rogueSkillSpin_9->value()+
         ui->rogueSkillSpin_2->value() + ui->rogueSkillSpin_6->value()+ ui->rogueSkillSpin_10->value() +
         ui->rogueSkillSpin_3->value()+ ui->rogueSkillSpin_7->value()+ ui->rogueSkillSpin_11->value() >= 15){

        ui->rogueSkillSpin_4->setEnabled(true);
        ui->rogueSkillSpin_8->setEnabled(true);

    }else{
        ui->rogueSkillSpin_4->setEnabled(false);
        ui->rogueSkillSpin_8->setEnabled(false);
        if (ui->rogueSkillSpin_4->value() != 0){
            pointsleft_ = pointsleft_+ ui->rogueSkillSpin_4->value()-1;
            ui->rogueSkillSpin_4->setValue(0);
        }if (ui->rogueSkillSpin_8->value() != 0){
            pointsleft_ = pointsleft_+ ui->rogueSkillSpin_8->value()-1;
            ui->rogueSkillSpin_8->setValue(0);
        }


    }   //EKAN rogue HAARAN LOPPU

    //TOINEN rogue HAARA
    if(ui->rogueSkillSpin_5->value()>= 1 &&
            ui->rogueSkillSpin_5->value()+ ui->rogueSkillSpin_1->value() +ui->rogueSkillSpin_9->value() >= 5 ){
        ui->rogueSkillSpin_6->setEnabled(true);

    }else{
        ui->rogueSkillSpin_6->setEnabled(false);
        if (ui->rogueSkillSpin_6->value() != 0){
                    pointsleft_ = pointsleft_+ ui->rogueSkillSpin_6->value()-1;
                    ui->rogueSkillSpin_6->setValue(0);
                }
    }
    if(ui->rogueSkillSpin_6->value() >= 1 &&
         ui->rogueSkillSpin_5->value() + ui->rogueSkillSpin_1->value() +ui->rogueSkillSpin_9->value()+
        ui->rogueSkillSpin_2->value()  + ui->rogueSkillSpin_6->value() + ui->rogueSkillSpin_10->value()  >= 10 ){

        ui->rogueSkillSpin_7->setEnabled(true);

    }else{
        ui->rogueSkillSpin_7->setEnabled(false);
        if ( ui->rogueSkillSpin_7->value() != 0){
            pointsleft_ = pointsleft_+ ui->rogueSkillSpin_7->value()-1;
            ui->rogueSkillSpin_7->setValue(0);
        }
    }


    if(ui->rogueSkillSpin_9->value()>= 1 &&
            ui->rogueSkillSpin_5->value()+ ui->rogueSkillSpin_1->value() +ui->rogueSkillSpin_9->value() >= 5 ){
        ui->rogueSkillSpin_10->setEnabled(true);
    }else{
        ui->rogueSkillSpin_10->setEnabled(false);
        pointsleft_ = pointsleft_+ ui->rogueSkillSpin_10->value();
        ui->rogueSkillSpin_10->setValue(0);
    }if(ui->rogueSkillSpin_10->value() >= 1 &&
            ui->rogueSkillSpin_5->value() + ui->rogueSkillSpin_1->value() + ui->rogueSkillSpin_9->value()+
           ui->rogueSkillSpin_2->value()  + ui->rogueSkillSpin_6->value() + ui->rogueSkillSpin_10->value()  >= 10 ){

           ui->rogueSkillSpin_11->setEnabled(true);

       }else{
        ui->rogueSkillSpin_11->setEnabled(false);
        if (ui->rogueSkillSpin_11->value() != 0){
            pointsleft_ = pointsleft_+ ui->rogueSkillSpin_11->value()-1;
            ui->rogueSkillSpin_11->setValue(0);
        }
       } //LINKKAUS rogue VIKAAN SKILLIIN
    if(ui->rogueSkillSpin_7->value() >= 1 && ui->rogueSkillSpin_11->value() >= 1 &&
            ui->rogueSkillSpin_5->value()+ ui->rogueSkillSpin_1->value() +ui->rogueSkillSpin_9->value()+
         ui->rogueSkillSpin_2->value() + ui->rogueSkillSpin_6->value()+ ui->rogueSkillSpin_10->value() +
         ui->rogueSkillSpin_3->value()+ ui->rogueSkillSpin_7->value()+ ui->rogueSkillSpin_11->value() >= 15){
        ui->rogueSkillSpin_12->setEnabled(true);
}else{
        ui->rogueSkillSpin_12->setEnabled(false);
        if (ui->rogueSkillSpin_12->value() != 0){
            pointsleft_ = pointsleft_+ ui->rogueSkillSpin_12->value()-1;
            ui->rogueSkillSpin_12->setValue(0);
        }
}

    usedPoints_ = calculateMSkills() + calculateRSkills() + calculateWSkills();
    ui->textBrowser->setText(QString::number(pointsleft_));
    return true;
}
void skilltree::alustaValuet()
{

    ui->mageSkillSpin_1->setValue(soturi->getMageSkills().at(0));
    ui->mageSkillSpin_2->setValue(soturi->getMageSkills().at(1));
    ui->mageSkillSpin_3->setValue(soturi->getMageSkills().at(2));
    ui->mageSkillSpin_4->setValue(soturi->getMageSkills().at(3));
    ui->mageSkillSpin_5->setValue(soturi->getMageSkills().at(4));
    ui->mageSkillSpin_6->setValue(soturi->getMageSkills().at(5));
    ui->mageSkillSpin_7->setValue(soturi->getMageSkills().at(6));
    ui->mageSkillSpin_8->setValue(soturi->getMageSkills().at(7));
    ui->mageSkillSpin_9->setValue(soturi->getMageSkills().at(8));
    ui->mageSkillSpin_10->setValue(soturi->getMageSkills().at(9));
    ui->mageSkillSpin_11->setValue(soturi->getMageSkills().at(10));
    ui->mageSkillSpin_12->setValue(soturi->getMageSkills().at(11));


    ui->warrSkillSpin_1->setValue(soturi->getWarrSkills().at(0));
    ui->warrSkillSpin_2->setValue(soturi->getWarrSkills().at(1));
    ui->warrSkillSpin_3->setValue(soturi->getWarrSkills().at(2));
    ui->warrSkillSpin_4->setValue(soturi->getWarrSkills().at(3));
    ui->warrSkillSpin_5->setValue(soturi->getWarrSkills().at(4));
    ui->warrSkillSpin_6->setValue(soturi->getWarrSkills().at(5));
    ui->warrSkillSpin_7->setValue(soturi->getWarrSkills().at(6));
    ui->warrSkillSpin_8->setValue(soturi->getWarrSkills().at(7));
    ui->warrSkillSpin_9->setValue(soturi->getWarrSkills().at(8));
    ui->warrSkillSpin_10->setValue(soturi->getWarrSkills().at(9));
    ui->warrSkillSpin_11->setValue(soturi->getWarrSkills().at(10));
    ui->warrSkillSpin_12->setValue(soturi->getWarrSkills().at(11));

    ui->rogueSkillSpin_1->setValue(soturi->getRogueSkills().at(0));
    ui->rogueSkillSpin_2->setValue(soturi->getRogueSkills().at(1));
    ui->rogueSkillSpin_3->setValue(soturi->getRogueSkills().at(2));
    ui->rogueSkillSpin_4->setValue(soturi->getRogueSkills().at(3));
    ui->rogueSkillSpin_5->setValue(soturi->getRogueSkills().at(4));
    ui->rogueSkillSpin_6->setValue(soturi->getRogueSkills().at(5));
    ui->rogueSkillSpin_7->setValue(soturi->getRogueSkills().at(6));
    ui->rogueSkillSpin_8->setValue(soturi->getRogueSkills().at(7));
    ui->rogueSkillSpin_9->setValue(soturi->getRogueSkills().at(8));
    ui->rogueSkillSpin_10->setValue(soturi->getRogueSkills().at(9));
    ui->rogueSkillSpin_11->setValue(soturi->getRogueSkills().at(10));
    ui->rogueSkillSpin_12->setValue(soturi->getRogueSkills().at(11));
}

void skilltree::on_doneBtn_clicked()
{
    QVector<int> wSkills;
    wSkills.push_back(ui->warrSkillSpin_1->value());
    wSkills.push_back(ui->warrSkillSpin_2->value());
    wSkills.push_back(ui->warrSkillSpin_3->value());
    wSkills.push_back(ui->warrSkillSpin_4->value());
    wSkills.push_back(ui->warrSkillSpin_5->value());
    wSkills.push_back(ui->warrSkillSpin_6->value());
    wSkills.push_back(ui->warrSkillSpin_7->value());
    wSkills.push_back(ui->warrSkillSpin_8->value());
    wSkills.push_back(ui->warrSkillSpin_9->value());
    wSkills.push_back(ui->warrSkillSpin_10->value());
    wSkills.push_back(ui->warrSkillSpin_11->value());
    wSkills.push_back(ui->warrSkillSpin_12->value());
    soturi->setWarrSkills(wSkills);
    wSkills.clear();
    wSkills.push_back(ui->rogueSkillSpin_1->value());
    wSkills.push_back(ui->rogueSkillSpin_2->value());
    wSkills.push_back(ui->rogueSkillSpin_3->value());
    wSkills.push_back(ui->rogueSkillSpin_4->value());
    wSkills.push_back(ui->rogueSkillSpin_5->value());
    wSkills.push_back(ui->rogueSkillSpin_6->value());
    wSkills.push_back(ui->rogueSkillSpin_7->value());
    wSkills.push_back(ui->rogueSkillSpin_8->value());
    wSkills.push_back(ui->rogueSkillSpin_9->value());
    wSkills.push_back(ui->rogueSkillSpin_10->value());
    wSkills.push_back(ui->rogueSkillSpin_11->value());
    wSkills.push_back(ui->rogueSkillSpin_12->value());

    soturi->setRogueSkills(wSkills);

    wSkills.clear();
    wSkills.push_back(ui->mageSkillSpin_1->value());
    wSkills.push_back(ui->mageSkillSpin_2->value());
    wSkills.push_back(ui->mageSkillSpin_3->value());
    wSkills.push_back(ui->mageSkillSpin_4->value());
    wSkills.push_back(ui->mageSkillSpin_5->value());
    wSkills.push_back(ui->mageSkillSpin_6->value());
    wSkills.push_back(ui->mageSkillSpin_7->value());
    wSkills.push_back(ui->mageSkillSpin_8->value());
    wSkills.push_back(ui->mageSkillSpin_9->value());
    wSkills.push_back(ui->mageSkillSpin_10->value());
    wSkills.push_back(ui->mageSkillSpin_11->value());
    wSkills.push_back(ui->mageSkillSpin_12->value());

    soturi->setMageSkills(wSkills);

    soturi->setUnusedSP(pointsleft_);



    if ((ui->warrSkillSpin_1->value() - soturi->gethitbonus()) > 0) {
         soturi->setHitrate(soturi->getHitrate()+((ui->warrSkillSpin_1->value() - soturi->gethitbonus())*3));

     }
    else if ((ui->warrSkillSpin_1->value() - soturi->gethitbonus()) < 0 ){
        int vahennys = (soturi->gethitbonus() - ui->warrSkillSpin_1->value());
         soturi->setHitrate(soturi->getHitrate()-(vahennys*3));
    }
    if (ui->warrSkillSpin_1->value() >= 0){
            soturi->sethitbonus(ui->warrSkillSpin_1->value());
    }



    if ((ui->warrSkillSpin_5->value() - soturi->gethpbonus()) > 0) {
         soturi->setMaxHp(soturi->getMaxHp()+(ui->warrSkillSpin_5->value()*10));

    }
    else if ((ui->warrSkillSpin_5->value() - soturi->gethpbonus()) < 0 ){
        int vahennys = (soturi->gethpbonus() - ui->warrSkillSpin_5->value());
         soturi->setMaxHp(soturi->getMaxHp()-(vahennys*10));
    }
    if (ui->warrSkillSpin_5->value() >= 0){
            soturi->sethpbonus(ui->warrSkillSpin_5->value());
    }


    if ((ui->warrSkillSpin_10->value() - soturi->getstrbonus()) > 0) {
         soturi->setStr(soturi->getStr()+((ui->warrSkillSpin_10->value() - soturi->getstrbonus())*2));

     }
    else if ((ui->warrSkillSpin_10->value() - soturi->getstrbonus()) < 0 ){
        int vahennys = (soturi->getstrbonus() - ui->warrSkillSpin_10->value());
         soturi->setStr(soturi->getStr()-(vahennys*2));
    }
    if (ui->warrSkillSpin_10->value() >= 0){
            soturi->setstrbonus(ui->warrSkillSpin_10->value());
    }


    this->close();
}


void skilltree::on_warrSkillSpin_5_valueChanged()
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_5->setValue(ui->warrSkillSpin_5->value()-1);
    }
}

void skilltree::on_warrSkillSpin_9_valueChanged( )
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_9->setValue(ui->warrSkillSpin_9->value()-1);
    }

}

void skilltree::on_mageBtn_clicked()
{
    ui->magebox->setVisible(true);
    ui->rogueBox->setVisible(false);
    ui->warrBox->setVisible(false);
}

void skilltree::on_warrBtn_clicked()
{

    ui->magebox->setVisible(false);
    ui->rogueBox->setVisible(false);
    ui->warrBox->setVisible(true);
}

void skilltree::on_rogueBtn_clicked()
{

    ui->magebox->setVisible(false);
    ui->rogueBox->setVisible(true);
    ui->warrBox->setVisible(false);
}

void skilltree::on_warrSkillSpin_2_valueChanged(const QString &)
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_2->setValue(ui->warrSkillSpin_2->value()-1);
    }
}

void skilltree::on_warrSkillSpin_6_valueChanged( )
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_6->setValue(ui->warrSkillSpin_6->value()-1);
    }
}

void skilltree::on_warrSkillSpin_10_valueChanged( )
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_10->setValue(ui->warrSkillSpin_10->value()-1);
    }

}

void skilltree::on_warrSkillSpin_3_valueChanged( )
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_3->setValue(ui->warrSkillSpin_3->value()-1);
    }
}

void skilltree::on_warrSkillSpin_7_valueChanged( )
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_7->setValue(ui->warrSkillSpin_7->value()-1);
    }
}

void skilltree::on_warrSkillSpin_11_valueChanged( )
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_11->setValue(ui->warrSkillSpin_11->value()-1);
    }
}

void skilltree::on_warrSkillSpin_1_valueChanged( )
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_1->setValue(ui->warrSkillSpin_1->value()-1);
    }
}

void skilltree::on_warrSkillSpin_4_valueChanged( )
{
    if (!warrValueChanged()){
        ui->warrSkillSpin_4->setValue(ui->warrSkillSpin_4->value()-1);
    }

}

void skilltree::on_warrSkillSpin_8_valueChanged( )
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_8->setValue(ui->warrSkillSpin_8->value()-1);
    }
}

void skilltree::on_warrSkillSpin_12_valueChanged( )
{

    if (!warrValueChanged()){
        ui->warrSkillSpin_12->setValue(ui->warrSkillSpin_12->value()-1);
    }
}

void skilltree::on_mageSkillSpin_1_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_1->setValue(ui->mageSkillSpin_1->value()-1);
    }
}

void skilltree::on_mageSkillSpin_2_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_2->setValue(ui->mageSkillSpin_2->value()-1);
    }
}

void skilltree::on_mageSkillSpin_3_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_3->setValue(ui->mageSkillSpin_3->value()-1);
    }
}

void skilltree::on_mageSkillSpin_4_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_4->setValue(ui->mageSkillSpin_4->value()-1);
    }
}

void skilltree::on_mageSkillSpin_5_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_5->setValue(ui->mageSkillSpin_5->value()-1);
    }
}

void skilltree::on_mageSkillSpin_6_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_6->setValue(ui->mageSkillSpin_6->value()-1);
    }
}

void skilltree::on_mageSkillSpin_7_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_7->setValue(ui->mageSkillSpin_7->value()-1);
    }
}

void skilltree::on_mageSkillSpin_8_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_8->setValue(ui->mageSkillSpin_8->value()-1);
    }
}

void skilltree::on_mageSkillSpin_9_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_9->setValue(ui->mageSkillSpin_9->value()-1);
    }
}

void skilltree::on_mageSkillSpin_10_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_10->setValue(ui->mageSkillSpin_10->value()-1);
    }
}

void skilltree::on_mageSkillSpin_11_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_11->setValue(ui->mageSkillSpin_11->value()-1);
    }
}

void skilltree::on_mageSkillSpin_12_valueChanged( )
{

    if (!mageValueChanged()){
        ui->mageSkillSpin_12->setValue(ui->mageSkillSpin_12->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_1_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_1->setValue(ui->rogueSkillSpin_1->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_2_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_2->setValue(ui->rogueSkillSpin_2->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_3_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_3->setValue(ui->rogueSkillSpin_3->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_4_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_4->setValue(ui->rogueSkillSpin_4->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_5_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_5->setValue(ui->rogueSkillSpin_5->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_6_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_6->setValue(ui->rogueSkillSpin_6->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_7_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_7->setValue(ui->rogueSkillSpin_7->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_8_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_8->setValue(ui->rogueSkillSpin_8->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_9_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_9->setValue(ui->rogueSkillSpin_9->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_10_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_10->setValue(ui->rogueSkillSpin_10->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_11_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_11->setValue(ui->rogueSkillSpin_11->value()-1);
    }
}

void skilltree::on_rogueSkillSpin_12_valueChanged( )
{

    if (!rogueValueChanged()){
        ui->rogueSkillSpin_12->setValue(ui->rogueSkillSpin_12->value()-1);
    }
}

void skilltree::on_pushButton_clicked()
{


    ui->mageSkillSpin_12->setValue(0);
    ui->mageSkillSpin_11->setValue(0);
    ui->mageSkillSpin_10->setValue(0);
    ui->mageSkillSpin_9->setValue(0);
    ui->mageSkillSpin_8->setValue(0);
    ui->mageSkillSpin_7->setValue(0);
    ui->mageSkillSpin_6->setValue(0);
    ui->mageSkillSpin_5->setValue(0);
    ui->mageSkillSpin_4->setValue(0);
    ui->mageSkillSpin_3->setValue(0);
    ui->mageSkillSpin_2->setValue(0);
    ui->mageSkillSpin_1->setValue(0);

    ui->warrSkillSpin_12->setValue(0);
    ui->warrSkillSpin_11->setValue(0);
    ui->warrSkillSpin_10->setValue(0);
    ui->warrSkillSpin_9->setValue(0);
    ui->warrSkillSpin_8->setValue(0);
    ui->warrSkillSpin_7->setValue(0);
    ui->warrSkillSpin_6->setValue(0);
    ui->warrSkillSpin_5->setValue(0);
    ui->warrSkillSpin_4->setValue(0);
    ui->warrSkillSpin_3->setValue(0);
    ui->warrSkillSpin_2->setValue(0);
    ui->warrSkillSpin_1->setValue(0);

    ui->rogueSkillSpin_12->setValue(0);
    ui->rogueSkillSpin_11->setValue(0);
    ui->rogueSkillSpin_10->setValue(0);
    ui->rogueSkillSpin_9->setValue(0);
    ui->rogueSkillSpin_8->setValue(0);
    ui->rogueSkillSpin_7->setValue(0);
    ui->rogueSkillSpin_6->setValue(0);
    ui->rogueSkillSpin_5->setValue(0);
    ui->rogueSkillSpin_4->setValue(0);
    ui->rogueSkillSpin_3->setValue(0);
    ui->rogueSkillSpin_2->setValue(0);
    ui->rogueSkillSpin_1->setValue(0);

    ui->warrSkillSpin_1->setMinimum(0);
    ui->warrSkillSpin_2->setMinimum(0);
    ui->warrSkillSpin_3->setMinimum(0);
    ui->warrSkillSpin_4->setMinimum(0);
    ui->warrSkillSpin_5->setMinimum(0);
    ui->warrSkillSpin_6->setMinimum(0);
    ui->warrSkillSpin_7->setMinimum(0);
    ui->warrSkillSpin_8->setMinimum(0);
    ui->warrSkillSpin_9->setMinimum(0);
    ui->warrSkillSpin_10->setMinimum(0);
    ui->warrSkillSpin_11->setMinimum(0);
    ui->warrSkillSpin_12->setMinimum(0);

    ui->rogueSkillSpin_1->setMinimum(0);
    ui->rogueSkillSpin_2->setMinimum(0);
    ui->rogueSkillSpin_3->setMinimum(0);
    ui->rogueSkillSpin_4->setMinimum(0);
    ui->rogueSkillSpin_5->setMinimum(0);
    ui->rogueSkillSpin_6->setMinimum(0);
    ui->rogueSkillSpin_7->setMinimum(0);
    ui->rogueSkillSpin_8->setMinimum(0);
    ui->rogueSkillSpin_9->setMinimum(0);
    ui->rogueSkillSpin_10->setMinimum(0);
    ui->rogueSkillSpin_11->setMinimum(0);
    ui->rogueSkillSpin_12->setMinimum(0);

    ui->mageSkillSpin_1->setMinimum(0);
    ui->mageSkillSpin_2->setMinimum(0);
    ui->mageSkillSpin_3->setMinimum(0);
    ui->mageSkillSpin_4->setMinimum(0);
    ui->mageSkillSpin_5->setMinimum(0);
    ui->mageSkillSpin_6->setMinimum(0);
    ui->mageSkillSpin_7->setMinimum(0);
    ui->mageSkillSpin_8->setMinimum(0);
    ui->mageSkillSpin_9->setMinimum(0);
    ui->mageSkillSpin_10->setMinimum(0);
    ui->mageSkillSpin_11->setMinimum(0);
    ui->mageSkillSpin_12->setMinimum(0);

    pointsleft_ = totalPoints_;
    ui->textBrowser->setText(QString::number(pointsleft_));
}
