#include <iostream>
#include"ListMember.h"
using namespace std;
int main() {
	Hero hero;
	cout << "英雄初始攻击值为："<<hero.getAtk() << endl;
	hero.setAtk(15);
	cout << "设置攻击值为15" << endl;
	cout << "英雄攻击值为：" << hero.getAtk() << endl;

	Enemy enemy(10,20,10,10);
	hero.fight(enemy);
	cout << hero.getHp() << " " << hero.getExp() << endl;
	hero.fight(enemy);
	cout << hero.getHp() << " " << hero.getAtk() << endl;


}