#pragma once
#include <QtWidgets/QMainWindow>
#include "qpushbutton.h"
#include "qlabel.h"
#include "qicon.h"
#include "qsignalmapper.h"
#include "qevent.h"
#include "qtextcodec.h"
#include "qgraphicseffect.h"
#include "qmessagebox.h"
#include "DrawPlace.h"
#include "HelpBoard.h"
#include "qinputdialog.h"
#include "qfiledialog.h"
#include "ICommand.h"
#include "FloorChoose.h"
#include "FloorFileSet.h"


// 左边三个框之间的距离
#define DIS_IT_TO_ENM 237
#define DIS_IT_TO_GM  525

class EditWindow : public QMainWindow {
	Q_OBJECT
public:
	// 构造函数原型
	EditWindow(QWidget *parent = Q_NULLPTR);

	std::shared_ptr<ISquareSet>  iss;
	std::shared_ptr<ISquareGet>  isgt;
	std::shared_ptr<ISquareGet>  isgi;
	std::shared_ptr<IGetInt>     iGetUntitledFloorNum;
	std::shared_ptr<IHandleFile> iSaveFile;
	std::shared_ptr<IHandleFile> iLoadFile;

	std::shared_ptr<FloorFileSet> pFloorFileSet;
	FloorChoose  floorChoose;
	// 公共函数接口
	int     getIndex();
	int     getMap();
	int     getType();
	int     getId();
	void    setFramePos();
	void    update();
	void    saveFile();
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
	void        initSaveComponent();
	void        initChangeFloorBtn();
	void        initSquarePic();
	// 属性
	int          index = 0;
	int          map = 0;
	int          fileId = 0;
	// 窗口组件
	QPushButton  btIce;
	QPushButton  btFire;
	QPushButton  btLeaf;
	QLabel       selectFrame;
	QPushButton  items[20];
	QPushButton  enemies[25];
	QPushButton  games[15];
	DrawPlace    drawPlace;
	QPushButton  drawObj;
	HelpBoard   *helpBoard;
	QPushButton  helpBoardBtn;
	QPushButton  saveBtn;
	QPushButton  newFloorBtn;
	QPushButton  openFloorBtn;

	QLabel       squaresPic[11][11];

	QTextCodec *codec = QTextCodec::codecForName("GBK");
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
	void clickSaveBtn();
	void clickNewBtn();
	void clickOpenBtn();
	void putSquare();
	void changeFileId(int num);
};
