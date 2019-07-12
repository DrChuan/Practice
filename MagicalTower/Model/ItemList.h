#pragma once
#include<string>
#include<vector>
#include <io.h>
#include <direct.h>
#include <fstream>
#include"ListMember.h"
#include<iostream>
using namespace std;
class ItemList {
	string  m_itemFile;
	vector<Item> m_items;
public:
	void AddItem(int hp, int atk, int def, int exp, int coins, int specialIndex, int walkable);
	void ChangeItem(int hp, int atk, int def, int exp, int coins, int Index);
	Item getItem(int index) { return m_items[index]; }
	void SaveItemList(string name);
	void LoadItemList(string name);
};