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
	// （改动）将filename文件中数据加载为当前的floor(filename为"__new"时为创建新floor)
};

class HandleRFileSink :public IHandleFile {
private:
	EditorViewModel* m_eVM;
public:
	virtual bool onHandleFile(std::string filename);
	HandleRFileSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
	// 以filename为文件名保存当前层到文件
};

class HandleDFileSink :public IHandleFile {
private:
	EditorViewModel* m_eVM;
public:
	virtual bool onHandleFile(std::string filename);
	HandleDFileSink(EditorViewModel* eVM) :m_eVM(eVM) {

	}
	// 将以filename为文件名的文件删除
};