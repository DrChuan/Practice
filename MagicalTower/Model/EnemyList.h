#pragma once
#include<string>
#include<vector>
#include <io.h>
#include <direct.h>
#include <fstream>
#include"ListMember.h"
#include<iostream>
using namespace std;
class EnemyList {
	string  m_enemyFile;
	vector<Enemy> m_enemies;
public:
	void Init();
	void AddEnemy(int atk, int def, int hp, int exp, int coins);
	void ChangeEnemy(int atk, int def, int hp, int exp, int coins, int index);
	Enemy getEnemy(int index) { return m_enemies[index]; }
	bool SaveEnemyList(string path);
	bool LoadEnemyList(string path);
};

