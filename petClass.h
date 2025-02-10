#pragma once
#include "extendClass.h"
class AttackCapable {
public:
    void capability();
    void capability(Warrior &p1);
    void capability(NatureMage &p1);
    void capability(Warrior &p1,NatureMage &p2);
    void capability(Warrior &p1, NatureMage& p2, Warrior &empty);
};
class pet001 :AttackCapable {
public:
    void capability(Warrior &empty){//扣除敌人随机的能量
        int energy = rand() % 101;
        empty.increaseEnergy(-energy);
        cout << "下回合将扣除敌人" << energy << "点能量" << endl;
    }
};
class pet002 :AttackCapable {//给队友回10*x血回10*x能(x为发动次数)
public:
    void capability(Warrior& p1,NatureMage &p2){
        static int num = 20;
        num += 10;
        p2.increaseEnergy(num);
        p1.increaseEnergy(num);
        p1.increaseHealth(num);
        p2.increaseHealth(num);
        cout << "全队恢复了" << num << "点能量和血量" << endl;
    }
};
class pet003 :AttackCapable {//随机对场上的一个目标造成随机的伤害(0-200)
public:
    void capability(Warrior& p1, NatureMage& p2, Warrior& empty){
        cout << "神罚降至" << endl;
        int mark = rand() % 3 + 1;
        int  damge2 = rand() % 200;
        if (mark == 1) { p1.suffer(damge2); cout << "勇者受到了" << damge2 << "点伤害"<<endl; }
        else if (mark == 2) { p2.suffer(damge2); cout << "魔法师受到了" << damge2 <<"点伤害"<< endl; }
        else if (mark == 3) { empty.suffer(damge2); cout << "贝利亚受到了" << damge2 << "点伤害" << endl; }
    }
};