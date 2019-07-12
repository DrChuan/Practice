#pragma once
#include "ICommand.h"
class EditorViewModel;

class GenerateGameSink : public IGenerate {
private:
	EditorViewModel* m_eVM;
public:
	virtual void onGenerate(const std::vector<int>& fileGeneList, std::string filename);
	GenerateGameSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
	// 以filename为文件名保存当前层到文件
};
