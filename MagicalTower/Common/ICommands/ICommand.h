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
	// ��Ҫһ�����ص�ǰfloor�ļ�������ΪUntitledXXX�����XXX
};

class IHandleFile {
public:
	virtual bool onHandleFile(std::string filename) = 0;
	// ��filenameΪ�ļ������浱ǰ�㵽�ļ�
	// ���Ķ�����filename�ļ������ݼ���Ϊ��ǰ��floor(filenameΪ"__new"ʱΪ������floor)
	// ����������filename�ļ�ɾ��
};

class IGenerate {
public:
	virtual bool onGenerate(const std::vector<int>& fileGeneList, std::string filename) = 0;
	// ��ͼ��� ��Ǯ ���� ���� ���� ��Կ�� ��Կ�� ��Կ��
};

class IGetObj {
public:
	virtual Obj onGetObj(int type, int index) = 0;    // ����type��index���ض���  type:0->��Ʒ 1->����
};

class ISetObj {
public:
	virtual void onSetObj(int type, int index, Obj object) = 0;   // ��object������Ը���(type, index)��Ӧ��Obj
};

class IGetSpeInt {
public:
	virtual int onGetSpeInt(int flag) = 0;  // 0: ��ǰ���ţ��ǵü�1��  1: �ܲ���   2: ��ͼ���
};

class IMove {
public:
	virtual int onMove(int direction) = 0;   // 0123 ��������
};

class IGetIntList {
public:
	virtual std::vector<int> onGetIntList() = 0;
};