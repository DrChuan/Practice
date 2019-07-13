#include "App.h"

MagicalTower::MagicalTower(int argc, char* argv[]) :QApplication(argc, argv) {

};

void MagicalTower::Init() {
	w.editWindow = new EditWindow();
	w.gameWindow = new GameWindow();

	string path = "floors_ws";
	if ((_access((path).c_str(), 0) == -1))
		if (_mkdir((path).c_str()) != 0)
			cerr << "Can't open or create the directory:" << path << "\n";
	path = "game";
	if ((_access((path).c_str(), 0) == -1))
		if (_mkdir((path).c_str()) != 0)
			cerr << "Can't open or create the directory:" << path << "\n";

	w.editWindow->iss = evm.m_sssink;
	w.editWindow->isgi = evm.m_sgIink;
	w.editWindow->isgt = evm.m_sgTink;
	w.editWindow->iGetUntitledFloorNum = evm.m_igsink;
	w.editWindow->iSaveFile = evm.m_hrfink;
	w.editWindow->iLoadFile = evm.m_hlfink;
	w.editWindow->iDeleteFile = evm.m_hdfink;
	w.editWindow->iGenerate = evm.m_ggsink;
	w.editWindow->iGetObj = evm.m_gosink;
	w.editWindow->iSetObj = evm.m_sosink;

	w.editWindow->pFloorFileSet = evm.m_floorFileSet;

	w.gameWindow->iGetSpecialInt = gvm.m_gssink;
	w.gameWindow->iMove = gvm.m_mvsink;
	w.gameWindow->iSetGame = gvm.m_gsnink;
	w.gameWindow->isgt = gvm.m_gstink;
	w.gameWindow->isgi = gvm.m_gsiink;


	w.gameWindow->hero = gvm.gm->m_hero;

	w.show();
}