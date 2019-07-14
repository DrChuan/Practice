#pragma once

#include <QtWidgets/QMainWindow>
#include "qtextcodec.h" 
#include "qpalette.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qfiledialog.h"
#include "ListMember.h"
#include "qinputdialog.h"
#include "ICommand.h"
#include <iostream>
#include "qcoreapplication.h"
#include "InitGameWindow.h"
#include "LoadWindow.h"
#include "qevent.h"

class GameWindow : public QMainWindow
{
	Q_OBJECT
public:
	GameWindow(QWidget* parent = Q_NULLPTR);
	void initButton();
	void initSquare();
	void initData();
	void initEnemyBook();
	void initGame();

	void updateSquare(int ox, int oy, int nx, int ny);
	void updateData();
	void updateEnemyBook();
	void update();

	void setData();
	void setXY();
	void setHeroName(QString name);

	void keyPressEvent(QKeyEvent*);

	QString getImgName(int type, int index);
	void loadGameFile(QString foldername);
	void load(QString foldername);
	std::shared_ptr<IGetSpeInt> getIntPtr();
	// 角色数据
	std::shared_ptr<Hero> hero;
	// 命令绑定
	std::shared_ptr<ISquareGet>  isgt;
	std::shared_ptr<ISquareGet>  isgi;
	std::shared_ptr<IGetSpeInt> iGetSpecialInt;
	std::shared_ptr<IHandleFile> iSetGame;
	std::shared_ptr<IMove> iMove;
	std::shared_ptr<IGetObj> iGetObj;
	std::shared_ptr<IGetIntList> iGetIntList;
	std::shared_ptr<IHandleFile> iSave;
	std::shared_ptr<IHandleFile> iLoadGame;
private:
	// 窗口控件
	QTextCodec* codec = QTextCodec::codecForName("GBK");
	QLabel heroPic;
	QLabel squares[11][11];
	QPushButton saveBtn;
	QPushButton loadBtn;
	QPushButton initGameBtn;
	QLabel model[9];
	QLabel heroName;
	QLabel gameName;
	QLabel layerNum;
	QLabel totalLayerNum;
	QLabel weapon[6];
	QLabel equip[6];
	QListWidget enemyBook;
	std::vector<QListWidgetItem> enemyList;
	InitGameWindow initGameWindow;
	LoadWindow loadWindow;
	int data[9] = { 0 };
	int _layerNum = 0;
	int _totalLayerNum = 0;
	QString _heroName = "";
	int _x;
	int _y;
	const QString name[25] = { 
		codec->toUnicode("绿色史莱姆"),codec->toUnicode("红色史莱姆"), codec->toUnicode("小蝙蝠")   , codec->toUnicode("初级法师") ,
		codec->toUnicode("骷髅人")   ,codec->toUnicode("骷髅士兵")  , codec->toUnicode("初级卫兵") , codec->toUnicode("骷髅队长") , 
		codec->toUnicode("大蝙蝠")   ,codec->toUnicode("高级法师")  , codec->toUnicode("兽人武士") , codec->toUnicode("大乌贼")   , 
		codec->toUnicode("大法师")   ,codec->toUnicode("战士")     , codec->toUnicode("幽灵")     , codec->toUnicode("中级卫兵") , 
		codec->toUnicode("双手剑士") ,codec->toUnicode("魔龙")     , codec->toUnicode("骑士")     , codec->toUnicode("骑士队长") , 
		codec->toUnicode("初级巫师") ,codec->toUnicode("高级巫师")  , codec->toUnicode("史莱姆王") , codec->toUnicode("高级卫兵") , 
		codec->toUnicode("红史莱姆") };
public slots:
	void clickSave();
	void clickLoad();
	void clickInitGame();
};