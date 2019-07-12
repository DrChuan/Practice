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
	const QString labelName[7] = { codec->toUnicode("��ʼ��Ǯ"), codec->toUnicode("��ʼ����"), codec->toUnicode("��ʼ����"), 
		codec->toUnicode("��ʼ����"), codec->toUnicode("��ʼ��Կ��"), codec->toUnicode("��ʼ��Կ��"), codec->toUnicode("��ʼ��Կ��") };

};