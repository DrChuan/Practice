#pragma once
#include "ICommand.h"
class GameViewModel;

class MoveSink : public IMove {
private:
	GameViewModel* m_gVM;
public:
	virtual int onMove(int flag);
	MoveSink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};