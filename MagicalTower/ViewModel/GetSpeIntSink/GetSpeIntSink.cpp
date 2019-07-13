#include "GameViewModel.h"

int GetSpeSink::onGetSpeInt(int flag) {// 0: 当前层编号（不记得加1）  1: 总层数   2: 地图风格
	switch (flag) {
	case 0: return m_gVM->gm->getIndex() + 1;
	case 1: return m_gVM->gm->getFloorSetSize();
	case 2: return m_gVM->gm->getStyle();
	case 3: return m_gVM->gm->getX();
	case 4: return m_gVM->gm->getY();
	default: return -1;
	}
}
