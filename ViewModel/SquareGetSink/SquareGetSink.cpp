#include "EditorViewModel.h"

int SquareGetTSink::onUpdate(int x, int y){
	return m_eVM->getFloorSquareType(x, y);
}

int SquareGetISink::onUpdate(int x, int y){
	return m_eVM->getFloorSquareIndex(x, y);
}