#pragma once
#include "baseClass.h"
#include <iostream>

using namespace std;

class Warrior :public WarriorFighter
{
public:
    Warrior(double health, int energy, double damage, int critChance, double critDamage) :WarriorFighter(health, energy, damage, critChance, critDamage){}
    double skillOne() override//扣除自身10滴血 增加自身暴率和爆伤
    {
        suffer(10);
        increaseCritDamage(0.5);
        increaseCritChance(5);
        return 0;
    }
    double skillTwo() override//扣除自身10滴血  对敌人造成伤害
    {
        suffer(10);
        return finalDamage();
    }
    double ultimateSkill() override//对敌人造成基于以损生命值的伤害
    {
        return finalDamage() * 2 + (100 - getHealth());
    }
};
class NatureMage :public MageFighter
{
public:
    NatureMage(double health, int energy, double HealPower, int MagicBoostBase) :MageFighter(health, energy, HealPower, MagicBoostBase) {}
    double skillOne()  override//扣除10点能量 恢复队友血量
    {
        increaseEnergy(-10);
        return getHealPower();
    }
    double skillTwo()  override//扣除10点能量  自身回血增伤
    {
        increaseEnergy(-10);
        increaseHealth(30);
        increaseMagicBoostBase(5);
        return 0;
    }
    double ultimateSkill()  override//对敌人造成大量伤害并基于造成的伤害获得能量
    {
        increaseEnergy(getMagicBoostBase() * 2);
        return getMagicBoostBase() * 2;
    }
};
