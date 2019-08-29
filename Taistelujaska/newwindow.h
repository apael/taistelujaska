#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QWidget>
//#include "levelup.h"
#include"item.h"
#include"hahmo.h"

namespace Ui {
class newwindow;
}

class newwindow : public QWidget
{
    Q_OBJECT

public:
    explicit newwindow(hahmo *taistelija,QWidget *parent = 0);
    ~newwindow();
public slots:
    //void openareenalvlup();

    void printtaastatit();
signals:
    void returnmenu();

private slots:
    void on_item_btn_1_clicked();

    void on_return_btn_clicked();

    void on_item_btn_2_clicked();


    void current_item_kuva();
private:
    Ui::newwindow *ui;
    hahmo *soturi;
    item *uusiase;
    item *uusiase2;
    item *newwep;
    item *newarm;


};

#endif // NEWWINDOW_H
