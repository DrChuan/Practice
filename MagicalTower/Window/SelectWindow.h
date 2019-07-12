#pragma once

#include <QtWidgets/QMainWindow>
//#include "ui_MagicalTower.h"
#include "qtextbrowser.h"
#include "qtextcodec.h" 
#include "qtoolbutton.h"
#include "qpalette.h"
#include "EditWindow.h"


// 按钮位置
#define BTN_X 200
#define BTN_Y 470

class SelectWindow : public QMainWindow
{
	Q_OBJECT
public:
	// 构造函数
	SelectWindow(QWidget* parent = Q_NULLPTR);

	// 编辑器窗口
	EditWindow* editWindow;
public slots:
	// 按钮槽函数
	void clickCreator();
	//void clickExplorer();
private:
	// 窗口组件
	QTextBrowser* browser;
	QToolButton* creatorBtn;
	QToolButton* explorerBtn;
	// 初始化函数
	void initWindow();
	void initBrowser();
	void initbutton();
};
