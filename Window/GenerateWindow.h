#pragma once
#include "qmainwindow.h"
#include "qdialog.h"
#include "qpushbutton.h"
#include "qlistwidget.h"
#include "iostream"
#include "qtextcodec.h"

class EditWindow;

using std::vector;
using std::string;

class GenerateWindow : public QDialog {
	Q_OBJECT
public:
	GenerateWindow();
	vector<string> getList();
	void initialize(EditWindow *ptr);
	void initBtn(QPushButton *btn, int x, int y, int width, int height, string text);
	void initList();
	void updateList();
private:
	vector<string> originList;
	vector<string> selectedList;
	int leftIndex = -1;
	int rightIndex = -1;
	QPushButton add;
	QPushButton del;
	QPushButton up;
	QPushButton down;
	QPushButton generate;
	QListWidget leftList;
	QListWidget rightList;
	EditWindow *ptrParent;
	QTextCodec *cdc = QTextCodec::codecForName("GBK");
public slots:
	void clickAdd();
	void clickDel();
	void clickUp();
	void clickDown();
	void clickGenerate();
	void changeLeft(int id);
	void changeRight(int id);
};