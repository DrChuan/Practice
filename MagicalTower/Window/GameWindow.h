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
	// ��ɫ����
	std::shared_ptr<Hero> hero;
	// �����
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
	// ���ڿؼ�
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
		codec->toUnicode("��ɫʷ��ķ"),codec->toUnicode("��ɫʷ��ķ"), codec->toUnicode("С����")   , codec->toUnicode("������ʦ") ,
		codec->toUnicode("������")   ,codec->toUnicode("����ʿ��")  , codec->toUnicode("��������") , codec->toUnicode("���öӳ�") , 
		codec->toUnicode("������")   ,codec->toUnicode("�߼���ʦ")  , codec->toUnicode("������ʿ") , codec->toUnicode("������")   , 
		codec->toUnicode("��ʦ")   ,codec->toUnicode("սʿ")     , codec->toUnicode("����")     , codec->toUnicode("�м�����") , 
		codec->toUnicode("˫�ֽ�ʿ") ,codec->toUnicode("ħ��")     , codec->toUnicode("��ʿ")     , codec->toUnicode("��ʿ�ӳ�") , 
		codec->toUnicode("������ʦ") ,codec->toUnicode("�߼���ʦ")  , codec->toUnicode("ʷ��ķ��") , codec->toUnicode("�߼�����") , 
		codec->toUnicode("��ʷ��ķ") };
public slots:
	void clickSave();
	void clickLoad();
	void clickInitGame();
};