#include "GameViewModel.h"

bool gSaveSink::onHandleFile(std::string filename) {
	return m_gVM->saveGame(filename);
}