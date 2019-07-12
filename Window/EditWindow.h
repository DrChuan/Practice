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
#include "GenerateWindow.h"

// 左边三个框之间的距离
#define DIS_IT_TO_ENM 237
#define DIS_IT_TO_GM  525

class EditWindow : public QMainWindow {
	Q_OBJECT
public:
	// 构造函数原型
	EditWindow(QWidget *parent = Q_NULLPTR);
	// 命令绑定指针
	std::shared_ptr<ISquareSet>  iss;
	std::shared_ptr<ISquareGet>  isgt;
	std::shared_ptr<ISquareGet>  isgi;
	std::shared_ptr<IGetInt>     iGetUntitledFloorNum;
	std::shared_ptr<IHandleFile> iSaveFile;
	std::shared_ptr<IHandleFile> iLoadFile;
	std::shared_ptr<IHandleFile> iDeleteFile;
	// Common对象数据绑定指针
	std::shared_ptr<FloorFileSet> pFloorFileSet;
	// 层文件选择控件
	FloorChoose  floorChoose;
	// 公共函数接口
	int     getIndex();
	int     getMap();
	int     getType();
	int     getId();
	QString getImgName(int type, int index);
	void    setFramePos();
	void    update();
	void    saveFile();
private:
	// 初始化函数
	void        initWindow();
	void        initButton(QPushButton & btn, int x, int y, int width, int height, std::string text);
	void        initRightButton();
	void		initBackSetBtn();
	void        initItemBtn();
	void        initEnemyBtn();
	void        initGameBtn();
	void        initSelectFrame();
	void        initDrawPlace();
	void        initDrawObj();
	void        initFloorChooseList();
	void        initSquarePic();
	// 鼠标事件函数
	void        mouseMoveEvent(QMouseEvent *e);
	// 属性
	int          index = 0;
	int          map = 0;
	int          fileId = -1;
	QString      currentFilename = "New Floor";
	// 窗口组件
	QPushButton  btIce;
	QPushButton  btFire;
	QPushButton  btLeaf;
	QLabel       currentFilenameLabel;
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
	QPushButton  generateBtn;
	QPushButton  deleteBtn;
	QPushButton  setModelBtn;
	QLabel       squaresPic[11][11];
	QTextCodec  *codec = QTextCodec::codecForName("GBK");
	GenerateWindow generateWindow;
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
	void clickDeleteBtn();
	void clickSetModelBtn();
	void putSquare();
	void changeFileId(int num);
	void generate();
};
