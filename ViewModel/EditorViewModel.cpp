#include"EditorViewModel.h"

EditorViewModel::EditorViewModel():m_sssink(std::make_shared<SquareSetSink>(this)),
									m_sgTink(std::make_shared<SquareGetTSink>(this)),
									m_sgIink(std::make_shared<SquareGetISink>(this)),
									m_igsink(std::make_shared<IGetSink>()),
									m_hdfink(std::make_shared<HandleFileSink>(this))
{
	m_floorFileSet.filenameSetInit();
}
void EditorViewModel::resetFloor() {
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			m_floor.setSquare(-1, -1, i, j);
}
void EditorViewModel::saveFloor() {
	m_floor.saveFloor();
}

void EditorViewModel::loadFloor() {
	m_floor.loadFloor();
}

void EditorViewModel::generateFloorSet(vector<int> floorsIndex, string filename) {
	FloorSet floors(filename);
	for (int i = 0; i < floorsIndex.size(); i++) {
		string filename = m_floorFileSet.getFilename(floorsIndex[i]);
		string path = "floor_ws\\" + filename;
		m_floor.setName(path);
		m_floor.loadFloor();
		m_floor.setName(filename);
		m_floor.setIndex(i);
		floors.addFloor(m_floor);
	}
	floors.saveFloorSet();
	enemylist.SaveEnemyList(filename);
	itemlist.SaveItemList(filename);
}

void EditorViewModel::AddEnemy(int atk, int def, int hp, int exp, string name) {
	enemylist.addEnemy(atk, def, hp, exp);
}
void EditorViewModel::AddItem(int hp, int atk, int def, int exp, int specialIndex, int walkable, string name) {
	itemlist.addItem(hp, atk, def, exp, specialIndex, walkable);
}
