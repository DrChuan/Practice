#pragma once
#include<string>
#include<vector>
#include <io.h>
#include <direct.h>
#include <fstream>
#include"ListMember.h"
#include<iostream>
using namespace std;
class EnemyList{
	string  m_enemyFile;
	vector<Enemy> m_enemies;
public:
	void AddEnemy(int atk, int def, int hp, int exp);
	void ChangeEnemy(int atk, int def, int hp, int exp, int index);
	Enemy getEnemy(int index) {return m_enemies[index];	}
	void SaveEnemyList(string name);
	void LoadEnemyList(string name);
};

