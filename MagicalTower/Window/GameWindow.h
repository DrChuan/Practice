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
#include "qevent.h"

class GameWindow : public QMainWindow
{
	Q_OBJECT
public:
	GameWindow(QWidget *parent = Q_NULLPTR);
	void initButton();
	void initSquare();
	void updateSquare(int ox, int oy, int nx, int ny);
	void initData();
	void updateData();

	void initGame();
	void setData();
	void setHeroName(QString name);

	QString getImgName(int type, int index);
	void loadGameFile(QString foldername);

	void keyPressEvent(QKeyEvent*);
	std::shared_ptr<IGetSpeInt> getIntPtr();

private:
	// ��ɫ����
	std::shared_ptr<Hero> hero;
	// �����
	std::shared_ptr<ISquareGet>  isgt;
	std::shared_ptr<ISquareGet>  isgi;
	std::shared_ptr<IGetSpeInt> iGetSpecialInt;
	std::shared_ptr<IHandleFile> iSetGame;
	std::shared_ptr<IMove> iMove;
	// ���ڿؼ�
	QTextCodec  *codec = QTextCodec::codecForName("GBK");
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
		// ���ﻹȱһ����ʾ�����ֲ�Ŀؼ�
	InitGameWindow initGameWindow;
	int data[9] = { 0 };
	int _layerNum = 0;
	int _totalLayerNum = 0;
	QString _heroName = "";

public slots:
	void clickSave();
	void clickLoad();
	void clickInitGame();
};