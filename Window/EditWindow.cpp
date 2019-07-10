#include "EditWindow.h"
#include <iostream>

// 构造函数
EditWindow::EditWindow(EditorViewModel *edvm, QWidget *parent) : QMainWindow(parent)
{
	// 初始化窗口标题，大小，背景
	initWindow();
	// 初始化ViewModel指针
	editorViewModel = edvm;
	// 初始化冰、火、林按钮
	initBackSetBtn();
	// 初始化元件栏按钮
	initItemBtn();	
	initEnemyBtn();
	initGameBtn();
	// 初始化选择框属性
	initSelectFrame();
	// 初始化地图编辑区域
	initDrawPlace();
	initDrawObj();
	// 初始化帮助按钮
	initHelpBoardBtn();
	// 初始化图块显示组件
	initSquarePic();
	// 设置鼠标事件响应方式
	setMouseTracking(true);
}

// 普通函数
void EditWindow::initWindow()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	setWindowTitle(codec->toUnicode("魔塔关卡设计"));
	setFixedSize(1024, 768);
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/editbackice.jpg")));
	this->setPalette(p);
}

void EditWindow::initBackSetBtn()
{
	// 字体设置及中文支持
	QFont font;
	font.setFamily("SimHei");   // 黑体
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	btIce.setFont(font);
	btFire.setFont(font);
	btLeaf.setFont(font);
	// 设置按钮背景色
	QPalette p;
	p = btIce.palette();
	p.setColor(QPalette::Button, QColor(105, 160, 255, 160));
	btIce.setPalette(p);
	btIce.setAutoFillBackground(true);
	p = btFire.palette();
	p.setColor(QPalette::Button, QColor(244, 30, 30, 160));
	btFire.setPalette(p);
	btFire.setAutoFillBackground(true);
	p = btLeaf.palette();
	p.setColor(QPalette::Button, QColor(30, 255, 45, 160));
	btLeaf.setPalette(p);
	btLeaf.setAutoFillBackground(true);
	btIce.setFlat(true);
	btFire.setFlat(true);
	btLeaf.setFlat(true);
	// 设置parent指针
	btIce.setParent(this);
	btFire.setParent(this);
	btLeaf.setParent(this);
	// 设置按钮文字
	btIce.setText(codec->toUnicode("冰"));
	btFire.setText(codec->toUnicode("火"));
	btLeaf.setText(codec->toUnicode("林"));
	// 显示按钮
	btIce.show();
	btFire.show();
	btLeaf.show();
	// 设置按钮大小及位置
	btIce.resize(100, 36);
	btIce.move(375, 705);
	btFire.resize(100, 36);
	btFire.move(525, 705);
	btLeaf.resize(100, 36);
	btLeaf.move(675, 705);
	// 设置按钮信号槽
	connect(&btIce, SIGNAL(clicked()), this, SLOT(setIce()));
	connect(&btFire, SIGNAL(clicked()), this, SLOT(setFire()));
	connect(&btLeaf, SIGNAL(clicked()), this, SLOT(setLeaf()));
	btIce.setDown(true);
}

void EditWindow::initItemBtn()
{
	QSignalMapper *qsm = new QSignalMapper(this);
	for (int i = 0; i < 20; i++)
	{
		items[i].setParent(this);                                            // 设置parent指针
		items[i].setGeometry(48 + 48 * (i % 5), 48 + 48 * (i / 5), 48, 48);  // 设置大小及位置
		items[i].setIcon(QIcon(QPixmap("img/item/item" + QString::number(i))));   // 设置图标
		items[i].setIconSize(QSize(48, 48));                                 // 设置图标大小
		items[i].setFlat(true);                                              // 原按钮图案不可见
		items[i].show();
		connect(&items[i], SIGNAL(clicked()), qsm, SLOT(map()));             // 设置信号槽
		qsm->setMapping(&items[i], i);
	}
	connect(qsm, SIGNAL(mapped(int)), this, SLOT(clickItem(int)));
}

void EditWindow::initEnemyBtn()
{
	QSignalMapper *qsm = new QSignalMapper(this);
	for (int i = 0; i < 25; i++)
	{
		enemies[i].setParent(this);
		enemies[i].setGeometry(48 + 48 * (i % 5), 48 + DIS_IT_TO_ENM + 48 * (i / 5), 48, 48);
		enemies[i].setIcon(QIcon(QPixmap("img/enemy/enemy" + QString::number(i))));
		enemies[i].setIconSize(QSize(48, 48));
		enemies[i].setFlat(true);
		enemies[i].show();
		connect(&enemies[i], SIGNAL(clicked()), qsm, SLOT(map()));
		qsm->setMapping(&enemies[i], i);
	}
	connect(qsm, SIGNAL(mapped(int)), this, SLOT(clickEnemy(int)));
}

void EditWindow::initGameBtn()
{
	QSignalMapper *qsm = new QSignalMapper(this);
	for (int i = 0; i < 15; i++)
	{
		games[i].setParent(this);
		games[i].setGeometry(48 + 48 * (i % 5), 48 + DIS_IT_TO_GM + 48 * (i / 5), 48, 48);
		games[i].setIcon(QIcon(QPixmap("img/game/game" + QString::number(i))));
		games[i].setIconSize(QSize(48, 48));
		games[i].setFlat(true);
		games[i].show();
		connect(&games[i], SIGNAL(clicked()), qsm, SLOT(map()));
		qsm->setMapping(&games[i], i);
	}
	connect(qsm, SIGNAL(mapped(int)), this, SLOT(clickGame(int)));
}

void EditWindow::initSelectFrame()
{
	selectFrame.setParent(this);
	selectFrame.setPixmap(QPixmap("img/system/selectFrame.png"));
	selectFrame.move(48, 48);
	selectFrame.show();	items[0].setParent(this);
	selectFrame.raise();
	selectFrame.setFixedSize(48, 48);
}

void EditWindow::initDrawPlace()
{
	drawPlace.setParent(this);
	drawPlace.show();
	drawPlace.setGeometry(311, 145, 48 * 11, 48 * 11);
	QPalette p = drawPlace.palette();
	p.setColor(QPalette::Background, QColor(255, 0, 0, 0));
	drawPlace.setAutoFillBackground(true);
	drawPlace.setPalette(p);
	drawPlace.setCursor(QCursor(QPixmap("img/item/item0.png")));
	drawPlace.setMouseTracking(true);
	connect(&drawPlace, SIGNAL(moving(int, int)), this, SLOT(updateDrawObj(int, int)));
}

void EditWindow::initDrawObj()
{
	drawObj.setParent(this);
	drawObj.setGeometry(0, 0, 48, 48);
	drawObj.setIcon(QIcon(QPixmap("img/item/item0.png")));
	drawObj.setIconSize(QSize(48, 48));
	drawObj.setFlat(true);
	drawObj.setCursor(QCursor(QPixmap("img/item/item0.png")));
	QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect;
	drawObj.setGraphicsEffect(opacityEffect);
	opacityEffect->setOpacity(0.65);
	connect(&drawObj, SIGNAL(clicked()), this, SLOT(putSquare()));
}

void EditWindow::initHelpBoardBtn()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	helpBoardBtn.setParent(this);
	helpBoardBtn.setText(codec->toUnicode("说明书"));
	helpBoardBtn.show();
	helpBoardBtn.setGeometry(900, 700, 100, 32);
	connect(&helpBoardBtn, SIGNAL(clicked()), this, SLOT(clickHelpBoardBtn()));
}

void EditWindow::initSquarePic()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			squaresPic[i][j].setParent(this);
			squaresPic[i][j].setGeometry(311 + i * 48, 145 + j * 48, 48, 48);
			squaresPic[i][j].setPixmap(QPixmap(getImgName(editorViewModel->getFloorSquareType(i, j), 
				                                          editorViewModel->getFloorSquareIndex(i, j))));
			squaresPic[i][j].show();
			squaresPic[i][j].lower();
		}
	}
}

void EditWindow::setFramePos()
{
	if (index < 20)
		selectFrame.setGeometry(48 + 48 * (index % 5), 48 + 48 * (index / 5), 48, 48);
	else if (index < 45)
		selectFrame.setGeometry(48 + 48 * (index % 5), 48 + DIS_IT_TO_ENM - 48 * 4 + 48 * (index / 5), 48, 48);
	else
		selectFrame.setGeometry(48 + 48 * (index % 5), 48 + DIS_IT_TO_GM - 48 * 9 + 48 * (index / 5), 48, 48);
}

void EditWindow::update()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			squaresPic[i][j].setPixmap(QPixmap(getImgName(editorViewModel->getFloorSquareType(i, j),
				                                          editorViewModel->getFloorSquareIndex(i, j))));
		}
	}
}

int EditWindow::getIndex()
{
	return index;
}

int EditWindow::getMap()
{
	return map;
}

int EditWindow::getType()
{
	if (index < 20)
		return 0;
	else if (index < 45)
		return 1;
	else
		return 0;
}

int EditWindow::getId()
{
	if (index < 20)
		return index;
	else if (index < 45)
		return index - 20;
	else
		return index - 25;
}

QString EditWindow::getImgName(int type, int index)
{
	QString ret;
	if (type == 0)
		if (index < 20)
			ret = "img/item/item" + QString::number(index);
		else
			ret = "img/game/game" + QString::number(index - 20);
	if (type == 1)
		ret = "img/enemy/enemy" + QString::number(index);
	return ret;
}

void EditWindow::mouseMoveEvent(QMouseEvent *e)
{
	drawObj.hide();
}



// slots函数
void EditWindow::setIce()
{
	map = 0;
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/editbackice.jpg")));
	this->setPalette(p);
	btIce.setDown(true);
}

void EditWindow::setFire()
{
	map = 1;
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/editbackfire.jpg")));
	this->setPalette(p);
	btFire.setDown(true);
}

void EditWindow::setLeaf()
{
	map = 2;
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/editbackleaf.jpg")));
	this->setPalette(p);
	btLeaf.setDown(true);
}

void EditWindow::clickItem(int id)
{
	index = id;
	drawPlace.setCursor(QCursor(QPixmap("img/item/item" + QString::number(id))));
	drawObj.setCursor(QCursor(QPixmap("img/item/item" + QString::number(id))));
	drawObj.setIcon(QIcon(QPixmap("img/item/item" + QString::number(id))));
	setFramePos();
}

void EditWindow::clickEnemy(int id)
{
	index = id + 20;
	drawPlace.setCursor(QCursor(QPixmap("img/enemy/enemy" + QString::number(id))));
	drawObj.setCursor(QCursor(QPixmap("img/enemy/enemy" + QString::number(id))));
	drawObj.setIcon(QIcon(QPixmap("img/enemy/enemy" + QString::number(id))));
	setFramePos();
}

void EditWindow::clickGame(int id)
{
	index = id + 45;
	drawPlace.setCursor(QCursor(QPixmap("img/game/game" + QString::number(id))));
	drawObj.setCursor(QCursor(QPixmap("img/game/game" + QString::number(id))));
	drawObj.setIcon(QIcon(QPixmap("img/game/game" + QString::number(id))));
	setFramePos();
}

void EditWindow::updateDrawObj(int x, int y)
{
	drawObj.show();
	drawObj.move(((x - 311) / 48) * 48 + 311, ((y - 145) / 48) * 48 + 145);
}

void EditWindow::clickHelpBoardBtn()
{
	helpBoard = new HelpBoard();
}

void EditWindow::putSquare()
{
	int type, id;
	if (index == 59)
		type = -1, id = 0;
	else
		type = getType(), id = getId();
	std::cout << "put!" << getType() << getId() << (drawObj.x() - 311) / 48 << (drawObj.y() - 145) / 48 << std::endl;
	editorViewModel->setFloorSquare((drawObj.x() - 311) / 48, (drawObj.y() - 145) / 48, type, id);
	update();
}