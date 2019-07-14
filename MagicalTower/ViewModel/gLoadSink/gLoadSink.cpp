#include "GameViewModel.h"

bool gLoadSink::onHandleFile(std::string filename) {
	return m_gVM->loadGame("save", filename);
}