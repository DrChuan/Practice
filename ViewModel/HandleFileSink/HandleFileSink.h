#pragma once
#include "ICommand.h"
#include <string>
class EditorViewModel;

class HandleFileSink:public IHandleFile {
private:
	EditorViewModel* m_eVM;
public:
	virtual void onHandleFile(std::string filename);
	HandleFileSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
	// ��filenameΪ�ļ������浱ǰ�㵽�ļ�
	// ���Ķ�����filename�ļ������ݼ���Ϊ��ǰ��floor(filenameΪ"__new"ʱΪ������floor)
};