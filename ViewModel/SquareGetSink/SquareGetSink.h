#pragma once
#include "ISquareGet.h"
class EditorViewModel;

class SquareGetTSink : public ISquareGet {
private:
	EditorViewModel* m_eVM;
public:
	virtual int onUpdate(int, int);
	SquareGetTSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
};

class SquareGetISink : public ISquareGet {
private:
	EditorViewModel* m_eVM;
public:
	virtual int onUpdate(int, int);
	SquareGetISink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
};