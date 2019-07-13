#include  "GameViewModel.h"

int MoveSink::onMove(int direction) {
	return m_gVM->move(direction);
}