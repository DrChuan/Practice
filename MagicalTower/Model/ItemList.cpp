#include "ItemList.h"

void ItemList::AddItem(int hp, int atk, int def, int exp, int specialIndex, int walkable) {
	Item item(hp, atk, def, exp, specialIndex, walkable);
	m_items.push_back(item);
}

void ItemList::ChangeItem(int hp, int atk, int def, int exp,int Index) {
	m_items[Index].setAtk(atk);
	m_items[Index].setDef(def);
	m_items[Index].setHp(hp);
	m_items[Index].setExp(exp);
}

void ItemList::SaveItemList(string name) {
	string filename = "Game\\" + name;
	if ((_access(filename.c_str(), 0) == -1))
		if (_mkdir(filename.c_str()) != 0) {
			cerr << "Directory is not exists and can't create the directory:" << filename << "\n";
		}
	string path = filename + "\\ItemList.txt";
	ofstream fout;
	fout.open(path.c_str(), ios::out | ios::binary);
	for (int i = 0; i < m_items.size(); i++) {
		fout.write((char*)& m_items[i], sizeof(m_items[i]));
	}
	fout.close();
}

void ItemList::LoadItemList(string name) {
	string filename = "Game\\" + name;
	if ((_access(filename.c_str(), 0) == -1))
		if (_mkdir(filename.c_str()) != 0) {
			cerr << "Directory is not exists and can't create the directory:" << filename << "\n";
		}
	string path = filename + "\\ItemList.txt";
	ifstream fcin;
	fcin.open(path.c_str(), ios::out | ios::binary);
	for (int i = 0; i < m_items.size(); i++) {
		fcin.read((char*)& m_items[i], sizeof(m_items[i]));
	}
	fcin.close();
}