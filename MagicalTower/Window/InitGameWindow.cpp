#include "InitGameWindow.h"
#include "GameWindow.h"

InitGameWindow::InitGameWindow(GameWindow* ptr) : ptrParent(ptr)
{
	setWindowTitle(codec->toUnicode("加载游戏关卡"));
	setFixedSize(400, 400);
	openBtn.setParent(this);
	openBtn.setGeometry(150, 355, 100, 32);
	openBtn.setText(codec->toUnicode("打开"));
	openBtn.show();
	connect(&openBtn, SIGNAL(clicked()), this, SLOT(open()));
	setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint);
	initList();
}

void InitGameWindow::initList()
{
	int len;
	getAllFileFolder(".\\game", gameNameList);
	std::string s = QCoreApplication::applicationDirPath().toStdString();
	len = QCoreApplication::applicationDirPath().toStdString().size();
	for (int i = 0; i < gameNameList.size(); i++)
	{
		std::string str = gameNameList[i].toStdString();
		int len = str.size() - 1;
		while (len && str[len--] != '/');
		gameNameList[i] = QString::fromStdString(gameNameList[i].toStdString().erase(0, len + 2));
		gameList.addItem(gameNameList[i]);
		//std::cout << gameNameList[i].toLocal8Bit().toStdString();
	}
	gameList.setParent(this);
	gameList.show();
	gameList.setGeometry(40, 40, 320, 300);
}

void InitGameWindow::getAllFileFolder(QString dirPath, std::vector<QString>& folder)
{
	QDir dir(dirPath);
	dir.setFilter(QDir::Dirs);
	foreach(QFileInfo fullDir, dir.entryInfoList())
	{
		if (fullDir.fileName() == "." || fullDir.fileName() == "..") continue;
		folder.push_back(fullDir.absoluteFilePath());
		this->getAllFileFolder(fullDir.absoluteFilePath(), folder);
	}
}

void InitGameWindow::open()
{
	int style;
	QString str = "";
	while ((str = QInputDialog::getText(this, codec->toUnicode("魔塔"), codec->toUnicode("旅行者，该怎么称呼您？"))) == "");
	ptrParent->setHeroName(str);
	int in = gameList.currentRow();
	ptrParent->loadGameFile(gameNameList[in]);
	ptrParent->initData();
	ptrParent->initSquare();
	if (ptrParent->getIntPtr())
		style = ptrParent->getIntPtr()->onGetSpeInt(2);
	QPalette p = palette();
	switch (style) {
	case 0: p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/gamebackice.png"))); break;
	case 1: p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/gamebackfire.png"))); break;
	case 2: p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/gamebackleaf.png"))); break;
	}
	ptrParent->setPalette(p);
	close();
}