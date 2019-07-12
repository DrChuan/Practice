#pragma once

#include "qdialog.h"
#include "qspinbox.h"
#include "qtextcodec.h"
#include "qlabel.h"
#include "qpushbutton.h"

class GenerateWindow;

class SetInitModelWindow : public QDialog {
	Q_OBJECT
public:
	QSpinBox gold;
	QSpinBox hp;
	QSpinBox atk;
	QSpinBox def;
	QSpinBox yelloKey;
	QSpinBox blueKey;
	QSpinBox redKey;
	void initialize(GenerateWindow *parent);
	void initBox(QSpinBox & box, int min, int max, int init, int x, int y);
private:
	GenerateWindow *ptr;
	QLabel   label[7];
	QPushButton ok;
	QPushButton reset;
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	const QString labelName[7] = { codec->toUnicode("初始金钱"), codec->toUnicode("初始生命"), codec->toUnicode("初始攻击"), 
		codec->toUnicode("初始防御"), codec->toUnicode("初始黄钥匙"), codec->toUnicode("初始蓝钥匙"), codec->toUnicode("初始红钥匙") };

};