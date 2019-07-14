#pragma once
#include "ICommand.h"
class GameViewModel;

class gLoadSink : public IHandleFile {
private:
	GameViewModel* m_gVM;
public:
	virtual bool onHandleFile(std::string filename);
	gLoadSink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};