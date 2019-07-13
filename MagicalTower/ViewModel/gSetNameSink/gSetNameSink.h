#pragma once
#include "ICommand.h"
class GameViewModel;

class gSetNameSink : public IHandleFile {
private:
	GameViewModel* m_gVM;
public:
	virtual bool onHandleFile(std::string filename);
	gSetNameSink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};
