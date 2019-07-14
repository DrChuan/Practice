#include "GameWindow.h"

GameWindow::GameWindow(QWidget* parent) : QMainWindow(parent), initGameWindow(this), loadWindow(this)
{
	// ���ô��ڱ��⼰��С
	setFixedSize(1024, 768);
	setWindowTitle(codec->toUnicode("ħ��"));
	// ���ô��ڱ���
	QPalette p = palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/gamebackice.png")));
	setPalette(p);
	// ��ʼ����ť������
	initButton();
	initSquare();
	// ��ʼ�������ֲ�
	initEnemyBook();
	// ��ʼ��������ʾ
	initData();
}


void GameWindow::initEnemyBook()
{
	enemyBook.setParent(this);
	enemyBook.show();
	enemyBook.setIconSize(QSize(48, 48));
	enemyBook.setGeometry(800, 192, 200, 540);
	enemyBook.setFocusPolicy(Qt::NoFocus);
	enemyBook.setStyleSheet("background-color:transparent; border:none");
	enemyList.resize(25);
	updateEnemyBook();
}

void GameWindow::initButton()
{
	saveBtn.setParent(this);
	saveBtn.setText(codec->toUnicode("����\n����"));
	saveBtn.setGeometry(820, 55, 68, 68);
	saveBtn.show();
	saveBtn.setFocusPolicy(Qt::NoFocus);
	loadBtn.setParent(this);
	loadBtn.setText(codec->toUnicode("��ȡ\n����"));
	loadBtn.setGeometry(905, 55, 68, 68);
	loadBtn.show();
	loadBtn.setFocusPolicy(Qt::NoFocus);
	initGameBtn.setParent(this);
	initGameBtn.setText(codec->toUnicode("��ȡ������Ϸ"));
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
	heroPic.setParent(this);
	heroPic.setPixmap(QPixmap("img/system/herodown.png"));
	heroPic.show();
	heroPic.raise();
	setXY();
	heroPic.setGeometry(241 + 48 * _x, 146 + 48 * _y, 48, 48);
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

void GameWindow::initGame()
{
	initGameWindow.setModal(true);
	initGameWindow.show();
}


void GameWindow::updateSquare(int ox, int oy, int nx, int ny)
{
	if (isgt && isgi)
	{
		squares[ox][oy].setPixmap(QPixmap(getImgName(isgt->onUpdate(ox, oy), isgi->onUpdate(ox, oy))));
		squares[nx][ny].setPixmap(QPixmap(getImgName(isgt->onUpdate(nx, ny), isgi->onUpdate(nx, ny))));
	}
}

void GameWindow::update()
{
	setXY();
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			if (isgt && isgi) squares[i][j].setPixmap(QPixmap(getImgName(isgt->onUpdate(i, j), isgi->onUpdate(i, j))));
	heroPic.move(241 + _x * 48, 146 + _y * 48);
	updateEnemyBook();
}

void GameWindow::updateEnemyBook()
{
	enemyList.clear();
	enemyBook.clear();
	if (!hero || !hero->getEnemyBook())
	{
		enemyBook.addItem(codec->toUnicode("��δ���������ֲᣡ"));
		return;
	}
	std::vector<int> list;
	int n;
	if (iGetIntList) list = iGetIntList->onGetIntList();
	n = list.size();
	QListWidgetItem temp;
	temp.setSizeHint(QSize(130, 150));
	QString info;
	for (int i = 0; i < n; i++)
	{
		int t = list[i];
		Obj tObj = iGetObj->onGetObj(1, t);
		if (iGetObj)
		{
			info += name[t];
			info += "\n";
			info += codec->toUnicode("����:") + QString::number(tObj.getHp()) + "\n";
			info += codec->toUnicode("����:") + QString::number(tObj.getAtk()) + "\n";
			info += codec->toUnicode("����:") + QString::number(tObj.getDef()) + "\n";
			info += codec->toUnicode("��þ���:") + QString::number(tObj.getExp()) + "\n";
			info += codec->toUnicode("��ý��:") + QString::number(tObj.getCoins()) + "\n";
			if (hero->getHurt(tObj) == -1)
				info += codec->toUnicode("�޷�������");
			else
				info += codec->toUnicode("��ʧ����:") + QString::number(hero->getHurt(tObj));
		}
		temp.setText(info);
		temp.setIcon(QIcon(QPixmap("img/enemy/enemy" + QString::number(t))));
		enemyList.push_back(temp);
		info = "";
		enemyBook.addItem(&(enemyList[i]));
	}
}

void GameWindow::updateData()
{
	setData();
	for (int i = 0; i < 9; i++)
	{
		model[i].setText(QString::number(data[i]));
	}
	layerNum.setText(QString::number(_layerNum));
}


void GameWindow::setXY()
{
	if (iGetSpecialInt)
	{
		_x = iGetSpecialInt->onGetSpeInt(3);
		_y = iGetSpecialInt->onGetSpeInt(4);
	}
}

void GameWindow::setData()
{
	if (hero)
	{
		data[0] = hero->getHp();
		data[1] = hero->getAtk();
		data[2] = hero->getDef();
		data[3] = hero->getExp();
		data[4] = hero->getLevel();
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


void GameWindow::keyPressEvent(QKeyEvent* eve)
{
	int k;
	setXY();
	if (iMove)
		switch (eve->key()) {
		case Qt::Key_Left:
			k = iMove->onMove(2);
			heroPic.setPixmap(QPixmap("img/system/heroleft"));
			if ((k & 0x0f) == 1)  heroPic.move(241 + (_x - 1) * 48, 146 + _y * 48), updateSquare(_x, _y, _x - 1, _y);
			if (k & 0x10) updateEnemyBook();
			break;
		case Qt::Key_Right:
			k = iMove->onMove(3);
			heroPic.setPixmap(QPixmap("img/system/heroright"));
			if ((k & 0x0f) == 1)  heroPic.move(241 + (_x + 1) * 48, 146 + _y * 48), updateSquare(_x, _y, _x + 1, _y);
			if (k & 0x10) updateEnemyBook();
			break;
		case Qt::Key_Up:
			k = iMove->onMove(0);
			heroPic.setPixmap(QPixmap("img/system/heroup"));
			if ((k & 0x0f) == 1)  heroPic.move(241 + _x * 48, 146 + (_y - 1) * 48), updateSquare(_x, _y, _x, _y - 1);
			if (k & 0x10) updateEnemyBook();
			break;
		case Qt::Key_Down:
			k = iMove->onMove(1);
			heroPic.setPixmap(QPixmap("img/system/herodown"));
			if ((k & 0x0f) == 1)  heroPic.move(241 + _x * 48, 146 + (_y + 1) * 48), updateSquare(_x, _y, _x, _y + 1);
			if (k & 0x10) updateEnemyBook();
			break;
		}
	if ((k & 0x0f) == 2) {
		update();
	}
	updateData();
}

void GameWindow::loadGameFile(QString foldername)
{
	if (iSetGame) iSetGame->onHandleFile(foldername.toLocal8Bit().toStdString());
	std::cout << "��ȡ��" << foldername.toLocal8Bit().toStdString() << "\n";
}

void GameWindow::load(QString foldername)
{
	if (iLoadGame) iLoadGame->onHandleFile(foldername.toLocal8Bit().toStdString());
}

std::shared_ptr<IGetSpeInt> GameWindow::getIntPtr()
{
	return iGetSpecialInt;
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
	QString str = "";
	while ((str = QInputDialog::getText(this, codec->toUnicode("ħ��"), codec->toUnicode("������浵�ļ�����"))) == "");
	if (iSave) iSave->onHandleFile(str.toLocal8Bit().toStdString());
}

void GameWindow::clickLoad()
{
	loadWindow.setModal(true);
	loadWindow.initList();
	loadWindow.show();
}

void GameWindow::clickInitGame()
{
	initGameWindow.setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
	initGame();
}