#include "GameViewModel.h"

Obj gGetObjSink::onGetObj(int type, int index) {
	return m_gVM->gm->getObj(type, index);
}