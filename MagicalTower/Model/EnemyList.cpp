#include "EnemyList.h"
static int enemylist[25][5] =//生命 攻击 防御 金币 经验
{
	{35,18,1,1,1},{45,20,2,2,1},{35,38,3,3,3},{60,32,8,5,2},{50,42,6,6,3},
	{55,52,12,8,4},{50,48,22,12,2},{100,65,15,30,5},{60,100,8,12,9},{100,95,30,18,6},
	{320,120,15,30,10},{1200,180,20,100,16},{4500,560,310,1000,25},{210,200,65,45,13},{320,140,20,30,12},
	{100,180,110,50,7},{100,680,50,55,63},{1500,600,250,800,35},{160,230,105,65,12},{120,150,50,100,10},
	{220,370,110,80,26},{200,380,130,90,25},{360,310,20,40,29},{180,460,360,200,10},{5000,1580,190,50,139}
};
void EnemyList::Init() {
	m_enemies.clear();
	for (int i = 0; i < 25; i++)
		AddEnemy(enemylist[i][1], enemylist[i][2], enemylist[i][0], enemylist[i][4], enemylist[i][3]);
}

void EnemyList::AddEnemy(int atk, int def, int hp, int exp, int coins) {
	Enemy enemy(hp, atk, def, exp, coins);
	m_enemies.push_back(enemy);
}

void EnemyList::ChangeEnemy(int atk, int def, int hp, int exp, int coins, int index) {
	m_enemies[index].setAtk(atk);
	m_enemies[index].setDef(def);
	m_enemies[index].setHp(hp);
	m_enemies[index].setExp(exp);
	m_enemies[index].setCoins(coins);
}

bool EnemyList::SaveEnemyList(string path) {//将EnemyList.txt保存至path目录下
	if ((_access(path.c_str(), 0) == -1))
		if (_mkdir(path.c_str()) != 0) {
			cerr << "Directory is not exists and can't create the directory:" << path << "\n";
			return false;
		}
	string filename = path + "\\EnemyList.txt";
	ofstream fout;
	fout.open(filename.c_str(), ios::out | ios::binary);
	if (!fout.is_open()) return false;
	for (int i = 0; i < m_enemies.size(); i++) {
		fout.write((char*)& m_enemies[i], sizeof(m_enemies[i]));
	}
	fout.close();
	return true;
}

bool EnemyList::LoadEnemyList(string path) {//从path目录下读取EnemyList.txt
	if ((_access(path.c_str(), 0) == -1))
		if (_mkdir(path.c_str()) != 0) {
			cerr << "Directory is not exists and can't create the directory:" << path << "\n";
			return false;
		}
	string filename = path + "\\EnemyList.txt";
	ifstream fcin;
	m_enemies.clear();
	fcin.open(filename.c_str(), ios::out | ios::binary);
	if (!fcin.is_open()) return false;
	for (int i = 0; i < 25; i++) {
		Enemy temp;
		fcin.read((char*)& temp, sizeof(temp));
		m_enemies.push_back(temp);
	}
	fcin.close();
	return true;
}