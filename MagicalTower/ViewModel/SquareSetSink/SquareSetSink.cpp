#include "EditorViewModel.h"

void SquareSetSink::onSquareChange(int x, int y, int type, int index) {
	m_eVM->setFloorSquare(x, y,type, index);
}