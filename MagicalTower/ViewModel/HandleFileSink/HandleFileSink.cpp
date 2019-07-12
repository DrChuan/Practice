#pragma once
#include "EditorViewModel.h"

bool HandleLFileSink::onHandleFile(std::string filename) {
	if (filename == "__new") {
		m_eVM->setFloorName("Focused Floor");
		m_eVM->resetFloor();
		return true;
	}
	else {
		m_eVM->setFloorName(filename);
		return m_eVM->loadFloor();
	}
	return true;
}

bool HandleRFileSink::onHandleFile(std::string filename) {
	m_eVM->setFloorName(filename);
	return m_eVM->saveFloor();
}

bool HandleDFileSink::onHandleFile(std::string filename) {
	m_eVM->setFloorName(filename);
	return m_eVM->removeFloor();
}