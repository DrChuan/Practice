#include <string>

class Obj() {
private:
	int m_hp, m_atk, m_def, m_exp;
	std::string m_name;		////生命 攻击 防御 经验 名字 
public:
	Obj(std::string name,int hp = 0, int atk = 0, int def = 0, int exp = 0) :m_name(name), m_hp(hp), m_atk(atk), m_def(def), m_exp(exp) {}

	int getName() { return m_name; }

	void setHp(int value) { m_hp = value; }
	void setAtk(int value) { m_atk = value; }
	void setDef(int value) { m_def = value; }
	void setExp(int value) { m_exp = value; }
	void setName(std::string value) { m_name = value; }

	int getHp() { return m_hp; }
	int getAtk() { return m_stk; }
	int getDef() { return m_def; }
	int getexp() { return m_exp; }
	std::string getName() { return m_name; }
}

class Enemy: public Obj {
public:
	Enemy(std::string name, int hp = 0, int atk = 0, int def = 0, int exp = 0) :Obj(name, hp, atk, def, exp) {}
	//friend bool fight(int enmAtk, int enmDef, int enmHp, int enmExp);
};

class  Item: public Obj {
private:
	int  m_specialIndex;
	bool m_walkable;

public:
	Item(std::string name, int hp = 0, int atk = 0, int def = 0, int exp = 0, int specialIndex, int walkable = 0) :
		: Obj(name, hp, atk, def, exp), m_specialIndex(specialIndex), m_walkable(walkable){}

	void setSpecialIndex(int value) { m_specialIndex = value; }
	void setWalkable(bool wkb) { m_walkable = wkb; }

	int getSpecialIndex() { return m_specialIndex; }
	bool getWalkable() { return getWalkable; }
};