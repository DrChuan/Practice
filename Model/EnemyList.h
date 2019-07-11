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
	void addEnemy(int atk, int def, int hp, int exp) {
		Enemy enemy(hp, atk, def, exp);
		m_enemies.push_back(enemy);
	}
	Enemy getEnemy(int index) {
		return m_enemies[index];
	}
	void SaveEnemyList(string name);
};

