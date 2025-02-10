
#include <iostream>
#include <ctime>
#include<cstdlib>
#include "extendClass.h"
#include "petClass.h"
#include "meau.h"

using namespace std;

int main()
{
	startMeau();
	Warrior p1(100, 100, 10, 10, 1);
	NatureMage p2(80, 50, 40, 20);
	Warrior empty(200,60,30,20,2);

	pet001 pet1;
	pet002 pet2;
	pet003 pet3;

	dMeau();

	int choic = 0;//难度选择项
	cin >> choic;

	if (choic == 1) {}
	if (choic == 2) { empty.increaseHealth(100); empty.increaseEnergy(10); empty.increaseCritDamage(10); }
	if (choic == 3) { empty.increaseHealth(100);  empty.increaseEnergy(50); empty.increaseCritDamage(10); empty.increaseCritChance(15); }

	system("cls");

	petMeau();
	int choic2 = 0;//宠物选择项
	cin >> choic2;

	system("cls");
	cout << "现在开始你的冒险吧" << endl;
	getchar();

	while (checkEnd(p1,p2, empty))
	{
		srand(time(0));

		static int num = 0;//回合数
		num++;

		getchar();
		getchar();
		system("cls");

		cout << "当前状态:" << endl;
		baseMeau(p1, p2, empty);

		getchar();
		getchar();
		system("cls");

		cout << "敌人的回合" << endl;
		int mark = rand() % 2 + 1;
		int mark2 = rand() % 2 + 1;

		if (empty.getEnergy() >= 100) {
			empty.emptyEnergy();
			double harm = 50+2*rand()%100+empty.finalDamage();
			if (mark == 1) {
				cout << "勇者受到了" << harm << "点伤害" << endl;
				p1.suffer(harm);
			}
			else {
				cout << "魔法师受到了" << harm << "点伤害" << endl;
				p2.suffer(harm);
			}
		}
		else
		{
			double harm = empty.skillTwo();
			if (mark == 1) {
				cout << "勇者受到了" << harm << "点伤害" << endl;
				p1.suffer(harm);
			}
			else {
				cout << "魔法师受到了" << harm << "点伤害" << endl;
				p2.suffer(harm);
			}

			double harm1 = empty.skillTwo()+rand() % 30;
			if (mark2 == 1) {
				cout << "勇者受到了" << harm1 << "点伤害" << endl;
				p1.suffer(harm1);
			}
			else {
				cout << "魔法师受到了" << harm1 << "点伤害" << endl;
				p2.suffer(harm1);
			}


		}

		getchar();
		system("cls");

		cout << "当前状态:" << endl;
		baseMeau(p1, p2, empty);

		getchar();
		getchar();
		system("cls");

		cout << "第" << num << "回合" << endl;

		int turn = 2;//行动点数
		while (turn > 0)
		{
			cout << "你还能行动" << turn << "次" << endl;
			cout << "请选择操作的角色" << endl;
			playerMeau();

			int choice = 0;
			cin >> choice;

			if (choice == 1)
			{
				if (p1.getHealth() > 0)
				{
					cout << "请选择技能释放" << endl;
					warriorMeau();
					int skillNum = 0;
					cin >> skillNum;
					if (skillNum == 1)
					{
						p1.skillOne();
						cout << "勇者的暴击率和暴击伤害增加了" << endl;
						turn--;
					}

					else if (skillNum == 2)
					{
						double dramge1 = p1.skillTwo();
						cout << "对敌人造成了" << dramge1 << "点伤害" << endl;
						empty.suffer(dramge1);
						turn--;
					}
					else if (skillNum == 3)
					{
						if (p1.getEnergy() >= 100)
						{
							p1.emptyEnergy();
							double dramge1 = p1.ultimateSkill();
							cout << "对敌人造成了" << dramge1 << "点伤害" << endl;
							empty.suffer(dramge1);
							turn--;
						}
						else
						{
							printf("能量不足\n");
						}

					}
				}
				else
				{
					printf("勇者已经阵亡请重选\n");
				}

			}
			if (choice == 2)
			{
				cout << "请选择技能释放" << endl;
				natureMeau();
				if (p2.getHealth() >= 0&&p2.getEnergy() >= 10)
				{
					int skillNum = 0;
					cin >> skillNum;
					if (skillNum == 1)
					{
						double help = p2.skillOne();
						cout << "勇者恢复了" << help << "点血量" << endl;
						p1.increaseHealth(help);
						turn--;
					}
					else if (skillNum == 2)
					{
						p2.skillTwo();
						cout << "魔术师强化了自身" << endl;
						turn--;
					}
					else if (skillNum == 3)
					{
						if (p2.getEnergy() >= 100 )
						{
							int harm = p2.ultimateSkill();
							turn -= 2;
							cout << "敌人受到了" << harm << "点伤害" << endl;
							empty.suffer(harm);
						}
						else
						{
							cout << "能量不足\n";
						}
					}

				}
				else
				{
					printf("魔术师无法选择请重选\n");
				}
			}
			if (choice == 3)
			{
				if (choic2 == 1) { pet1.capability(empty); turn--; }
				if (choic2 == 2) {pet2.capability(p1, p2); turn--;}
				if (choic2 == 3) { pet3.capability(p1, p2, empty); turn -= 2; }
			}

		}
	}

	getchar();
	system("cls");

	if (empty.getHealth() <= 0) {
		winMeau();
	}
	else {
		loseMeau();
	}

	return 0;
}