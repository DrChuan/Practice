#pragma once
#include "ICommand.h"
class GameViewModel;

class gGetObjSink : public IGetObj {
private:
	GameViewModel* m_gVM;
public:
	virtual Obj onGetObj(int type, int index); //���ص�ǰ�����
	gGetObjSink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};