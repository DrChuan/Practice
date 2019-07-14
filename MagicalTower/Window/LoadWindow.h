#pragma once

#include "qdialog.h"
#include "qpushbutton.h"
#include "qlistwidget.h"
#include "qdir.h"
#include "qcoreapplication.h"
#include <iostream>
#include "qtextcodec.h"

class GameWindow;

class LoadWindow : public QDialog {
	Q_OBJECT
public:
	LoadWindow(GameWindow *ptr);
	void initList();
	void getAllFileFolder(QString dirPath, std::vector<QString> &folder);
private:
	GameWindow *ptrParent;
	QPushButton openBtn;
	QListWidget gameList;
	std::vector<QString> gameNameList;
	QTextCodec  *codec = QTextCodec::codecForName("GBK");
public slots:
	void open();
};