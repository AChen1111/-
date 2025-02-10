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
    void capability(Warrior &empty){//�۳��������������
        int energy = rand() % 101;
        empty.increaseEnergy(-energy);
        cout << "�»غϽ��۳�����" << energy << "������" << endl;
    }
};
class pet002 :AttackCapable {//�����ѻ�10*xѪ��10*x��(xΪ��������)
public:
    void capability(Warrior& p1,NatureMage &p2){
        static int num = 20;
        num += 10;
        p2.increaseEnergy(num);
        p1.increaseEnergy(num);
        p1.increaseHealth(num);
        p2.increaseHealth(num);
        cout << "ȫ�ӻָ���" << num << "��������Ѫ��" << endl;
    }
};
class pet003 :AttackCapable {//����Գ��ϵ�һ��Ŀ�����������˺�(0-200)
public:
    void capability(Warrior& p1, NatureMage& p2, Warrior& empty){
        cout << "�񷣽���" << endl;
        int mark = rand() % 3 + 1;
        int  damge2 = rand() % 200;
        if (mark == 1) { p1.suffer(damge2); cout << "�����ܵ���" << damge2 << "���˺�"<<endl; }
        else if (mark == 2) { p2.suffer(damge2); cout << "ħ��ʦ�ܵ���" << damge2 <<"���˺�"<< endl; }
        else if (mark == 3) { empty.suffer(damge2); cout << "�������ܵ���" << damge2 << "���˺�" << endl; }
    }
};