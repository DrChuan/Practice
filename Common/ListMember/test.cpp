#include <iostream>
#include"ListMember.h"
using namespace std;
int main() {
	Hero hero;
	cout << "Ӣ�۳�ʼ����ֵΪ��"<<hero.getAtk() << endl;
	hero.setAtk(15);
	cout << "���ù���ֵΪ15" << endl;
	cout << "Ӣ�۹���ֵΪ��" << hero.getAtk() << endl;
	cout << "Ӣ�۷���ֵΪ��" << hero.getDef() <<"\n"<< endl;

	Enemy enemy(10,20,10,10);
	hero.fight(enemy);
	cout <<"��ĳ����(hp=10,atk=20,def=10,exp=10)ս����\n"<<"������"<< hero.getHp() << " ���飺" << hero.getExp() << endl;
	hero.fight(enemy);
	cout << "��ĳ����(hp=10,atk=20,def=10,exp=10)�ٴ�ս������������\n" << "������" << hero.getHp() << " ������" << hero.getAtk() <<"\n"<< endl;

	Item item(10,0,0,0,0,0);
	hero.getItem(0, 0, 0, item.getHp());
	cout << "��Ѫƿ(+10)" << endl;
	cout << "������" << hero.getHp() << " ������" << hero.getAtk() << endl;
	cout << "��Կ������" << hero.getKey(1) << endl;
	cout << "�õ���Կ��" << endl;
	hero.getItem(1);
	cout << "��Կ������" << hero.getKey(1) << endl;


}