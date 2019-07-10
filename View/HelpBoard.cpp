#include "HelpBoard.h"

HelpBoard::HelpBoard()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	setWindowTitle(codec->toUnicode("魔塔关卡设计说明书"));
	setWindowIcon(QIcon(QPixmap("img/item/item0.png")));
	setFixedSize(800, 600);
	setPixmap(QPixmap("img/system/helpboard.png"));
	show();
}