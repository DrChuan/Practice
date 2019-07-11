#include "ICommand.h"
#include <string>
class EditorViewModel;

class SquareSetSink : public ISquareSet {
private:
	EditorViewModel* m_eVM;
public:
	virtual void onSquareChange(int x, int y, int type, int index);
	SquareSetSink(EditorViewModel* eVM) :m_eVM(eVM) {
	
	}
};