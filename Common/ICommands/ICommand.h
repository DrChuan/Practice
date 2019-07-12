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
	virtual void onGenerate(const std::vector<int>& fileGeneList, std::string filename) = 0;
	// ��ͼ��� ��Ǯ ���� ���� ���� ��Կ�� ��Կ�� ��Կ��
};