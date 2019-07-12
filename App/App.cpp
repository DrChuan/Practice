#include "App.h"

MagicalTower::MagicalTower(int argc, char* argv[]) :QApplication(argc, argv) {

};

void MagicalTower::Init() {
	w.editWindow = new EditWindow();

	string path = "floors_ws";
	if ((_access((path).c_str(), 0) == -1))
		if (_mkdir((path).c_str()) != 0) {
			cerr << "Can't open or create the directory:" << path << "\n";
		}

	w.editWindow->iss = evm.m_sssink;
	w.editWindow->isgi = evm.m_sgIink;
	w.editWindow->isgt = evm.m_sgTink;
	w.editWindow->iGetUntitledFloorNum = evm.m_igsink;
	w.editWindow->iSaveFile = evm.m_hrfink;
	w.editWindow->iLoadFile = evm.m_hlfink;
	w.editWindow->iDeleteFile = evm.m_hdfink;
	w.editWindow->iGenerate = evm.m_ggsink;

	w.editWindow->pFloorFileSet = evm.m_floorFileSet;

	w.show();
}