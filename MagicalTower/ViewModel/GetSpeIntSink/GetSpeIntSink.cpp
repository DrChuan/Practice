#include "GameViewModel.h"

int GetSpeSink::onGetSpeInt(int flag) {// 0: ��ǰ���ţ����ǵü�1��  1: �ܲ���   2: ��ͼ���
	switch (flag) {
	case 0: return m_gVM->gm->getIndex() + 1;
	case 1: return m_gVM->gm->getFloorSetSize();
	case 2: return m_gVM->gm->getStyle();
	case 3: return m_gVM->gm->getX();
	case 4: return m_gVM->gm->getY();
	default: return -1;
	}
}
