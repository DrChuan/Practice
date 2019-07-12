#pragma once
#include "ICommand.h"
class EditorViewModel;

class IGetSink:public IGetInt {
public:
	virtual int onCallInt();
};