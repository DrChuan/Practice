#pragma once
#include <QtWidgets/QMainWindow>
#include "qpushbutton.h"
#include "qlabel.h"
#include "qicon.h"
#include "qsignalmapper.h"
#include "qevent.h"
#include "qtextcodec.h"
#include "qgraphicseffect.h"
#include "DrawPlace.h"
#include "HelpBoard.h"
#include "ISquareSet.h"
#include "ISquareGet.h"

// 左边三个框之间的距离
#define DIS_IT_TO_ENM 237
#define DIS_IT_TO_GM  525

class EditWindow : public QMainWindow {
	Q_OBJECT
public:
	// 构造函数原型
	EditWindow(QWidget *parent = Q_NULLPTR);

	std::shared_ptr<ISquareSet> iss;
	std::shared_ptr<ISquareGet> isgt;
	std::shared_ptr<ISquareGet> isgi;
	// 公共函数接口
	int     getIndex();
	int     getMap();  
	int     getType();              
	int     getId();
	void    setFramePos();
	void    update();
	QString getImgName(int type, int index);
private:
	// 初始化函数及鼠标事件函数
	void        initWindow();
	void		    initBackSetBtn();
	void        initItemBtn();
	void        initEnemyBtn();
	void        initGameBtn();
	void        initSelectFrame();
	void        initDrawPlace();
	void        mouseMoveEvent(QMouseEvent *e);
	void        initDrawObj();
	void        initHelpBoardBtn();
	void        initSquarePic();
	// 属性
	int         index = 0;
	int         map = 0;
	// 窗口组件
	QPushButton btIce;
	QPushButton btFire;
	QPushButton btLeaf;
	QLabel      selectFrame;
	QPushButton items[20];
	QPushButton enemies[25];
	QPushButton games[15];
	DrawPlace   drawPlace;
	QPushButton drawObj;
	HelpBoard  *helpBoard;
	QPushButton helpBoardBtn;
	QLabel      squaresPic[11][11];
	// 槽函数
public slots:
	void setIce();
	void setFire();
	void setLeaf();
	void clickItem(int id);
	void clickEnemy(int id);
	void clickGame(int id);
	void updateDrawObj(int x, int y);
	void clickHelpBoardBtn();
	void putSquare();
};
