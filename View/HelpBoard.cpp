#include "HelpBoard.h"

HelpBoard::HelpBoard()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	setWindowTitle(codec->toUnicode("ħ���ؿ����˵����"));
	setWindowIcon(QIcon(QPixmap("img/item/item0.png")));
	setFixedSize(800, 600);
	setPixmap(QPixmap("img/system/helpboard.png"));
	show();
}