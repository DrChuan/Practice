#include "EnemyList.h"

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
		Enemy x = m_enemies[i];
		fout.write(path.c_str(), sizeof(x.getHp()));
		fout.write(path.c_str(), sizeof(x.getAtk()));
		fout.write(path.c_str(), sizeof(x.getDef()));
		fout.write(path.c_str(), sizeof(x.getExp()));
	}
	fout.close();
}
