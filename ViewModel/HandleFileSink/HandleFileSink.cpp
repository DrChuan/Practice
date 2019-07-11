#pragma once
#include "EditorViewModel.h"

void HandleFileSink::onHandleFile(std::string filename) {
	if (filename != "__new") {
		m_eVM->setFloorName("Focused Floor");
		m_eVM->resetFloor();
	}
	else {
		m_eVM->setFloorName(filename);
		m_eVM->loadFloor();
	}
}
