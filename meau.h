#pragma once
#include"teamClass.h"
#include <iostream>
#include <cstdio>
void startMeau() {
	cout << "�����������" << endl;
	getchar();
	cout << "���,����" << endl;
	getchar();
	cout << "����������������������ץ����" << endl;
	cout << "����ͬ����ץ�߹����Ĳ��Ƕ�������........." << endl;
	getchar();
	cout << "�����Ǵ���!!!" << endl;
	getchar();
	cout << "��Ȼ�㲢���ǹµ�һ��,����ͬ�еĻ���һ��ħ��ʦ����ĳ���" << endl;
	getchar();
	system("cls");
}
void dMeau() {
	cout << "�������б����Ǵ��˵�ʵ��Ӧ����?" << endl;
	cout << "1.ezez" << endl;
	cout << "2.�е�ֲ�" << endl;
	cout << "3.��֮�����ĵ���" << endl;
}
void petMeau() {
	cout << "����ļ�������ֻ������ ?" << endl;
	cout << "1.�������������ʦ(����:�۳��������������(0-100))"<< endl;
	cout << "2.���������Ŀɰ�Сè(����:�����ѻ�10*xѪ��10*x��(xΪ��������))"<< endl;
	cout << "3.���ֵ��ҵ�����ħ��(����:����Գ��ϵ�һ��Ŀ�����������˺�(0-200))"<< endl;
}
void baseMeau(Warrior& p1, NatureMage& p2, Warrior& empty) {
	cout << "����  :����:" << p1.getHealth() <<" ����:"<< p1.getEnergy() <<endl;
	cout << "ħ��ʦ:����:" <<p2.getHealth() << " ����:" <<p2.getEnergy() << endl;
	cout << "������:����:" << empty.getHealth() << " ����:" <<empty.getEnergy() << endl;
}
bool checkEnd(Warrior &p1,NatureMage &p2, Warrior &empty) {
	if (p1.getHealth() <= 0 && p2.getHealth() <= 0) return false;
	else if (empty.getHealth() <= 0) return false;
	return true;
}
void playerMeau() {
	cout << "1.����         2.ħ��ʦ           3.�ͷų���" << endl;
}
void petMeau(int choic) {
	if (choic == 1)cout << "���＼��:�۳��������������" << endl;
	if (choic == 2)cout << "���＼��:�����ѻ�10*xѪ��10*x��(xΪ��������)" << endl;
	if (choic == 3)cout << "���＼��:����Գ��ϵ�һ��Ŀ�����������˺�" << endl;
}
void warriorMeau() {
	cout << "����" << endl << "1.����һ:�۳�����10��Ѫ ���������ʺͱ���" << endl << "2.���ܶ�:�۳�����10��Ѫ  �Ե�������˺�" <<endl<< "3.���ռ���:�Ե�����ɻ�����������ֵ���˺�" << endl;
}
void natureMeau() {
	cout << "ħ��ʦ" << endl << "1.����һ:�۳�10������ �ָ�����Ѫ��" << endl << "2.���ܶ�:�۳�10������  �����Ѫ����" <<endl<< "3.���ռ���:�Ե�����ɴ����˺���������ɵ��˺��������" << endl;
}
void loseMeau() {
	cout << "�������վ��ǲ���սʤ����........" << endl;
	cout << "��ȥ����������....." << endl;
	getchar();
	cout << "������" << endl;
}
void winMeau() {
	cout << "��ϲ��սʤ����λ���˾ȳ��˹���" << endl;
	cout << "����......." << endl;
	getchar();
	cout << "���Ӯ����?" << endl;
}