#pragma once
#include <string>

class Obj {
private:
	int m_hp, m_atk, m_def, m_exp; //生命 攻击 防御 经验 名字 
public:
	Obj(int hp = 0, int atk = 0, int def = 0, int exp = 0) : m_hp(hp), m_atk(atk), m_def(def), m_exp(exp) {}

	void setHp(int value) { m_hp = value; }
	void setAtk(int value) { m_atk = value; }
	void setDef(int value) { m_def = value; }
	void setExp(int value) { m_exp = value; }

	int getHp() const { return m_hp; }
	int getAtk() const { return m_atk; }
	int getDef() const { return m_def; }
	int getExp() const { return m_exp; }
};

class Enemy: public Obj {
public:
	Enemy( int hp = 0, int atk = 0, int def = 0, int exp = 0) :Obj( hp, atk, def, exp) {}
};

class  Item: public Obj {
private:
	int  m_specialIndex;
	bool m_walkable;

public:
	Item( int hp = 0, int atk = 0, int def = 0, int exp = 0, int specialIndex=-1, int walkable = 0) :
		 Obj( hp, atk, def, exp), m_specialIndex(specialIndex), m_walkable(walkable) {}

	void setSpecialIndex(int value) { m_specialIndex = value; }
	void setWalkable(bool wkb) { m_walkable = wkb; }

	int getSpecialIndex() { return m_specialIndex; }
	bool getWalkable() { return m_walkable; }
};

class Hero : public Obj {
private:
	int next_level_exp;
	int m_level, m_weapon, m_equip; //direction {0,1,2,3}=={上，下，左，右}
	int key[3];
	void addExp(int value);
	void addKey(int keyNum) { key[keyNum]++; }
public:
	Hero();

	bool fight(const Enemy& enemy);

	bool getItem(int index);

	void getItem(int addAtk, int addDef, int addExp, int addHp);

	int getKey(int num) { return key[num]; }
};