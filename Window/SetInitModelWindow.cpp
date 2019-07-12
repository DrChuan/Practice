#include "SetInitModelWindow.h"

#include "GenerateWindow.h"

void SetInitModelWindow::initialize(GenerateWindow *parent)
{
	setFixedSize(460, 320);
	ptr = parent;
	setWindowTitle(codec->toUnicode("设置初始属性"));
	initBox(gold, 0, 100000, ptr->getInitialModel()[1], 120, 60);
	initBox(hp, 1, 100000, ptr->getInitialModel()[2], 120, 100);
	initBox(atk, 0, 100000, ptr->getInitialModel()[3], 120, 140);
	initBox(def, 0, 100000, ptr->getInitialModel()[4], 120, 180);
	initBox(yelloKey, 0, 1000, ptr->getInitialModel()[5], 330, 75);
	initBox(blueKey, 0, 1000, ptr->getInitialModel()[6], 330, 115);
	initBox(redKey, 0, 1000, ptr->getInitialModel()[7], 330, 155);
	for (int i = 0; i < 4; i++)
	{
		label[i].setText(labelName[i]);
		label[i].setGeometry(44, 50 + 40 * i, 80, 40);
		label[i].setParent(this);
		label[i].show();
	}
	for (int i = 4; i < 7; i++)
	{
		label[i].setText(labelName[i]);
		label[i].setGeometry(240, 65 + 40 *(i-4), 80, 40);
		label[i].setParent(this);
		label[i].show();
	}
	ok.setParent(this);
	ok.show();
	ok.setText(codec->toUnicode("确定"));
	ok.setGeometry(120, 270, 120, 32);
	connect(&ok, SIGNAL(clicked()), ptr, SLOT(setModelOk()));
	reset.setParent(this);
	reset.show();
	reset.setText(codec->toUnicode("重置"));
	reset.setGeometry(320, 270, 120, 32);
	connect(&reset, SIGNAL(clicked()), ptr, SLOT(setModelReset()));
}

void SetInitModelWindow::initBox(QSpinBox & box, int min, int max, int init, int x, int y)
{
	box.setParent(this);
	box.show();
	box.move(x, y);
	box.setMaximum(max);
	box.setMinimum(min);
	box.setValue(init);
	box.setFixedWidth(90);
}
