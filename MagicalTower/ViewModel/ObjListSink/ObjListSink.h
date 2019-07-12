#include "ICommand.h"
class EditorViewModel;

class GetObjSink :public IGetObj {
private:
	EditorViewModel* m_eVM;
public:
	virtual Obj onGetObj(int type, int index);
	GetObjSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
};

class SetObjSink :public ISetObj {
private:
	EditorViewModel* m_eVM;
public:
	virtual void onSetObj(int type, int index, Obj obj);
	SetObjSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
};