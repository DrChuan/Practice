#pragma once
#include "ICommand.h"
class GameViewModel;

class GetEnemySink : public IGetIntList {
private:
	GameViewModel* m_gVM;
public:
	virtual std::vector<int> onGetIntList(); //���ص�ǰ�����
	GetEnemySink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};