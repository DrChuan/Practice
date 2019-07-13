#pragma once
#include "ICommand.h"
class GameViewModel;

class gGetSquareTSink : public ISquareGet {
private:
	GameViewModel* m_gVM;
public:
	virtual int onUpdate(int, int);
	gGetSquareTSink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};

class gGetSquareISink : public ISquareGet {
private:
	GameViewModel* m_gVM;
public:
	virtual int onUpdate(int, int);
	gGetSquareISink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};