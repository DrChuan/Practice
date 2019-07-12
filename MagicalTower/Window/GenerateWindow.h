#pragma once
#include "qmainwindow.h"
#include "qdialog.h"
#include "qpushbutton.h"
#include "qlistwidget.h"
#include "iostream"
#include "qtextcodec.h"
#include "SetInitModelWindow.h"

class EditWindow;

using std::vector;
using std::string;

class GenerateWindow : public QDialog {
	Q_OBJECT
public:
	GenerateWindow(EditWindow *ptr);
	vector<string> getList();
	void initialize();
	void initBtn(QPushButton *btn, int x, int y, int width, int height, string text);
	void initList();
	void updateList();
	void setInitialModel(int gold, int hp, int atk, int def, int ykey, int bkey, int rkey);
	vector<int> getInitialModel();
private:
	vector<int>    initModel = {0, 0, 1000, 10, 5, 1, 1, 1};
	vector<string> originList;
	vector<string> selectedList;
	int leftIndex = -1;
	int rightIndex = -1;
	QPushButton add;
	QPushButton del;
	QPushButton up;
	QPushButton down;
	QPushButton generate;
	QPushButton setInitModel;
	QListWidget leftList;
	QListWidget rightList;
	EditWindow *ptrParent;
	SetInitModelWindow setInitModelWindow;
	QTextCodec *cdc = QTextCodec::codecForName("GBK");
public slots:
	void clickAdd();
	void clickDel();
	void clickUp();
	void clickDown();
	void clickSetInitModel();
	void changeLeft(int id);
	void changeRight(int id);
	void setModelOk();
	void setModelReset();
};