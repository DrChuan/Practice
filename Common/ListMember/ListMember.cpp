#include "ListMember.h"
#include <cmath>
Hero::Hero() :Obj( 1200, 18, 18, 0) {
	this->m_level = 0;
	this->next_level_exp = 20;
	this->m_playerX = 5;
	this->m_playerY = 10;
	this->key[0] = 0;
	this->key[1] = 0;
	this->key[2] = 0;
	this->m_equip = 0;
	this->m_weapon = 0;
}

void Hero::addExp(int value) {
	int exp = getExp() + value;
	setExp(exp); 
	if (exp >= this->next_level_exp) {
		this->m_level++;
		this->setHp(this->getHp() + int(300.0 * log10(m_level * 11)));
		this->setAtk(this->getAtk() + int(3.0*log10(m_level*10)));
		this->setDef(this->getDef() + int(5.0 * log10(m_level * 10)));
		this->next_level_exp = m_level * (m_level + 1) * 20;
	}
}

bool Hero::fight(const Enemy& enemy) {
	int Hero_hurt = this->getAtk() - enemy.getDef();
	if (Hero_hurt < 0) return false;
	int huihe = (enemy.getHp() + Hero_hurt - 1) / Hero_hurt;
	int Enemy_hurt = enemy.getAtk() - this->getDef();
	Enemy_hurt = Enemy_hurt > 0 ? Enemy_hurt : 0;
	int hp = this->getHp() - Enemy_hurt * huihe;
	if (hp > 0) {
		this->setHp(hp);
		this->addExp(enemy.getExp());
		return true;
	}
	else {
		return false;
	}
}

bool Hero::getItem(int index) {//这里index待修改
	switch (index) {
	case 0: case 1: case 2://三种钥匙
		this->addKey(index);
	case 20: case 21: case 22://三扇门(三种门)20~22
		if (this->key[index - 20] > 0)
			this->key[index - 20]--;
		else 
			return false;

	}
	return true;
}

void Hero::getItem(int addAtk, int addDef, int addExp, int addHp) {
	this->setAtk(this->getAtk() + addAtk);
	this->setDef(this->getDef() + addDef);
	this->setExp(this->getExp() + addExp);
	this->setHp(this->getHp() + addHp);
}