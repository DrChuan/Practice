#pragma once
#include "ICommand.h"
class GameViewModel;

class GetSpeSink : public IGetSpeInt {
private:
	GameViewModel* m_gVM;
public:
	virtual int onGetSpeInt(int flag);// 0: 当前层编号（记得加1）  1: 总层数   2: 地图风格
	GetSpeSink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};