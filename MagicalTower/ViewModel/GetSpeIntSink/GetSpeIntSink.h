#pragma once
#include "ICommand.h"
class GameViewModel;

class GetSpeSink : public IGetSpeInt {
private:
	GameViewModel* m_gVM;
public:
	virtual int onGetSpeInt(int flag);// 0: ��ǰ���ţ��ǵü�1��  1: �ܲ���   2: ��ͼ���
	GetSpeSink(GameViewModel* gVM) :m_gVM(gVM) {

	}
};