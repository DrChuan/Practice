#include "ItemList.h"

static int itemlist[20][6] =
{
	{ 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 3, 0, 0, 0 },{ 0, 0, 0, 5, 0, 0 },{ 0, 2, 0, 0, 0, 0 },
	{ 0, 1, 4, 0, 0, 0 },{ 0, 0, 0, 20, 0, 0 },{ 200, 0, 0, 0, 0, 0 },
	{ 0, 10, 0, 0, 0, 0 },{ 0, 30, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0 }, //18
	{ 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 0 }
};

void ItemList::ItemList::Init() {
	m_items.clear();
	for (int i = 0; i < 20; i++) {
		AddItem(itemlist[i][0], itemlist[i][1], itemlist[i][2], itemlist[i][3], itemlist[i][4], itemlist[i][5]);
	}
}

void ItemList::AddItem(int hp, int atk, int def, int exp, int coins, int walkable) {
	Item item(hp, atk, def, exp, coins, walkable);
	m_items.push_back(item);
}

void ItemList::ChangeItem(int hp, int atk, int def, int exp, int coins, int Index) {
	m_items[Index].setAtk(atk);
	m_items[Index].setDef(def);
	m_items[Index].setHp(hp);
	m_items[Index].setExp(exp);
	m_items[Index].setCoins(coins);
}

bool ItemList::SaveItemList(string path) {//将itemlist保存至path目录下
	if ((_access(path.c_str(), 0) == -1))
		if (_mkdir(path.c_str()) != 0) {
			cerr << "Directory is not exists and can't create the directory:" << path << "\n";
			return false;
		}
	string filename = path + "\\ItemList.txt";
	ofstream fout;
	fout.open(filename.c_str(), ios::out | ios::binary);
	if (!fout.is_open()) return false;
	for (int i = 0; i < m_items.size(); i++) {
		fout.write((char*)& m_items[i], sizeof(m_items[i]));
	}
	fout.close();
	return true;
}

bool ItemList::LoadItemList(string path) {//从path目录下读取iteamlist
	if ((_access(path.c_str(), 0) == -1))
		if (_mkdir(path.c_str()) != 0) {
			cerr << "Directory is not exists and can't create the directory:" << path << "\n";
			return false;
		}
	string filename = path + "\\ItemList.txt";
	ifstream fcin;
	fcin.open(filename.c_str(), ios::out | ios::binary);
	if (!fcin.is_open()) return false;
	for (int i = 0; i < 25; i++) {
		Item temp;
		fcin.read((char*)& temp, sizeof(m_items[i]));
		m_items.push_back(temp);
	}
	fcin.close();
	return true;
}