#pragma once
#include <string>

class Obj {
private:
	int m_hp, m_atk, m_def, m_exp, m_coins; //生命 攻击 防御 经验 名字 
public:
	Obj(int hp = 0, int atk = 0, int def = 0, int exp = 0, int coins = 0) : m_hp(hp), m_atk(atk), m_def(def), m_exp(exp), m_coins(coins) {}

	void setHp(int value) { m_hp = value; }
	void setAtk(int value) { m_atk = value; }
	void setDef(int value) { m_def = value; }
	void setExp(int value) { m_exp = value; }
	void setCoins(int value) { m_coins = value; }

	int getHp() const { return m_hp; }
	int getAtk() const { return m_atk; }
	int getDef() const { return m_def; }
	int getExp() const { return m_exp; }
	int getCoins() const { return m_coins; }
};

class Enemy : public Obj {
public:
	Enemy(Obj & obj) : Obj(obj) {}

	Enemy(int hp = 0, int atk = 0, int def = 0, int exp = 0, int coins = 0) :Obj(hp, atk, def, exp, coins) {}
};

class  Item : public Obj {
private:
	//int  m_specialIndex;
	bool m_walkable;

public:
	Item(int hp = 0, int atk = 0, int def = 0, int exp = 0, int coins = 0, int walkable = 0) :
		Obj(hp, atk, def, exp, coins), m_walkable(walkable) {}

	//void setSpecialIndex(int value) { m_specialIndex = value; }
	void setWalkable(bool wkb) { m_walkable = wkb; }

	//int getSpecialIndex() { return m_specialIndex; }
	bool getWalkable() { return m_walkable; }
};

class Hero : public Obj {
private:
	int next_level_exp;
	int m_level, m_weapon, m_equip; //direction {0,1,2,3}=={上，下，左，右}
	bool EnemyBook;
	int key[3];
	void addExp(int value);
	void addKey(int keyNum) { key[keyNum]++; }
public:
	Hero();

	bool fight(const Enemy& enemy);

	int getHurt(const Enemy& enemy);

	int getItem(int index);

	void getItem(int addAtk, int addDef, int addExp, int addHp, int addCoins);

	int getKey(int index) { return key[index]; }

	void setKey(int index, int num) { key[index] = num; }

	int getLevel();

	void setEnemyBook(bool o) { EnemyBook = o; }

	bool getEnemyBook() { return EnemyBook; }
};