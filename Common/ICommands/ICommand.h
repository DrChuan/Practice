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
	// ��Ҫһ�����ص�ǰfloor_ws�ļ�������ΪUntitledXXX�����XXX
};

class IHandleFile {
public:
	virtual void onHandleFile(std::string filename) = 0;
	// ��filenameΪ�ļ������浱ǰ�㵽�ļ�
	// ���Ķ�����filename�ļ������ݼ���Ϊ��ǰ��floor(filenameΪ"__new"ʱΪ������floor)
};