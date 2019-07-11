#include "ItemList.h"

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
		Item x = m_items[i];
		fout.write(path.c_str(), sizeof(x.getHp()));
		fout.write(path.c_str(), sizeof(x.getAtk()));
		fout.write(path.c_str(), sizeof(x.getDef()));
		fout.write(path.c_str(), sizeof(x.getExp()));
		fout.write(path.c_str(), sizeof(x.getSpecialIndex()));
		fout.write(path.c_str(), sizeof(x.getWalkable()));
	}
	fout.close();
}