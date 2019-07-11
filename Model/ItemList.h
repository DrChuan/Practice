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
	void addItem(int hp, int atk, int def , int exp , int specialIndex, int walkable) {
		Item item(hp, atk, def, exp, specialIndex, walkable);
		m_items.push_back(item);
	}
	Item getItem(int index) {
		return m_items[index];
	}
	void SaveItemList(string name);
};