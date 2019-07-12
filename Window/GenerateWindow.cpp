#include "GenerateWindow.h"
#include "EditWindow.h"

GenerateWindow::GenerateWindow()
{
	setFixedSize(800, 600);
	initBtn(&add , 100, 100, 120, 32, "添加这一层 >");
	initBtn(&del , 250, 100, 120, 32, "< 移除这一层");
	initBtn(&up  , 400, 100, 120, 32, "移至更低层 ↑");
	initBtn(&down, 550, 100, 120, 32, "移至更高层 ↓");
	initBtn(&generate, 300, 550, 120, 32, "生成游戏");
	initBtn(&setInitModel, 450, 550, 120, 32, "设置初始属性");
	connect(&add,  SIGNAL(clicked()), this, SLOT(clickAdd()));
	connect(&del,  SIGNAL(clicked()), this, SLOT(clickDel()));
	connect(&up,   SIGNAL(clicked()), this, SLOT(clickUp()));
	connect(&down, SIGNAL(clicked()), this, SLOT(clickDown()));
	
	connect(&setInitModel, SIGNAL(clicked()), this, SLOT(clickSetInitModel()));
}

void GenerateWindow::initialize(EditWindow *ptr)
{
	ptrParent = ptr;
	connect(&generate, SIGNAL(clicked()), ptrParent, SLOT(generateOk()));
	setWindowTitle(cdc->toUnicode("魔塔关卡设计"));
	originList.clear();
	selectedList.clear();
	for (int i = 0; i < ptrParent->pFloorFileSet->getSize(); i++)
		originList.push_back(ptrParent->pFloorFileSet->getFilename(i));
	add.setEnabled(false);
	up.setEnabled(false);
	down.setEnabled(false);
	del.setEnabled(false);
	initList();
}

void GenerateWindow::initBtn(QPushButton *btn, int x, int y, int width, int height, string text)
{
	btn->setParent(this);
	btn->setText(cdc->toUnicode(text.data()));
	btn->setGeometry(x, y, width, height);
	btn->show();
}

void GenerateWindow::initList()
{
	leftList.setParent(this);
	rightList.setParent(this);
	leftList.setGeometry(40, 140, 300, 400);
	rightList.setGeometry(370, 140, 300, 400);
	leftList.show();
	rightList.show();
	leftIndex = -1;
	rightIndex = -1;
	updateList();
	connect(&leftList, SIGNAL(currentRowChanged(int)), this, SLOT(changeLeft(int)));
	connect(&rightList, SIGNAL(currentRowChanged(int)), this, SLOT(changeRight(int)));
}

void GenerateWindow::updateList()
{
	leftList.clear();
	rightList.clear();
	for (int i = 0; i < originList.size(); i++)
		leftList.addItem(QString::fromLocal8Bit(originList[i].c_str()));
	for (int i = 0; i < selectedList.size(); i++)
		rightList.addItem(QString::fromLocal8Bit(selectedList[i].c_str()));
}

void GenerateWindow::setInitialModel(int gold, int hp, int atk, int def, int ykey, int bkey, int rkey)
{
	initModel[1] = gold;
	initModel[2] = hp;
	initModel[3] = atk;
	initModel[4] = def;
	initModel[5] = ykey;
	initModel[6] = bkey;
	initModel[7] = rkey;
}

vector<int> GenerateWindow::getInitialModel()
{
	return initModel;
}

vector<string> GenerateWindow:: getList()
{
	return selectedList;
}

void GenerateWindow::clickAdd()
{
	if (leftIndex < 0 || leftIndex >= originList.size())
	{
		return;
	}
	add.setEnabled(false);
	selectedList.push_back(originList[leftIndex]);
	originList.erase(std::begin(originList) + leftIndex);
	originList.shrink_to_fit();
	updateList();
}

void GenerateWindow::clickDel()
{
	if (rightIndex < 0 || rightIndex >= selectedList.size())
	{
		return;
	}
	del.setEnabled(false);
	originList.push_back(selectedList[rightIndex]);
	selectedList.erase(std::begin(selectedList) + rightIndex);
	selectedList.shrink_to_fit();
	updateList();
}

void GenerateWindow::clickUp()
{
	string t = selectedList[rightIndex];
	selectedList[rightIndex] = selectedList[rightIndex - 1];
	selectedList[rightIndex - 1] = t;
	updateList();
}

void GenerateWindow::clickDown()
{
	string t = selectedList[rightIndex];
	selectedList[rightIndex] = selectedList[rightIndex + 1];
	selectedList[rightIndex + 1] = t;
	updateList();
}

void GenerateWindow::clickSetInitModel()
{
	setInitModelWindow.initialize(this);
	setInitModelWindow.setModal(true);
	setInitModelWindow.show();
}

void GenerateWindow::changeLeft(int id)
{
	if(id != -1)
		add.setEnabled(true);
	leftIndex = leftList.currentRow();
	std::cout << leftIndex << std::endl;
}

void GenerateWindow::changeRight(int id)
{
	rightIndex = id;
	up.setEnabled(true);
	down.setEnabled(true);
	if (rightIndex != -1)
		del.setEnabled(true);
	if (rightIndex <= 0)
		up.setEnabled(false);
	if (rightIndex == selectedList.size() - 1 || rightIndex == -1)
		down.setEnabled(false);
}

void GenerateWindow::setModelOk()
{
	initModel[1] = setInitModelWindow.gold.value();
	initModel[2] = setInitModelWindow.hp.value();
	initModel[3] = setInitModelWindow.atk.value();
	initModel[4] = setInitModelWindow.def.value();
	initModel[5] = setInitModelWindow.yelloKey.value();
	initModel[6] = setInitModelWindow.blueKey.value();
	initModel[7] = setInitModelWindow.redKey.value();
	setInitModelWindow.close();
}

void GenerateWindow::setModelReset()
{
	initModel[1] = 0;
	initModel[2] = 1000;
	initModel[3] = 10;
	initModel[4] = 5;
	initModel[5] = 1;
	initModel[6] = 1;
	initModel[7] = 1;
	setInitModelWindow.initialize(this);
}