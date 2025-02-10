//Team类越写错误越多最后没有使用
#pragma once
#include "extendClass.h"
#include "petClass.h"

class Team {
public:
	Team(Warrior& p1, NatureMage& p2,Warrior &empty ):p1(0, 0, 0, 0, 0), p2(0, 0, 0, 0),empty(0,0,0,0,0) {
		this->p1 = p1;
		this->p2 = p2;
		this->empty = empty;
	}
	double getWarrior()
	{
		return p1.getHealth();
	}
	double getNature()
	{
		return p2.getHealth();
	}
	Warrior p1;
	Warrior empty;
	NatureMage p2;
	pet001 pet1;
	pet002 pet2;
	pet003 pet3;
};
