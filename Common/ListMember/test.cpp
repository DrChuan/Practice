#include <iostream>
#include"ListMember.h"
using namespace std;
int main() {
	Hero hero;
	cout << "Ӣ�۳�ʼ����ֵΪ��"<<hero.getAtk() << endl;
	hero.setAtk(15);
	cout << "���ù���ֵΪ15" << endl;
	cout << "Ӣ�۹���ֵΪ��" << hero.getAtk() << endl;

	Enemy enemy(10,20,10,10);
	hero.fight(enemy);
	cout << hero.getHp() << " " << hero.getExp() << endl;
	hero.fight(enemy);
	cout << hero.getHp() << " " << hero.getAtk() << endl;


}