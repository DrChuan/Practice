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


// ���������֮��ľ���
#define DIS_IT_TO_ENM 237
#define DIS_IT_TO_GM  525

class EditWindow : public QMainWindow {
	Q_OBJECT
public:
	// ���캯��ԭ��
	EditWindow(EditorViewModel *evm, QWidget *parent = Q_NULLPTR);
	// ���������ӿ�
	int getIndex();
	int getMap();  // mapָ������������ѡ��
	int getType();
	int getId();
	void setFramePos();
	void update();
	QString getImgName(int type, int index);
private:
	EditorViewModel *editorViewModel;
	Floor           *floor;
	// ��ʼ������������¼�����
	void        initWindow();
	void		    initBackSetBtn();
	void        initItemBtn();
	void        initEnemyBtn();
	void        initGameBtn();
	void        initSelectFrame();
	void        initDrawPlace();
	void        mouseMoveEvent(QMouseEvent *e);
	void        initDrawObj();
	void        initSquarePic();
	// ����
	int         index = 0;
	int         map = 0;
	int         cursorOX = 0;
	int         cursorOY = 0;
	// �������
	QPushButton btIce;
	QPushButton btFire;
	QPushButton btLeaf;
	QLabel      selectFrame;
	QPushButton items[20];
	QPushButton enemies[25];
	QPushButton games[15];
	DrawPlace   drawPlace;
	QPushButton drawObj;
	QLabel      squaresPic[11][11];
	// �ۺ���
public slots:
	void setIce();
	void setFire();
	void setLeaf();
	void clickItem(int id);
	void clickEnemy(int id);
	void clickGame(int id);
	void updateDrawObj(int x, int y);
	void putSquare();
};
