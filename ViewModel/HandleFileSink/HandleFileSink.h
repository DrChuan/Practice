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
	// 以filename为文件名保存当前层到文件
	// （改动）将filename文件中数据加载为当前的floor(filename为"__new"时为创建新floor)
};