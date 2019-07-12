#pragma once
#include"GameViewModel.h"
#include"ListMember.h"
#include"MapUtility.h"
#include"EnemyList.h"
#include"ItemList.h"
#include <fstream>
#include <io.h>
#include <direct.h>

class GameViewModel {
	Hero m_hero;
	FloorSet m_floorset;
	EnemyList m_enemylist;
	ItemList m_itemlist;
	int index, x, y, style;
public:
	GameViewModel(string name="focused name",int xx = 5, int yy = 10):x(xx),y(yy), m_floorset(name){}
	void LoadList(string enemylistname, string itemlistname);
	void LoadMap(string name) {	m_floorset.loadFloorSet(name);}
	void SaveMap(string name) {	m_floorset.saveFloorSet(name);}
	bool loadHero(string path);
	bool saveHero(string path);
	void xychange(int k) {
		if (k == 0)y--;
		if (k == 1)y++;
		if (k == 2)x--;
		if (k == 3)x++;
	}
	void Move(int directionKey);
};