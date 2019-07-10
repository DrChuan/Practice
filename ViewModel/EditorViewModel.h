#pragma once
#include <string>
#include <vector>
#include "MapUtility.h"
#include "FloorFileSet.h"
#include "SquareSetSink.h"
#include "SquareGetSink.h"

using std::string;
using std::vector;

class EditorViewModel {
	FloorFileSet m_floorFileSet;
	Floor m_floor;
public:
	std::shared_ptr<SquareSetSink> m_sssink;
	std::shared_ptr<SquareGetTSink> m_sgTink;
	std::shared_ptr<SquareGetISink> m_sgIink;
	EditorViewModel();
	void setFloorSquare(int x, int y, int type, int index) {
		m_floor.setSquare(type, index, x, y);
	}
	Floor getFloor() {	return  m_floor; }
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
};
