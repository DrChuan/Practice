#pragma once

#include "qdialog.h"
#include "qspinbox.h"
#include "qtextcodec.h"
#include "qlabel.h"
#include "qpushbutton.h"

class EditWindow;

class SetEnemyWindow : public QDialog {
	Q_OBJECT
public:
	void initialize(EditWindow *ptr, int _type, int _id);
	void initSignalSlot();
	int  getData(int id);
private:
	int			 type;
	int			 id;
	int          data[5];
	QWidget     *ptrParent;
	QTextCodec  *codec = QTextCodec::codecForName("GBK");
	QPushButton  ok;
	QPushButton  cancel;
	QSpinBox     dataBox[5];
	QLabel       dataLabel[5];
public slots:
}; 
