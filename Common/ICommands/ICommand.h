#pragma once

class ISquareGet {
public:
	virtual int onUpdate(int, int) = 0;
};

class ISquareSet {
public:
	virtual void onSquareChange(int, int, int, int) = 0;
};

class IGetInt {
public:
	virtual int onCallInt() = 0;
	// 需要一个返回当前floor_ws文件夹下名为UntitledXXX的最大XXX
};

class IHandleFile {
public:
	virtual void onHandleFile(std::string filename) = 0;
	// 以filename为文件名保存当前层到文件
	// （改动）将filename文件中数据加载为当前的floor(filename为"__new"时为创建新floor)
};