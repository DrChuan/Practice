#include "SelectWindow.h"

// 从QMainWindow类创建了SelectWindow类，作为程序的入口，要求用户选择编辑或游戏
SelectWindow::SelectWindow(QWidget *parent) : QMainWindow(parent)
{
	initWindow();
	initBrowser();
	initbutton();
}

void SelectWindow::clickCreator()
{
	//editWindow = new EditWindow(editorViewModel);
	//editWindow->iss = editorViewModel->m_sssink;
	editWindow->show();
	editWindow->pFloorFileSet->filenameSetInit();
	editWindow->floorChoose.setFileList();

	this->hide();
}

void SelectWindow::initWindow()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	// 初始化窗口标题及大小
	setWindowTitle(codec->toUnicode("魔塔"));
	setFixedSize(800, 600);
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/back.png")));
	this->setPalette(p);
}
void SelectWindow::initBrowser()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	// 创建、显示文本框
	browser = new QTextBrowser(this);
	browser->show();
	// 设置文本框位置及大小
	browser->resize(600, 320);
	browser->move(100, 100);
	// 设置文本框字体及内容
	QFont font;
	font.setFamily("SimHei");   // 黑体
	font.setPointSize(12);      // 12号字
	browser->setFont(font);
	browser->append(codec->toUnicode("你好，旅行者！欢迎来到魔塔的世界。\n\n每一位来到这里的旅行者，都有两条截然不同的道路可以选择。\n\n一者，乃缔造者。\n掌握魔塔世界运行之道。\n道生一，一生二，二生三，三生万物。\n\n二者，乃求索者。\n欲少留此灵琐，日忽忽其将暮。\n路漫漫其修远，将上下而求索。\n\n旅行者，接下来，是你做选择的时候了。"));
	// 设置文本框半透明背景
	QPalette pl = browser->palette();
	pl.setBrush(QPalette::Base, QBrush(QColor(255, 255, 255, 80)));
	browser->setPalette(pl);
	// 消除文本框边界
	browser->setStyleSheet("border:none");
}

void SelectWindow::initbutton()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	// 设置缔造者按钮文字、大小、位置
	creatorBtn = new QToolButton(this);
	creatorBtn->setText(codec->toUnicode("我要做缔造者"));
	creatorBtn->move(BTN_X, BTN_Y);
	creatorBtn->setFixedSize(150, 60);
	creatorBtn->show();
	// 设置求索者按钮文字、大小、位置
	explorerBtn = new QToolButton(this);
	explorerBtn->setText(codec->toUnicode("我要做求索者"));
	explorerBtn->move(650 - BTN_X, BTN_Y);
	explorerBtn->setFixedSize(150, 60);
	explorerBtn->show();
	// 设置按钮信号槽
	connect(&(*creatorBtn), SIGNAL(clicked()), this, SLOT(clickCreator()));
}