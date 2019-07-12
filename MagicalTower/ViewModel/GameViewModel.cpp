#include"ListMember.h"
#include"GameViewModel.h"

void GameViewModel::LoadList(string name1, string name2) {
	m_enemylist.LoadEnemyList(name1);
	m_itemlist.LoadItemList(name2);
}

bool GameViewModel::loadHero(string path) {
	string name;
	if (path.c_str() != nullptr)
		name = path + "\\Hero";
	else
		name = "Hero";
	ofstream fout;
	fout.open(name.c_str(), ios_base::out | ios_base::binary);
	if (!fout.is_open()) {
		cerr << "Can't open the file:" << "Hero" << "\n";
		return false;
	}

	for (auto i : "Hero") {
		fout.write((char*)& i, sizeof i);
	}
	int mo = 0;
	fout.write((char*)& mo, 1);
	fout.write((char*)& index, sizeof index);
	fout.write((char*)& x, sizeof x);
	fout.write((char*)& y, sizeof y);
	fout.write((char*)& m_hero, sizeof m_hero);
	fout.write((char*)& style, sizeof style);
	fout.close();
	return true;
}

bool GameViewModel::saveHero(string path) {
	string name;
	if (path.c_str() != nullptr)
		name = path + "\\" + "Hero";
	else
		name = "Hero";
	ifstream fcin;
	fcin.open(name.c_str(), ios_base::in | ios_base::binary);
	if (!fcin.is_open()) {
		cerr << "Can't open the file:" << "Hero" << "\n";
		return false;
	}
	string m_name = "\0";
	char a;
	fcin.read((char*)& a, 1);
	while (a != 0) {
		m_name += a;
		fcin.read((char*)& a, 1);
	}
	fcin.read((char*)& index, sizeof index);
	fcin.read((char*)& x, sizeof x);
	fcin.read((char*)& y, sizeof y);
	fcin.read((char*)& m_hero, sizeof m_hero);
	fcin.read((char*)& style, sizeof style);
	fcin.close();
	return true;
}

void GameViewModel::Move(int directionKey) {
	xychange(directionKey);
	if (x < 0 || x > 10 || y < 0 || y > 10)return;
	int k = m_floorset.getSquare(index,x,y).getType(); 
	if (k == 0) {
		Item m_item = m_itemlist.getItem(m_floorset.getSquare(index, x, y).getIndex());
		bool f = m_hero.getItem(m_floorset.getSquare(index, x, y).getIndex());
		if (!f)xychange(directionKey ^ 1);
		else {
			m_floorset.getSquare(index, x, y).setType(-1);
			m_floorset.getSquare(index, x, y).setIndex(-1);
		}
		m_hero.getItem(m_item.getAtk(), m_item.getDef(), m_item.getExp(), m_item.getHp());
	}
	if (k == 1) {
		Enemy m_enemy = m_enemylist.getEnemy(m_floorset.getSquare(index, x, y).getIndex());
		bool f = m_hero.fight(m_enemy);
		if (!f)xychange(directionKey ^ 1);
		else {
			m_floorset.getSquare(index, x, y).setType(-1);
			m_floorset.getSquare(index, x, y).setIndex(-1);
		}
	}
	if (k == 2) {
		index++;
	}
	if (k == 3) {
		index--;
	}
}