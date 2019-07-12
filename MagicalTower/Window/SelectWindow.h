#pragma once

#include <QtWidgets/QMainWindow>
//#include "ui_MagicalTower.h"
#include "qtextbrowser.h"
#include "qtextcodec.h" 
#include "qtoolbutton.h"
#include "qpalette.h"
#include "EditWindow.h"


// ��ťλ��
#define BTN_X 200
#define BTN_Y 470

class SelectWindow : public QMainWindow
{
	Q_OBJECT
public:
	// ���캯��
	SelectWindow(QWidget* parent = Q_NULLPTR);

	// �༭������
	EditWindow* editWindow;
public slots:
	// ��ť�ۺ���
	void clickCreator();
	//void clickExplorer();
private:
	// �������
	QTextBrowser* browser;
	QToolButton* creatorBtn;
	QToolButton* explorerBtn;
	// ��ʼ������
	void initWindow();
	void initBrowser();
	void initbutton();
};
