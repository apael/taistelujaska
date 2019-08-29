#ifndef SKILLTREE_H
#define SKILLTREE_H

#include <QWidget>
#include <hahmo.h>
namespace Ui {
class skilltree;
}

class skilltree : public QWidget
{
    Q_OBJECT

public:
    explicit skilltree(hahmo *sot,QWidget *parent = 0);
    ~skilltree();
    int calculateWSkills();
    int calculateMSkills();
    int calculateRSkills();
    bool warrValueChanged();
    bool mageValueChanged();
    bool rogueValueChanged();
    void alustaValuet();
private slots:
    void on_doneBtn_clicked();

   // void on_warrSkillSpin_valueChanged( );

    void on_warrSkillSpin_5_valueChanged();

    void on_warrSkillSpin_9_valueChanged( );

    void on_mageBtn_clicked();

    void on_warrBtn_clicked();

    void on_rogueBtn_clicked();

    void on_warrSkillSpin_2_valueChanged(const QString &arg1);

    void on_warrSkillSpin_6_valueChanged( );

    void on_warrSkillSpin_10_valueChanged( );

    void on_warrSkillSpin_3_valueChanged( );

    void on_warrSkillSpin_7_valueChanged( );

    void on_warrSkillSpin_11_valueChanged( );

    void on_warrSkillSpin_1_valueChanged( );

    void on_warrSkillSpin_4_valueChanged( );

    void on_warrSkillSpin_8_valueChanged( );

    void on_warrSkillSpin_12_valueChanged( );

    void on_mageSkillSpin_1_valueChanged( );

    void on_mageSkillSpin_2_valueChanged( );

    void on_mageSkillSpin_3_valueChanged( );

    void on_mageSkillSpin_4_valueChanged( );

    void on_mageSkillSpin_5_valueChanged( );

    void on_mageSkillSpin_6_valueChanged( );

    void on_mageSkillSpin_7_valueChanged( );

    void on_mageSkillSpin_8_valueChanged( );

    void on_mageSkillSpin_9_valueChanged( );

    void on_mageSkillSpin_10_valueChanged( );

    void on_mageSkillSpin_11_valueChanged( );

    void on_mageSkillSpin_12_valueChanged( );

    void on_rogueSkillSpin_1_valueChanged( );

    void on_rogueSkillSpin_2_valueChanged( );

    void on_rogueSkillSpin_3_valueChanged( );

    void on_rogueSkillSpin_4_valueChanged( );

    void on_rogueSkillSpin_5_valueChanged( );

    void on_rogueSkillSpin_6_valueChanged( );

    void on_rogueSkillSpin_7_valueChanged( );

    void on_rogueSkillSpin_8_valueChanged( );

    void on_rogueSkillSpin_9_valueChanged( );

    void on_rogueSkillSpin_10_valueChanged( );

    void on_rogueSkillSpin_11_valueChanged( );

    void on_rogueSkillSpin_12_valueChanged( );

    void on_pushButton_clicked();

private:
    Ui::skilltree *ui;
    hahmo* soturi;
    int pointsleft_;
    int totalPoints_;
    int usedPoints_;
};

#endif // SKILLTREE_H
