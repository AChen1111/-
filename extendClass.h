#pragma once
#include "baseClass.h"
#include <iostream>

using namespace std;

class Warrior :public WarriorFighter
{
public:
    Warrior(double health, int energy, double damage, int critChance, double critDamage) :WarriorFighter(health, energy, damage, critChance, critDamage){}
    double skillOne() override//�۳�����10��Ѫ ���������ʺͱ���
    {
        suffer(10);
        increaseCritDamage(0.5);
        increaseCritChance(5);
        return 0;
    }
    double skillTwo() override//�۳�����10��Ѫ  �Ե�������˺�
    {
        suffer(10);
        return finalDamage();
    }
    double ultimateSkill() override//�Ե�����ɻ�����������ֵ���˺�
    {
        return finalDamage() * 2 + (100 - getHealth());
    }
};
class NatureMage :public MageFighter
{
public:
    NatureMage(double health, int energy, double HealPower, int MagicBoostBase) :MageFighter(health, energy, HealPower, MagicBoostBase) {}
    double skillOne()  override//�۳�10������ �ָ�����Ѫ��
    {
        increaseEnergy(-10);
        return getHealPower();
    }
    double skillTwo()  override//�۳�10������  �����Ѫ����
    {
        increaseEnergy(-10);
        increaseHealth(30);
        increaseMagicBoostBase(5);
        return 0;
    }
    double ultimateSkill()  override//�Ե�����ɴ����˺���������ɵ��˺��������
    {
        increaseEnergy(getMagicBoostBase() * 2);
        return getMagicBoostBase() * 2;
    }
};
