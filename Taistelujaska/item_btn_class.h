#ifndef ITEM_BTN_CLASS_H
#define ITEM_BTN_CLASS_H
#include"QPushButton"
#include"QWidget"
#include"hahmo.h"
#include"item.h"
#include"newwindow.h"
#include"QLabel"
#include <stdio.h>


class item_btn_class : public QPushButton
{
    Q_OBJECT
public:
    item_btn_class();
    item_btn_class(QWidget *parent = 0);
   // ~item_btn_class();
void enterEvent(QEvent *event);
void leaveEvent(QEvent *event);
void sethahmo(hahmo *uusisoturi, item *uusiase, QLabel *uusiui);
void setskill(QLabel *uusiui, int numero);

private:
hahmo *soturi;
item *ase1;
QLabel *ui;
int hyokkays_nappi;
};

#endif // ITEM_BTN_CLASS_H
