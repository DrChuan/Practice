#include <iostream>
#include"ListMember.h"
using namespace std;
int main() {
	Hero hero;
	cout << "英雄初始攻击值为："<<hero.getAtk() << endl;
	hero.setAtk(15);
	cout << "设置攻击值为15" << endl;
	cout << "英雄攻击值为：" << hero.getAtk() << endl;
	cout << "英雄防御值为：" << hero.getDef() <<"\n"<< endl;

	Enemy enemy(10,20,10,10);
	hero.fight(enemy);
	cout <<"与某怪物(hp=10,atk=20,def=10,exp=10)战斗后：\n"<<"生命："<< hero.getHp() << " 经验：" << hero.getExp() << endl;
	hero.fight(enemy);
	cout << "与某怪物(hp=10,atk=20,def=10,exp=10)再次战斗后（升级）：\n" << "生命：" << hero.getHp() << " 攻击：" << hero.getAtk() <<"\n"<< endl;

	Item item(10,0,0,0,0,0);
	hero.getItem(0, 0, 0, item.getHp());
	cout << "捡到血瓶(+10)" << endl;
	cout << "生命：" << hero.getHp() << " 攻击：" << hero.getAtk() << endl;
	cout << "黄钥匙数：" << hero.getKey(1) << endl;
	cout << "拿到黄钥匙" << endl;
	hero.getItem(1);
	cout << "黄钥匙数：" << hero.getKey(1) << endl;


}