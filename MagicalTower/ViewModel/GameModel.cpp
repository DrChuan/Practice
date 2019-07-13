#include"ListMember.h"
#include"GameModel.h"
using namespace std;
bool GameModel::LoadMap(string path, string name) {
	m_floorset.setName(name);
	return m_floorset.loadFloorSet(path);
}

bool GameModel::SaveMap(string path, string name) {
	m_floorset.setName(name);
	return m_floorset.saveFloorSet(path);
}

bool GameModel::LoadList(string path) {
	if (!m_enemylist.LoadEnemyList(path))return false;
	if (!m_itemlist.LoadItemList(path)) return false;
	return true;
}

bool GameModel::SaveList(string path) {
	if (!m_enemylist.SaveEnemyList(path))return false;
	if (!m_itemlist.SaveItemList(path)) return false;
	return true;
}

bool GameModel::loadHero(string path) {
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

bool GameModel::saveHero(string path) {
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

bool GameModel::loadAppend(string path) {
	string name = path + "\\append";
	ifstream fcin(name, ios_base::in);
	if (!fcin.is_open()) return false;
	int temp;
	fcin.read((char*)& style, sizeof(int));
	fcin.read((char*)& temp, sizeof(int));//gold
	m_hero->setCoins(temp);
	fcin.read((char*)& temp, sizeof(int));//hp
	m_hero->setHp(temp);
	fcin.read((char*)& temp, sizeof(int));//Atk
	m_hero->setAtk(temp);
	fcin.read((char*)& temp, sizeof(int));//Def
	m_hero->setDef(temp);
	fcin.read((char*)& temp, sizeof(int));//YKey
	m_hero->setKey(0, temp);
	fcin.read((char*)& temp, sizeof(int));//BKey
	m_hero->setKey(1, temp);
	fcin.read((char*)& temp, sizeof(int));//RKey
	m_hero->setKey(2, temp);
}

int GameModel::Move(int directionKey) {//返回：0-没动， 1-走了一格， 2-换层
	xychange(directionKey);
	if (x < 0 || x > 10 || y < 0 || y > 10) {
		xychange(directionKey ^ 1);
		return 0;
	}
	int k = m_floorset.getSquare(index, x, y).getType();
	if (k == 0) {
		int indexx = m_floorset.getSquare(index, x, y).getIndex();
		if (indexx < 20) {
			Item m_item = m_itemlist.getItem(indexx);
			m_hero->getItem(m_item.getAtk(), m_item.getDef(), m_item.getExp(), m_item.getHp(), m_item.getCoins());
			m_floorset.setSquare(index, -1, -1, x, y);
			return 1;
		}
		else {
			int f = m_hero->getItem(indexx);
			switch (f) {
			case 0:
				xychange(directionKey ^ 1);
				break;
			case 1:
				m_floorset.setSquare(index, -1, -1, x, y);
				break;
			case 2:
				if (index > 0) {
					index--;
					resetXY(1);
				}
				break;
			case 3:
				if (index < m_floorset.getFloorNum() - 1) {
					index++;
					resetXY(0);
				}
				break;
			}
			return (f == 3) ? 2 : f;
		}
	}
	if (k == 1) {
		Enemy m_enemy = m_enemylist.getEnemy(m_floorset.getSquare(index, x, y).getIndex());
		bool f = m_hero->fight(m_enemy);
		if (!f) {
			xychange(directionKey ^ 1);
			return 0;
		}
		else {
			m_floorset.setSquare(index, -1, -1, x, y);
			return 1;
		}
	}
	return 1;
}

void GameModel::resetXY(int direction) {
	int temp = 20 + direction;
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			if (m_floorset.getSquare(index, i, j).getIndex() == temp && m_floorset.getSquare(index, i, j).getType() == 0)
			{
				x = i; y = j;
				return;
			}
}