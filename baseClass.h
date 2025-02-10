#pragma once
#include <ctime>
#include<cstdlib>
#include <iostream>
using namespace std;
class CoreFighter
{
public:
    CoreFighter(double health, int energy)
    {
        this->health = health;
        this->energy = energy;
    }

    double getHealth() const
    {
        return health;
    }

    int getEnergy() const
    {
        return energy;
    }

    virtual double skillOne() = 0;
    virtual double skillTwo() = 0;
    virtual double ultimateSkill() = 0;



    void increaseEnergy(int energy)
    {
        this->energy += energy;
    }


    void increaseHealth(double health)
    {
        this->health += health;
    }

        void suffer(double harm)//ÊÜÉËÅÐ¶¨
    {
        energy += harm;
        health -= harm;
    }

    void emptyEnergy()
    {
        energy -= 100;
    }
private:
    double health;
    int energy;
};

class MageFighter :public CoreFighter
{
public:
    MageFighter(double health, int energy, double HealPower, int MagicBoostBase) :CoreFighter(health, energy)
    {
        this->HealPower = HealPower;
        this->MagicBoostBase = MagicBoostBase;
    }

    double getHealPower() 
    {
        return HealPower;
    }

    int getMagicBoostBase() 
    {
        return MagicBoostBase;
    }

    void increaseMagicBoostBase(int MagicBoostBase)
    {
        this->MagicBoostBase += MagicBoostBase;
    }


private:
    double HealPower;
    int MagicBoostBase;
};

class WarriorFighter :public CoreFighter
{
public:
    WarriorFighter(double health, int energy, double damage, int critChance, double critDamage) :CoreFighter(health, energy)
    {
        this->damage = damage;
        this->critChance = critChance;
        this->critDamage = critDamage;
    }

    double getDamage()
    {
        return damage;
    }

    double getCritChance()
    {
        return critChance;
    }

    double getCritDamage() const
    {
        return (critDamage + 1) *damage;
    }

    void increaseDamage(double damage)
    {
        this->damage += damage;
    }

    void increaseCritChance(int critChance)
    {
        this->critChance += critChance;
    }

    void increaseCritDamage(double critDamage)
    {
        this->critDamage += critDamage;
    }

    double finalDamage()
    {
        srand(time(0));
        if (getCritChance() >= (rand() % 100))
        {
            return getCritDamage();
        }
        else
            return getDamage();
    }

private:
    double damage;
    int critChance;
    double critDamage;
};