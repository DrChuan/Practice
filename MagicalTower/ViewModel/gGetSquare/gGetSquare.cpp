#include "GameViewModel.h"

int gGetSquareTSink::onUpdate(int x, int y) {
	return m_gVM->gm->getSquareType(x, y);
}

int gGetSquareISink::onUpdate(int x, int y) {
	return m_gVM->gm->getSquareIndex(x, y);
}
