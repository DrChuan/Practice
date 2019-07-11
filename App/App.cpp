#include "App.h"

MagicalTower::MagicalTower(int argc, char* argv[] ):QApplication(argc, argv) {

};

void MagicalTower::Init() {
	w.editWindow = new EditWindow();

	w.editWindow->iss = evm.m_sssink;
	w.editWindow->isgi = evm.m_sgIink;
	w.editWindow->isgt = evm.m_sgTink;

	w.show();
}