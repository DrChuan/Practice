#pragma once
#include <string>
#include <vector>
#include "MapUtility.h"
#include "FloorFileSet.h"
#include "SquareSetSink.h"
#include "SquareGetSink.h"
#include "IGetSink.h"
#include "IHandleFile/HandleFileSink.h"
#include "EnemyList.h"
#include "ItemList.h"

using std::string;
using std::vector;

class EditorViewModel {
private:
	FloorFileSet m_floorFileSet;
	Floor m_floor;
	EnemyList enemylist;
	ItemList itemlist;
public:
	std::shared_ptr<SquareSetSink> m_sssink;
	std::shared_ptr<SquareGetTSink> m_sgTink;
	std::shared_ptr<SquareGetISink> m_sgIink;
	std::shared_ptr<IGetSink> m_igsink;
	EditorViewModel();

	void setFloorSquare(int x, int y, int type, int index) {
		m_floor.setSquare(type, index, x, y);
	}
	Floor getFloor() {	return  m_floor; }
	void setFloorName(std::string name) { m_floor.setName(name); }
	void saveFloor();
	void loadFloor();
	void generateFloorSet(vector<int> floorsIndex, string filename);
	int getFloorSquareType(int x, int y)
	{
		return m_floor.getSquare(x, y).getType();
	}
	int getFloorSquareIndex(int x, int y)
	{
		return m_floor.getSquare(x, y).getIndex();
	}
	void AddEnemy(int atk, int def, int hp, int exp, string name);
	void AddItem(int hp, int atk, int def, int exp, int specialIndex, int walkable, string name);
};
