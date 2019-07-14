#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ListMember.h"

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
	virtual bool onGenerate(const std::vector<int>& fileGeneList, std::string filename) = 0;
	// 地图风格 金钱 生命 攻击 防御 黄钥匙 蓝钥匙 红钥匙
};

class IGetObj {
public:
	virtual Obj onGetObj(int type, int index) = 0;    // 根据type和index返回对象  type:0->物品 1->敌人
};

class ISetObj {
public:
	virtual void onSetObj(int type, int index, Obj object) = 0;   // 将object存的属性赋给(type, index)对应的Obj
};

class IGetSpeInt {
public:
	virtual int onGetSpeInt(int flag) = 0;  // 0: 当前层编号（记得加1）  1: 总层数   2: 地图风格
};

class IMove {
public:
	virtual int onMove(int direction) = 0;   // 0123 上下左右
};

class IGetIntList {
public:
	virtual std::vector<int> onGetIntList() = 0;
};