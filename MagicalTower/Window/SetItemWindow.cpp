#include "SetItemWindow.h"
#include "EditWindow.h"
void SetItemWindow::initialize(EditWindow *ptr, int _type, int _id)
{
	ptrParent = ptr;
	type = _type;
	id = _id;
	setWindowTitle(codec->toUnicode("��������"));
	setFixedSize(250, 300);
	setModal(true);
	if (ptr->iGetObj)
	{
		data[1] = ptr->iGetObj->onGetObj(type, id).getHp();
		data[2] = ptr->iGetObj->onGetObj(type, id).getAtk();
		data[3] = ptr->iGetObj->onGetObj(type, id).getDef();
		data[4] = ptr->iGetObj->onGetObj(type, id).getExp();
	}
	for (int i = 0; i < 5; i++)
	{
		dataBox[i].setParent(this);
		dataBox[i].setGeometry(105, 30 + 40 * i, 110, 32);
		dataBox[i].show();
		dataBox[i].setValue(data[i]);
		dataBox[i].setMinimum(0);
		dataBox[i].setMaximum(100000);
		dataLabel[i].setParent(this);
		dataLabel[i].show();
		dataLabel[i].setGeometry(24, 32 + 40 * i, 64, 32);
	}
	dataLabel[0].setText(codec->toUnicode("���ӽ�Ǯ"));
	dataLabel[1].setText(codec->toUnicode("��������"));
	dataLabel[2].setText(codec->toUnicode("���ӹ���"));
	dataLabel[3].setText(codec->toUnicode("���ӷ���"));
	dataLabel[4].setText(codec->toUnicode("���Ӿ���"));
	ok.setParent(this);
	ok.show();
	ok.setGeometry(30, 250, 90, 32);
	ok.setText(codec->toUnicode("ȷ��"));
	cancel.setParent(this);
	cancel.show();
	cancel.setGeometry(145, 250, 90, 32);
	cancel.setText(codec->toUnicode("ȡ��"));
}

void SetItemWindow::initSignalSlot()
{
	connect(&ok, SIGNAL(clicked()), ptrParent, SLOT(setItemOk()));
	connect(&cancel, SIGNAL(clicked()), ptrParent, SLOT(setItemCancel()));
}

int SetItemWindow::getData(int id)
{
	return dataBox[id].value();
}