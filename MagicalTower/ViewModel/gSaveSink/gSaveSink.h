#include "ICommand.h"
class GameViewModel;

class gSaveSink : public IHandleFile {
private:
	GameViewModel* m_gVM;
public:
	virtual bool onHandleFile(std::string filename);
	gSaveSink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};