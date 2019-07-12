#include "GenerateWindow.h"
#include "EditWindow.h"

GenerateWindow::GenerateWindow()
{
	setFixedSize(800, 600);
	initBtn(&add , 100, 100, 120, 32, "�����һ�� >");
	initBtn(&del , 250, 100, 120, 32, "< �Ƴ���һ��");
	initBtn(&up  , 400, 100, 120, 32, "�������Ͳ� ��");
	initBtn(&down, 550, 100, 120, 32, "�������߲� ��");
	initBtn(&generate, 300, 550, 120, 32, "������Ϸ");
	connect(&add,  SIGNAL(clicked()), this, SLOT(clickAdd()));
	connect(&del,  SIGNAL(clicked()), this, SLOT(clickDel()));
	connect(&up,   SIGNAL(clicked()), this, SLOT(clickUp()));
	connect(&down, SIGNAL(clicked()), this, SLOT(clickDown()));
}

void GenerateWindow::initialize(EditWindow *ptr)
{
	ptrParent = ptr;
	setWindowTitle(cdc->toUnicode("ħ���ؿ����"));
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

void GenerateWindow::clickGenerate()
{
	// �����麯��
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
