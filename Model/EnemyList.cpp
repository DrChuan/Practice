#include "EnemyList.h"

void EnemyList::AddEnemy(int atk, int def, int hp, int exp) {
	Enemy enemy(hp, atk, def, exp);
	m_enemies.push_back(enemy);
}

void EnemyList::ChangeEnemy(int atk, int def, int hp, int exp, int index) {
	m_enemies[index].setAtk(atk);
	m_enemies[index].setDef(def);
	m_enemies[index].setHp(hp);
	m_enemies[index].setExp(exp);
}

void EnemyList::SaveEnemyList(string name) {
	string filename = "Game\\"+name;
	if ((_access(filename.c_str(), 0) == -1))
		if (_mkdir(filename.c_str()) != 0) {
			cerr << "Directory is not exists and can't create the directory:" << filename << "\n";
		}
	string path = filename+ "\\EnemyList.txt";
	ofstream fout;
	fout.open(path.c_str(), ios::out | ios::binary);
	for (int i = 0; i < m_enemies.size(); i++) {
		fout.write((char*)& m_enemies[i], sizeof(m_enemies[i]));
	}
	fout.close();
}

void EnemyList::LoadEnemyList(string name) {
	string filename = "Game\\" + name;
	if ((_access(filename.c_str(), 0) == -1))
		if (_mkdir(filename.c_str()) != 0) {
			cerr << "Directory is not exists and can't create the directory:" << filename << "\n";
		}
	string path = filename + "\\EnemyList.txt";
	ifstream fcin;
	fcin.open(path.c_str(), ios::out | ios::binary);
	for (int i = 0; i < m_enemies.size(); i++) {
		fcin.read ((char*)&m_enemies[i], sizeof(m_enemies[i]));
	}
	fcin.close();
}