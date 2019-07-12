#pragma once
#include <string>
#include <vector>
#include "MapUtility.h"
#include "FloorFileSet.h"
#include "EnemyList.h"
#include "ItemList.h"
#include "SquareSetSink.h"
#include "SquareGetSink.h"
#include "IGetSink.h"
#include "HandleFileSink.h"
#include "GenerateGameSink.h"

using std::string;
using std::vector;

class EditorViewModel {
private:

	Floor m_floor;
	EnemyList enemylist;
	ItemList itemlist;
public:
	std::shared_ptr<FloorFileSet> m_floorFileSet;
	std::shared_ptr<SquareSetSink> m_sssink;
	std::shared_ptr<SquareGetTSink> m_sgTink;
	std::shared_ptr<SquareGetISink> m_sgIink;
	std::shared_ptr<IGetSink> m_igsink;
	std::shared_ptr<HandleLFileSink> m_hlfink;
	std::shared_ptr<HandleRFileSink> m_hrfink;
	std::shared_ptr<HandleDFileSink> m_hdfink;
	std::shared_ptr<GenerateGameSink> m_ggsink;

	EditorViewModel();
	void setFloorSquare(int x, int y, int type, int index) {
		m_floor.setSquare(type, index, x, y);
	}
	Floor getFloor() { return  m_floor; }
	void setFloorName(std::string name) { m_floor.setName(name); }
	void resetFloor();
	bool saveFloor();
	bool loadFloor();
	bool removeFloor();
	bool generateFloorSet(const vector<int>& floorsIndex, string filename);
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
	void LoadEnemyList(string filename);
	void ChangeEnemyList(int atk, int def, int hp, int exp, int index);
	void LoadItemList(string filename);
	void ChangeItemList(int hp, int atk, int def, int exp, int Index);
};
