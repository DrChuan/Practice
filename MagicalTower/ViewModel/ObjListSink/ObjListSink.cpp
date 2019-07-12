#include "EditorViewModel.h"
#include "ListMember.h"

Obj GetObjSink::onGetObj(int type, int index) {
	return m_eVM->getObj(type, index);
}

void SetObjSink::onSetObj(int type, int index, Obj object) {
	if (type == 1) m_eVM->ChangeEnemyList(object.getAtk(), object.getDef(), object.getHp(), object.getExp(), object.getCoins(), index);
	else m_eVM->ChangeItemList(object.getHp(), object.getAtk(), object.getDef(), object.getExp(), object.getCoins(), index);
}