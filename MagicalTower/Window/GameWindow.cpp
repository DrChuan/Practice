#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent), initGameWindow(this)
{
	setFixedSize(1024, 768);
	setWindowTitle(codec->toUnicode("魔塔"));
	QPalette p = palette();

	
	setPalette(p);
	
	initButton();
	initGame();
	initSquare();
	initData();	
}

void GameWindow::initButton()
{
	saveBtn.setParent(this);
	saveBtn.setText(codec->toUnicode("保存\n进度"));
	saveBtn.setGeometry(820, 55, 68, 68);
	saveBtn.show();
	saveBtn.setFocusPolicy(Qt::NoFocus);
	loadBtn.setParent(this);
	loadBtn.setText(codec->toUnicode("读取\n进度"));
	loadBtn.setGeometry(905, 55, 68, 68);
	loadBtn.show();
	loadBtn.setFocusPolicy(Qt::NoFocus);
	initGameBtn.setParent(this);
	initGameBtn.setText(codec->toUnicode("读取其他游戏"));
	initGameBtn.setGeometry(450, 700, 140, 40);
	initGameBtn.show();
	initGameBtn.setFocusPolicy(Qt::NoFocus);
	connect(&saveBtn, SIGNAL(clicked()), this, SLOT(clickSave()));
	connect(&loadBtn, SIGNAL(clicked()), this, SLOT(clickLoad()));
	connect(&initGameBtn, SIGNAL(clicked()), this, SLOT(clickInitGame()));
}

void GameWindow::initSquare()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			squares[i][j].setParent(this);
			squares[i][j].setGeometry(241 + i * 48, 146 + j * 48, 48, 48);
			if (isgt && isgi) squares[i][j].setPixmap(QPixmap(getImgName(isgt->onUpdate(i, j), isgi->onUpdate(i, j))));
			squares[i][j].show();
			squares[i][j].lower();
		}
	}
	int x, y;
	if (iGetSpecialInt)
	{
		x = iGetSpecialInt->onGetSpeInt(3);
		y = iGetSpecialInt->onGetSpeInt(4);
	}
	squares[x][y].setPixmap(QPixmap("img/system/hero.png"));
}

void GameWindow::updateSquare(int ox, int oy, int nx, int ny)
{
	if (isgt && isgi)
		squares[ox][oy].setPixmap(QPixmap(getImgName(isgt->onUpdate(ox, oy), isgi->onUpdate(ox, oy))));
	squares[nx][ny].setPixmap(QPixmap("img/system/hero.png"));
}

void GameWindow::initData()
{
	setData();
	QFont font;
	font.setPointSize(14);
	font.setFamily("SimHei");
	QPalette pt;
	pt.setColor(QPalette::WindowText, Qt::white);
	for (int i = 0; i < 6; i++)
	{
		model[i].setGeometry(120, 111 + 42 * i, 120, 32);
		model[i].setParent(this);
		model[i].show();
		model[i].setText(QString::number(data[i]));
		model[i].setFont(font);
		model[i].setPalette(pt);
	}
	for (int i = 6; i < 9; i++)
	{
		model[i].setGeometry(100, 80 + 49 * i, 120, 32);
		model[i].setParent(this);
		model[i].show();
		model[i].setText(QString::number(data[i]));
		model[i].setFont(font);
		model[i].setPalette(pt);
	}
	heroName.setGeometry(80, 30, 200, 32);
	heroName.setParent(this);
	heroName.show();
	heroName.setText(_heroName);
	heroName.setFont(font);
	heroName.setPalette(pt);
	layerNum.setGeometry(456, 97, 64, 32);
	layerNum.setParent(this);
	layerNum.show();
	layerNum.setText(QString::number(_layerNum));
	layerNum.setFont(font);
	layerNum.setPalette(pt);
	totalLayerNum.setGeometry(556, 97, 64, 32);
	totalLayerNum.setParent(this);
	totalLayerNum.show();
	totalLayerNum.setText(QString::number(_totalLayerNum));
	totalLayerNum.setFont(font);
	totalLayerNum.setPalette(pt);
}

void GameWindow::updateData()
{
	setData();
	for (int i = 0; i < 9; i++)
	{
		model[i].setText(QString::number(data[i]));
	}
}

void GameWindow::initGame()
{
	initGameWindow.setModal(true);
	initGameWindow.show();
}

void GameWindow::loadGameFile(QString foldername)
{
	if (iSetGame) iSetGame->onHandleFile(foldername.toLocal8Bit().toStdString());
	std::cout << "读取！" << foldername.toLocal8Bit().toStdString() <<"\n";
}

std::shared_ptr<IGetSpeInt> GameWindow::getIntPtr()
{
	return iGetSpecialInt;
}

void GameWindow::keyPressEvent(QKeyEvent* eve)
{
	int x, y;
	if (iGetSpecialInt)
	{
		x = iGetSpecialInt->onGetSpeInt(3);
		y = iGetSpecialInt->onGetSpeInt(4);
	}
	switch (eve->key()) {
	case Qt::Key_Left: if (iMove && iMove->onMove(2)); updateSquare(x, y, x - 1, y); break;
	case Qt::Key_Right: if (iMove && iMove->onMove(3)); updateSquare(x, y, x + 1, y); break;
	case Qt::Key_Up: if (iMove && iMove->onMove(0)); updateSquare(x, y, x, y - 1); break;
	case Qt::Key_Down: if (iMove && iMove->onMove(1)); updateSquare(x, y, x, y + 1); break;
	}
	updateData();

}

void GameWindow::setData()
{
	if (hero)
	{
		data[0] = hero->getHp();
		data[1] = hero->getAtk();
		data[2] = hero->getDef();
		data[3] = hero->getExp();
		//data[4] = hero->getLevel();
		data[5] = hero->getCoins();
		data[6] = hero->getKey(0);
		data[7] = hero->getKey(1);
		data[8] = hero->getKey(2);
	}
	if (iGetSpecialInt)
	{
		_layerNum = iGetSpecialInt->onGetSpeInt(0);
		_totalLayerNum = iGetSpecialInt->onGetSpeInt(1);
	}
}

void GameWindow::setHeroName(QString name)
{
	_heroName = name;
	heroName.setText(_heroName);
}

QString GameWindow::getImgName(int type, int index)
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


void GameWindow::clickSave()
{

}
void GameWindow::clickLoad()
{

}
void GameWindow::clickInitGame()
{
	initGameWindow.setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	initGame();
}