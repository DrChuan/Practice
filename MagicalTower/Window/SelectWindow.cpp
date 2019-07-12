#include "SelectWindow.h"

// ��QMainWindow�ഴ����SelectWindow�࣬��Ϊ�������ڣ�Ҫ���û�ѡ��༭����Ϸ
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
	// ��ʼ�����ڱ��⼰��С
	setWindowTitle(codec->toUnicode("ħ��"));
	setFixedSize(800, 600);
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/back.png")));
	this->setPalette(p);
}
void SelectWindow::initBrowser()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	// ��������ʾ�ı���
	browser = new QTextBrowser(this);
	browser->show();
	// �����ı���λ�ü���С
	browser->resize(600, 320);
	browser->move(100, 100);
	// �����ı������弰����
	QFont font;
	font.setFamily("SimHei");   // ����
	font.setPointSize(12);      // 12����
	browser->setFont(font);
	browser->append(codec->toUnicode("��ã������ߣ���ӭ����ħ�������硣\n\nÿһλ��������������ߣ�����������Ȼ��ͬ�ĵ�·����ѡ��\n\nһ�ߣ��˵����ߡ�\n����ħ����������֮����\n����һ��һ���������������������\n\n���ߣ��������ߡ�\n���������������պ����佫ĺ��\n·��������Զ�������¶�������\n\n�����ߣ���������������ѡ���ʱ���ˡ�"));
	// �����ı����͸������
	QPalette pl = browser->palette();
	pl.setBrush(QPalette::Base, QBrush(QColor(255, 255, 255, 80)));
	browser->setPalette(pl);
	// �����ı���߽�
	browser->setStyleSheet("border:none");
}

void SelectWindow::initbutton()
{
	QTextCodec *codec = QTextCodec::codecForName("GBK");
	// ���õ����߰�ť���֡���С��λ��
	creatorBtn = new QToolButton(this);
	creatorBtn->setText(codec->toUnicode("��Ҫ��������"));
	creatorBtn->move(BTN_X, BTN_Y);
	creatorBtn->setFixedSize(150, 60);
	creatorBtn->show();
	// ���������߰�ť���֡���С��λ��
	explorerBtn = new QToolButton(this);
	explorerBtn->setText(codec->toUnicode("��Ҫ��������"));
	explorerBtn->move(650 - BTN_X, BTN_Y);
	explorerBtn->setFixedSize(150, 60);
	explorerBtn->show();
	// ���ð�ť�źŲ�
	connect(&(*creatorBtn), SIGNAL(clicked()), this, SLOT(clickCreator()));
}