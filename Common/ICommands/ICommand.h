#pragma once
#include <string>
#include <iostream>
#include <vector>

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
	// 需要一个返回当前floor文件夹下名为UntitledXXX的最大XXX
};

class IHandleFile {
public:
	virtual bool onHandleFile(std::string filename) = 0;
	// 以filename为文件名保存当前层到文件
	// （改动）将filename文件中数据加载为当前的floor(filename为"__new"时为创建新floor)
	// （新增）将filename文件删除
};

class IGenerate {
public:
	virtual void onGenerate(const std::vector<int>& fileGeneList, std::string filename) = 0;
	// 地图风格 金钱 生命 攻击 防御 黄钥匙 蓝钥匙 红钥匙
};