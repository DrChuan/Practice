#include"EditorViewModel.h"
#include <fstream>

EditorViewModel::EditorViewModel() :m_sssink(std::make_shared<SquareSetSink>(this)),
m_sgTink(std::make_shared<SquareGetTSink>(this)),
m_sgIink(std::make_shared<SquareGetISink>(this)),
m_igsink(std::make_shared<IGetSink>()),
m_hlfink(std::make_shared<HandleLFileSink>(this)),
m_hrfink(std::make_shared<HandleRFileSink>(this)),
m_hdfink(std::make_shared<HandleDFileSink>(this)),
m_ggsink(std::make_shared<GenerateGameSink>(this))
{
	m_floorFileSet = std::make_shared<FloorFileSet>();
	m_floorFileSet->filenameSetInit();
}
void EditorViewModel::resetFloor() {
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			m_floor.setSquare(-1, -1, i, j);
}
bool EditorViewModel::saveFloor() {
	return m_floor.saveFloor();
}

bool EditorViewModel::loadFloor() {
	return m_floor.loadFloor();
}

bool EditorViewModel::removeFloor() {
	return m_floor.removeFloor();
}

bool EditorViewModel::generateFloorSet(const vector<int>& floorsIndex, string filename) {
	FloorSet floors(filename);
	for (int i = 8; i < floorsIndex.size(); i++) {
		string name = m_floorFileSet->getFilename(floorsIndex[i]);
		m_floor.setName(name);
		if (!m_floor.loadFloor())return false;
		floors.addFloor(m_floor);
		m_floor.setIndex(i);
	}
	if (!floors.saveFloorSet()) return false;
	ofstream fout;
	fout.open("game\\" + filename + "\\append", ios_base::out);
	if (!fout.is_open()) return false;
	for (int i = 0; i < 8; i++)
		fout.write((char*)& floorsIndex[i], sizeof floorsIndex[i]);
	fout.close();
	enemylist.SaveEnemyList(filename);
	itemlist.SaveItemList(filename);
	return true;
}

void EditorViewModel::AddEnemy(int atk, int def, int hp, int exp, string name) {
	enemylist.AddEnemy(atk, def, hp, exp);
}
void EditorViewModel::AddItem(int hp, int atk, int def, int exp, int specialIndex, int walkable, string name) {
	itemlist.AddItem(hp, atk, def, exp, specialIndex, walkable);
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
