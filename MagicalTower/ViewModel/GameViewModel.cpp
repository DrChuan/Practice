#include "GameViewModel.h"
using namespace std;
GameViewModel::GameViewModel() :
	m_gssink(make_shared<GetSpeSink>(this)),
	m_mvsink(make_shared<MoveSink>(this)),
	m_gsnink(make_shared<gSetNameSink>(this)),
	m_gstink(make_shared<gGetSquareTSink>(this)),
	m_gsiink(make_shared<gGetSquareISink>(this))
{
	gm = make_shared<GameModel>();
}

bool GameViewModel::saveGame(string name) {
	string path = "save";
	if (!gm->SaveMap(path, name)) return false;
	if (!gm->saveHero(path + "\\" + name)) return false;
	if (!gm->SaveList(path + "\\" + name)) return false;
	return true;
}

bool GameViewModel::loadGame(string path, string name) {
	if (!gm->LoadMap(path, name)) return false;
	if (!gm->loadHero(path + "\\" + name)) return false;
	if (!gm->LoadList(path + "\\" + name)) return false;
	return true;
}

