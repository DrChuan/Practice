#pragma once
#include"ListMember.h"
#include"MapUtility.h"
#include"EnemyList.h"
#include"ItemList.h"
#include <fstream>
#include <io.h>
#include <direct.h>

class GameModel {
private:
	FloorSet m_floorset;
	EnemyList m_enemylist;
	ItemList m_itemlist;
	int index, x, y, style;

	void xychange(int k) {	//�ƶ�һ���������ң�
		switch (k) {
		case 0: y--; break; case 1: y++; break;
		case 2: x--; break; case 3: x++; break;
		}
	}
public:
	shared_ptr<Hero> m_hero;
	GameModel(string name = "focused game", int xx = 5, int yy = 10) :x(xx), y(yy), m_floorset(name), index(0), style(0), m_hero(make_shared<Hero>()) {
		Floor floor;
		m_floorset.addFloor(floor);
	}
	bool LoadList(string path);
	bool LoadMap(string path, string name);//��path·����һ��Ϊgame��save����ȡ��Ϊname����Ϸ���浵����ͼ
	bool loadHero(string path);
	bool loadAppend(string path);

	bool SaveList(string path);
	bool SaveMap(string path, string name);
	bool saveHero(string path);

	//void setName(string name) { m_floorset.setName(name); }

	int Move(int directionKey);
	int getFloorSetSize() { return m_floorset.getFloorNum(); }//���ز���
	int getIndex() { return index; }
	int getStyle() { return style; }
	int getX() { return x; }
	int getY() { return y; }
	int getSquareType(int x, int y) { return m_floorset.getSquare(index, x, y).getType(); }
	int getSquareIndex(int x, int y) { return m_floorset.getSquare(index, x, y).getIndex(); }

	void resetXY(int direction);
};