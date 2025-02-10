#pragma once
#include"teamClass.h"
#include <iostream>
#include <cstdio>
void startMeau() {
	cout << "按任意键继续" << endl;
	getchar();
	cout << "你好,勇者" << endl;
	getchar();
	cout << "就像许多故事中那样公主被抓走了" << endl;
	cout << "但不同的是抓走公主的不是恶龙而是........." << endl;
	getchar();
	cout << "贝利亚大人!!!" << endl;
	getchar();
	cout << "当然你并不是孤单一人,与你同行的还有一名魔法师和你的宠物" << endl;
	getchar();
	system("cls");
}
void dMeau() {
	cout << "在你心中贝利亚大人的实力应该是?" << endl;
	cout << "1.ezez" << endl;
	cout << "2.有点恐怖" << endl;
	cout << "3.光之国最大的敌人" << endl;
}
void petMeau() {
	cout << "在你的记忆中这只宠物是 ?" << endl;
	cout << "1.制造机会的陷阱大师(能力:扣除敌人随机的能量(0-100))"<< endl;
	cout << "2.令人治愈的可爱小猫(能力:给队友回10*x血回10*x能(x为发动次数))"<< endl;
	cout << "3.不分敌我的乱世魔王(能力:随机对场上的一个目标造成随机的伤害(0-200))"<< endl;
}
void baseMeau(Warrior& p1, NatureMage& p2, Warrior& empty) {
	cout << "勇者  :健康:" << p1.getHealth() <<" 能量:"<< p1.getEnergy() <<endl;
	cout << "魔法师:健康:" <<p2.getHealth() << " 能量:" <<p2.getEnergy() << endl;
	cout << "贝利亚:健康:" << empty.getHealth() << " 能量:" <<empty.getEnergy() << endl;
}
bool checkEnd(Warrior &p1,NatureMage &p2, Warrior &empty) {
	if (p1.getHealth() <= 0 && p2.getHealth() <= 0) return false;
	else if (empty.getHealth() <= 0) return false;
	return true;
}
void playerMeau() {
	cout << "1.勇者         2.魔术师           3.释放宠物" << endl;
}
void petMeau(int choic) {
	if (choic == 1)cout << "宠物技能:扣除敌人随机的能量" << endl;
	if (choic == 2)cout << "宠物技能:给队友回10*x血回10*x能(x为发动次数)" << endl;
	if (choic == 3)cout << "宠物技能:随机对场上的一个目标造成随机的伤害" << endl;
}
void warriorMeau() {
	cout << "勇者" << endl << "1.技能一:扣除自身10滴血 增加自身暴率和爆伤" << endl << "2.技能二:扣除自身10滴血  对敌人造成伤害" <<endl<< "3.最终技能:对敌人造成基于以损生命值的伤害" << endl;
}
void natureMeau() {
	cout << "魔术师" << endl << "1.技能一:扣除10点能量 恢复队友血量" << endl << "2.技能二:扣除10点能量  自身回血增伤" <<endl<< "3.最终技能:对敌人造成大量伤害并基于造成的伤害获得能量" << endl;
}
void loseMeau() {
	cout << "贝利亚终究是不能战胜的吗........" << endl;
	cout << "快去请奶龙大人....." << endl;
	getchar();
	cout << "你输了" << endl;
}
void winMeau() {
	cout << "恭喜你战胜了那位大人救出了公主" << endl;
	cout << "但是......." << endl;
	getchar();
	cout << "真的赢了吗?" << endl;
}