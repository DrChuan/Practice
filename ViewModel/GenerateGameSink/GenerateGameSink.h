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
	// ��filenameΪ�ļ������浱ǰ�㵽�ļ�
};
