#include "GameViewModel.h"
bool gSetNameSink::onHandleFile(std::string filename) {
	//m_gVM->gm->setName(filename);
	m_gVM->gm->LoadMap("game", filename);
	m_gVM->gm->LoadList("game\\" + filename);
	m_gVM->gm->loadAppend("game\\" + filename);
	return true;
}