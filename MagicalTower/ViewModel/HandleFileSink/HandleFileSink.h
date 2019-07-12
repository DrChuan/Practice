#pragma once
#include "ICommand.h"
#include <string>
class EditorViewModel;

class HandleLFileSink:public IHandleFile {
private:
	EditorViewModel* m_eVM;
public:
	virtual bool onHandleFile(std::string filename);
	HandleLFileSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
	// ���Ķ�����filename�ļ������ݼ���Ϊ��ǰ��floor(filenameΪ"__new"ʱΪ������floor)
};

class HandleRFileSink :public IHandleFile {
private:
	EditorViewModel* m_eVM;
public:
	virtual bool onHandleFile(std::string filename);
	HandleRFileSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
	// ��filenameΪ�ļ������浱ǰ�㵽�ļ�
};

class HandleDFileSink :public IHandleFile {
private:
	EditorViewModel* m_eVM;
public:
	virtual bool onHandleFile(std::string filename);
	HandleDFileSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
	// ����filenameΪ�ļ������ļ�ɾ��
};