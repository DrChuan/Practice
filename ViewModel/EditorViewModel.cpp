#include"EditorViewModel.h"
#include <fstream>

EditorViewModel::EditorViewModel():m_sssink(std::make_shared<SquareSetSink>(this)),
									m_sgTink(std::make_shared<SquareGetTSink>(this)),
									m_sgIink(std::make_shared<SquareGetISink>(this)),
									m_igsink(std::make_shared<IGetSink>()),
									m_hlfink(std::make_shared<HandleLFileSink>(this)),
									m_hrfink(std::make_shared<HandleRFileSink>(this)),
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
void EditorViewModel::saveFloor() {
	m_floor.saveFloor();
}

void EditorViewModel::loadFloor() {
	m_floor.loadFloor();
}

void EditorViewModel::generateFloorSet(const vector<int>& floorsIndex, string filename) {
	FloorSet floors(filename);
	for (int i = 1; i < floorsIndex.size(); i++) {
		string filename = m_floorFileSet->getFilename(floorsIndex[i]);
		string path = "floor_ws\\" + filename;
		m_floor.setName(path);
		m_floor.loadFloor();
		m_floor.setName(filename);
		m_floor.setIndex(i);
		floors.addFloor(m_floor);
	}
	ofstream fout;
	fout.open("game\\" + filename + "\\filenameStyle.stl", ios_base::in);
	fout.write((char *)&floorsIndex[0], sizeof floorsIndex[0]);
	fout.close();
	floors.saveFloorSet();
	enemylist.SaveEnemyList(filename);
	itemlist.SaveItemList(filename);
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
