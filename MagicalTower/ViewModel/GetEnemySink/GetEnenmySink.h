#pragma once
#include "ICommand.h"
class GameViewModel;

class GetEnemySink : public IGetIntList {
private:
	GameViewModel* m_gVM;
public:
	virtual std::vector<int> onGetIntList(); //传回当前层怪物
	GetEnemySink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};