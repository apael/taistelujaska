#ifndef SAVE_H
#define SAVE_H

#include <QWidget>
#include"hahmo.h"
#include"funktiot.h"
#include"item.h"
#include"math.h"
#include "QFile"



namespace Ui {
class save;
}

class save : public QWidget
{
    Q_OBJECT

public:
    explicit save(hahmo *taistelija, hahmo *enemy, QWidget *parent = 0 );
    ~save();


    void load(int slot);
    void set_slot2();

    void set_slot1();
    void load_1();
public slots:

signals:
    void returnmenu();
private slots:
    void on_cancel_btn_clicked();

    void on_slot_1_clicked();

    void on_slot_2_clicked();

    void on_del_sav_clicked();

private:
    Ui::save *ui;
    hahmo *soturi;
    item *kirves;
    hahmo *vihu;
    item *haarniska;

};

#endif // SAVE_H
