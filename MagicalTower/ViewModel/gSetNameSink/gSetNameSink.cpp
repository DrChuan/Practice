#include "GameViewModel.h"
bool gSetNameSink::onHandleFile(std::string filename) {
	//m_gVM->gm->setName(filename);
	Hero nhero;
	*m_gVM->gm->m_hero = nhero;
	m_gVM->gm->LoadMap("game", filename);
	m_gVM->gm->LoadList("game\\" + filename);
	m_gVM->gm->loadAppend("game\\" + filename);//
	m_gVM->gm->setIndex(0);
	return true;
}