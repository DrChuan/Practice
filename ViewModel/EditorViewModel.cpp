#include"EditorViewModel.h"

EditorViewModel::EditorViewModel():m_sssink(std::make_shared<SquareSetSink>(this)),
									m_sgTink(std::make_shared<SquareGetTSink>(this)),
									m_sgIink(std::make_shared<SquareGetISink>(this))
{
	m_floorFileSet.filenameSetInit();
}

void EditorViewModel::saveFloor() {
	string filename = m_floor.getName();
	string path = "floor_work\\" + filename;
	m_floor.setName(path);
	m_floor.saveFloor();
	m_floor.setName(filename);
}

void EditorViewModel::loadFloor() {
	string filename = m_floor.getName();
	string path = "floor_work\\" + filename;
	m_floor.setName(path);
	m_floor.loadFloor();
	m_floor.setName(filename);
}

void EditorViewModel::generateFloorSet(vector<int> floorsIndex, string filename) {
	FloorSet floors(filename);
	for (int i = 0; i < floorsIndex.size(); i++) {
		string filename = m_floorFileSet.getFilename(floorsIndex[i]);
		string path = "floor_work\\" + filename;
		m_floor.setName(path);
		m_floor.loadFloor();
		m_floor.setName(filename);
		m_floor.setIndex(i);
		floors.addFloor(m_floor);
	}
	floors.saveFloorSet();
}