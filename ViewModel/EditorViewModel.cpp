#include"EditorViewModel.h"

EditorViewModel::EditorViewModel():m_sssink(std::make_shared<SquareSetSink>(this)),
									m_sgTink(std::make_shared<SquareGetTSink>(this)),
									m_sgIink(std::make_shared<SquareGetISink>(this)),
									m_igsink(std::make_shared<IGetSink>())
{
	m_floorFileSet.filenameSetInit();
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
void EditorViewModel::LoadEnemyList(string filename) {
	enemylist.SaveEnemyList(filename);
	enemylist.LoadEnemyList(filename);
}
void EditorViewModel::ChangeEnemyList(int atk, int def, int hp, int exp, int index) {
	enemylist.ChangeEnemy(atk, def, hp, exp, index);
}
void EditorViewModel::LoadItemList(string filename) {
	itemlist.SaveItemList(filename);
	itemlist.LoadItemList(filename);
}
void EditorViewModel::ChangeItemList(int hp, int atk, int def, int exp, int Index) {
	itemlist.ChangeItem(hp, atk, def, exp, Index);
}

