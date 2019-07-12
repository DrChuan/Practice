#include "EditWindow.h"
#include <iostream>

// 构造函数
EditWindow::EditWindow(QWidget *parent) : QMainWindow(parent) , floorChoose(pFloorFileSet)
{
	// 初始化窗口标题，大小，背景
	initWindow();
	// 初始化冰、火、林按钮
	initBackSetBtn();
	// 初始化元件栏按钮
	initItemBtn();
	initEnemyBtn();
	initGameBtn();
	// 初始化选择框属性
	initSelectFrame();
	// 初始化地图编辑区域
	initDrawPlace();
	initDrawObj();
	// 初始化右侧按钮
	initRightButton();
	// 初始化图块显示组件
	initSquarePic();
	// 初始化层选择控件
	initFloorChooseList();
	// 设置鼠标事件响应方式
	setMouseTracking(true);
}

// 普通函数
// -- 控件初始化函数
void EditWindow::initWindow()
{
	setWindowTitle(codec->toUnicode("魔塔关卡设计"));
	setFixedSize(1024, 768);
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/editbackice.jpg")));
	this->setPalette(p);
	QFont font;
	font.setFamily("SimHei");
	font.setPointSize(18);
	currentFilenameLabel.setParent(this);
	currentFilenameLabel.setText(currentFilename.toLocal8Bit());
	currentFilenameLabel.show();
	currentFilenameLabel.setFont(font);
	currentFilenameLabel.setGeometry(340, 40, 200, 48);
}

void EditWindow::initButton(QPushButton & btn, int x, int y, int width, int height, std::string text)
{
	btn.setParent(this);
	btn.setText(codec->toUnicode(text.data()));
	btn.show();
	btn.setGeometry(x, y, width, height);
}

void EditWindow::initRightButton()
{
	initButton(helpBoardBtn, 900, 700, 100, 32, "说明书");
	initButton(saveBtn, 900, 600, 120, 32, "保存当前层");
	initButton(newFloorBtn, 900, 500, 120, 32, "新建空白层");
	initButton(openFloorBtn, 900, 400, 120, 32, "打开选中层");
	initButton(generateBtn, 800, 500, 120, 32, "生成游戏关卡");
	initButton(deleteBtn, 800, 600, 120, 32, "删除选中层");
	initButton(setModelBtn, 800, 400, 120, 32, "修改选中块属性");
	connect(&helpBoardBtn, SIGNAL(clicked()), this, SLOT(clickHelpBoardBtn()));
	connect(&saveBtn, SIGNAL(clicked()), this, SLOT(clickSaveBtn()));
	connect(&newFloorBtn, SIGNAL(clicked()), this, SLOT(clickNewBtn()));
	connect(&openFloorBtn, SIGNAL(clicked()), this, SLOT(clickOpenBtn()));
	connect(&generateBtn, SIGNAL(clicked()), this, SLOT(generate()));
	connect(&deleteBtn, SIGNAL(clicked()), this, SLOT(clickDeleteBtn()));
	connect(&setModelBtn, SIGNAL(clicked()), this, SLOT(clickSetModelBtn()));
}

void EditWindow::initBackSetBtn()
{
	// 字体设置
	QFont font;
	font.setFamily("SimHei");   // 黑体
	btIce.setFont(font);
	btFire.setFont(font);
	btLeaf.setFont(font);
	// 设置按钮背景色
	QPalette p;
	p = btIce.palette();
	p.setColor(QPalette::Button, QColor(105, 160, 255, 160));
	btIce.setPalette(p);
	btIce.setAutoFillBackground(true);
	p = btFire.palette();
	p.setColor(QPalette::Button, QColor(244, 30, 30, 160));
	btFire.setPalette(p);
	btFire.setAutoFillBackground(true);
	p = btLeaf.palette();
	p.setColor(QPalette::Button, QColor(30, 255, 45, 160));
	btLeaf.setPalette(p);
	btLeaf.setAutoFillBackground(true);
	btIce.setFlat(true);
	btFire.setFlat(true);
	btLeaf.setFlat(true);
	// 设置parent指针
	btIce.setParent(this);
	btFire.setParent(this);
	btLeaf.setParent(this);
	// 设置按钮文字
	btIce.setText(codec->toUnicode("冰"));
	btFire.setText(codec->toUnicode("火"));
	btLeaf.setText(codec->toUnicode("林"));
	// 显示按钮
	btIce.show();
	btFire.show();
	btLeaf.show();
	// 设置按钮大小及位置
	btIce.resize(100, 36);
	btIce.move(375, 705);
	btFire.resize(100, 36);
	btFire.move(525, 705);
	btLeaf.resize(100, 36);
	btLeaf.move(675, 705);
	// 设置按钮信号槽
	connect(&btIce, SIGNAL(clicked()), this, SLOT(setIce()));
	connect(&btFire, SIGNAL(clicked()), this, SLOT(setFire()));
	connect(&btLeaf, SIGNAL(clicked()), this, SLOT(setLeaf()));
	btIce.setDown(true);
}

void EditWindow::initItemBtn()
{
	QSignalMapper *qsm = new QSignalMapper(this);
	for (int i = 0; i < 20; i++)
	{
		items[i].setParent(this);                                            // 设置parent指针
		items[i].setGeometry(48 + 48 * (i % 5), 48 + 48 * (i / 5), 48, 48);  // 设置大小及位置
		items[i].setIcon(QIcon(QPixmap("img/item/item" + QString::number(i))));   // 设置图标
		items[i].setIconSize(QSize(48, 48));                                 // 设置图标大小
		items[i].setFlat(true);                                              // 原按钮图案不可见
		items[i].show();
		connect(&items[i], SIGNAL(clicked()), qsm, SLOT(map()));             // 设置信号槽
		qsm->setMapping(&items[i], i);
	}
	connect(qsm, SIGNAL(mapped(int)), this, SLOT(clickItem(int)));
}

void EditWindow::initEnemyBtn()
{
	QSignalMapper *qsm = new QSignalMapper(this);
	for (int i = 0; i < 25; i++)
	{
		enemies[i].setParent(this);
		enemies[i].setGeometry(48 + 48 * (i % 5), 48 + DIS_IT_TO_ENM + 48 * (i / 5), 48, 48);
		enemies[i].setIcon(QIcon(QPixmap("img/enemy/enemy" + QString::number(i))));
		enemies[i].setIconSize(QSize(48, 48));
		enemies[i].setFlat(true);
		enemies[i].show();
		connect(&enemies[i], SIGNAL(clicked()), qsm, SLOT(map()));
		qsm->setMapping(&enemies[i], i);
	}
	connect(qsm, SIGNAL(mapped(int)), this, SLOT(clickEnemy(int)));
}

void EditWindow::initGameBtn()
{
	QSignalMapper *qsm = new QSignalMapper(this);
	for (int i = 0; i < 15; i++)
	{
		games[i].setParent(this);
		games[i].setGeometry(48 + 48 * (i % 5), 48 + DIS_IT_TO_GM + 48 * (i / 5), 48, 48);
		games[i].setIcon(QIcon(QPixmap("img/game/game" + QString::number(i))));
		games[i].setIconSize(QSize(48, 48));
		games[i].setFlat(true);
		games[i].show();
		connect(&games[i], SIGNAL(clicked()), qsm, SLOT(map()));
		qsm->setMapping(&games[i], i);
	}
	connect(qsm, SIGNAL(mapped(int)), this, SLOT(clickGame(int)));
}

void EditWindow::initSelectFrame()
{
	selectFrame.setParent(this);
	selectFrame.setPixmap(QPixmap("img/system/selectFrame.png"));
	selectFrame.move(48, 48);
	selectFrame.show();	items[0].setParent(this);
	selectFrame.raise();
	selectFrame.setFixedSize(48, 48);
}

void EditWindow::initDrawPlace()
{
	drawPlace.setParent(this);
	drawPlace.show();
	drawPlace.setGeometry(311, 145, 48 * 11, 48 * 11);
	QPalette p = drawPlace.palette();
	p.setColor(QPalette::Background, QColor(255, 0, 0, 0));
	drawPlace.setAutoFillBackground(true);
	drawPlace.setPalette(p);
	drawPlace.setCursor(QCursor(QPixmap("img/item/item0.png")));
	drawPlace.setMouseTracking(true);
	connect(&drawPlace, SIGNAL(moving(int, int)), this, SLOT(updateDrawObj(int, int)));
}

void EditWindow::initDrawObj()
{
	drawObj.setParent(this);
	drawObj.setGeometry(0, 0, 48, 48);
	drawObj.setIcon(QIcon(QPixmap("img/item/item0.png")));
	drawObj.setIconSize(QSize(48, 48));
	drawObj.setFlat(true);
	drawObj.setCursor(QCursor(QPixmap("img/item/item0.png")));
	QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect;
	drawObj.setGraphicsEffect(opacityEffect);
	opacityEffect->setOpacity(0.65);
	connect(&drawObj, SIGNAL(clicked()), this, SLOT(putSquare()));
}

void EditWindow::initFloorChooseList()
{
	floorChoose.show();
	floorChoose.setParent(this);
	floorChoose.move(880, 50);
	connect(&floorChoose, SIGNAL(currentRowChanged(int)), this, SLOT(changeFileId(int)));
}

void EditWindow::initSquarePic()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			squaresPic[i][j].setParent(this);
			squaresPic[i][j].setGeometry(311 + i * 48, 145 + j * 48, 48, 48);
			if (isgt && isgi) squaresPic[i][j].setPixmap(QPixmap(getImgName(isgt->onUpdate(i, j), isgi->onUpdate(i, j))));
			squaresPic[i][j].show();
			squaresPic[i][j].lower();
		}
	}
}

// -- 属性获取函数
int EditWindow::getIndex()
{
	return index;
}

int EditWindow::getMap()
{
	return map;
}

int EditWindow::getType()
{
	if (index < 20)
		return 0;
	else if (index < 45)
		return 1;
	else
		return 0;
}

int EditWindow::getId()
{
	if (index < 20)
		return index;
	else if (index < 45)
		return index - 20;
	else
		return index - 25;
}

QString EditWindow::getImgName(int type, int index)
{
	QString ret;
	if (type == 0)
		if (index < 20)
			ret = "img/item/item" + QString::number(index);
		else
			ret = "img/game/game" + QString::number(index - 20);
	if (type == 1)
		ret = "img/enemy/enemy" + QString::number(index);
	return ret;
}

// -- 刷新函数
void EditWindow::setFramePos()
{
	if (index < 20)
		selectFrame.setGeometry(48 + 48 * (index % 5), 48 + 48 * (index / 5), 48, 48);
	else if (index < 45)
		selectFrame.setGeometry(48 + 48 * (index % 5), 48 + DIS_IT_TO_ENM - 48 * 4 + 48 * (index / 5), 48, 48);
	else
		selectFrame.setGeometry(48 + 48 * (index % 5), 48 + DIS_IT_TO_GM - 48 * 9 + 48 * (index / 5), 48, 48);
}

void EditWindow::update()
{
	currentFilenameLabel.setText(currentFilename);//(codec->toUnicode(currentFilename.to));//currentFilename.toLocal8Bit());
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (isgt && isgi) squaresPic[i][j].setPixmap(QPixmap(getImgName(isgt->onUpdate(i, j), isgi->onUpdate(i, j))));
		}
	}
}

// -- 保存文件函数
void EditWindow::saveFile()
{
	bool ok = false;
	int num = 0;
	if (iGetUntitledFloorNum) num = iGetUntitledFloorNum->onCallInt();
	QString oriUntitledName;
	oriUntitledName = "Untitled" + QString::number(num);
	QString filename = QInputDialog::getText(this, codec->toUnicode("保存层"), 
		                                     codec->toUnicode("请输入您要保存的层文件名："), 
		                                     QLineEdit::Normal, oriUntitledName, &ok);
	if (ok) {
		if (iSaveFile) {
			if (iSaveFile->onHandleFile(filename.toLocal8Bit().toStdString())) {
				QMessageBox::information(NULL, codec->toUnicode("魔塔关卡设计"), codec->toUnicode("成功保存当前层数据！"),
					QMessageBox::Ok, QMessageBox::Ok);
			} else {
				QMessageBox::warning(NULL, codec->toUnicode("魔塔关卡设计"), codec->toUnicode("保存失败！请检查您的输入。"),
					QMessageBox::Ok, QMessageBox::Ok);
			}
		}
		pFloorFileSet->filenameSetInit();
		floorChoose.setFileList();
	}
}

// -- 鼠标移动回调函数
void EditWindow::mouseMoveEvent(QMouseEvent *e)
{
	drawObj.hide();
}

// slots函数
void EditWindow::setIce()
{
	map = 0;
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/editbackice.jpg")));
	this->setPalette(p);
	btIce.setDown(true);
}

void EditWindow::setFire()
{
	map = 1;
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/editbackfire.jpg")));
	this->setPalette(p);
	btFire.setDown(true);
}

void EditWindow::setLeaf()
{
	map = 2;
	QPalette p = this->palette();
	p.setBrush(QPalette::Background, QBrush(QPixmap("img/system/editbackleaf.jpg")));
	this->setPalette(p);
	btLeaf.setDown(true);
}

void EditWindow::clickItem(int id)
{
	index = id;
	drawPlace.setCursor(QCursor(QPixmap("img/item/item" + QString::number(id))));
	drawObj.setCursor(QCursor(QPixmap("img/item/item" + QString::number(id))));
	drawObj.setIcon(QIcon(QPixmap("img/item/item" + QString::number(id))));
	setFramePos();
}

void EditWindow::clickEnemy(int id)
{
	index = id + 20;
	drawPlace.setCursor(QCursor(QPixmap("img/enemy/enemy" + QString::number(id))));
	drawObj.setCursor(QCursor(QPixmap("img/enemy/enemy" + QString::number(id))));
	drawObj.setIcon(QIcon(QPixmap("img/enemy/enemy" + QString::number(id))));
	setFramePos();
}

void EditWindow::clickGame(int id)
{
	index = id + 45;
	drawPlace.setCursor(QCursor(QPixmap("img/game/game" + QString::number(id))));
	drawObj.setCursor(QCursor(QPixmap("img/game/game" + QString::number(id))));
	drawObj.setIcon(QIcon(QPixmap("img/game/game" + QString::number(id))));
	setFramePos();
}

void EditWindow::updateDrawObj(int x, int y)
{
	drawObj.show();
	drawObj.move(((x - 311) / 48) * 48 + 311, ((y - 145) / 48) * 48 + 145);
}

void EditWindow::clickHelpBoardBtn()
{
	helpBoard = new HelpBoard();
}

void EditWindow::clickSaveBtn()
{
	saveFile();
}

void EditWindow::clickNewBtn()
{
	QMessageBox::StandardButton rb = QMessageBox::question(this, codec->toUnicode("魔塔关卡设计"), 
		                             codec->toUnicode("是否保存当前层？"), 
		                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	if (rb == QMessageBox::Yes)
		saveFile();
	if(iLoadFile) iLoadFile->onHandleFile("__new");
	currentFilename = "New Floor";
	update();
}

void EditWindow::clickOpenBtn()
{
	if (fileId == -1)
	{
		QMessageBox::warning(this, codec->toUnicode("魔塔关卡设计"),
			codec->toUnicode("请选中一个层文件！"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	std::string name = pFloorFileSet->getFilename(fileId);
	QMessageBox::StandardButton rb = QMessageBox::question(this, codec->toUnicode("魔塔关卡设计"),
		codec->toUnicode("是否保存当前层？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	if (rb == QMessageBox::Yes)
		saveFile();
	if (iLoadFile) {
		if (iLoadFile->onHandleFile(name)) {
			currentFilename = QString::fromLocal8Bit(name.c_str());
			update();
		}
		else {
			QMessageBox::warning(this, codec->toUnicode("魔塔关卡设计"),
				codec->toUnicode("不是有效的层文件！"), QMessageBox::Ok, QMessageBox::Ok);
		}
	}
}

void EditWindow::clickDeleteBtn()
{
	if (fileId == -1)
	{
		QMessageBox::warning(this, codec->toUnicode("魔塔关卡设计"),
			codec->toUnicode("请选中一个层文件！"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}
	std::string name = pFloorFileSet->getFilename(fileId);
	QMessageBox::StandardButton rb = QMessageBox::question(this, codec->toUnicode("魔塔关卡设计"),
		codec->toUnicode("确认删除") + QString::fromStdString(name) + codec->toUnicode("吗？"), 
		QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
	if (rb == QMessageBox::Yes)
		if (iDeleteFile) iDeleteFile->onHandleFile(name);
	pFloorFileSet->filenameSetInit();
	floorChoose.setFileList();
}

void EditWindow::clickSetModelBtn()
{

}

void EditWindow::putSquare()
{
	int type, id;
	if (index == 59)
		type = -1, id = 0;
	else
		type = getType(), id = getId();
	std::cout << "put!" << getType() << getId() << (drawObj.x() - 311) / 48 << (drawObj.y() - 145) / 48 << std::endl;
	iss->onSquareChange((drawObj.x() - 311) / 48, (drawObj.y() - 145) / 48, type, id);
	update();
}

void EditWindow::changeFileId(int num)
{
	fileId = num;
	std::cout << fileId << std::endl;
}

void EditWindow::generate()
{
	generateWindow.initialize(this);
	generateWindow.setModal(true);
	generateWindow.show();
}

void EditWindow::generateOk()
{
	bool ok = false;
	std::vector<int> temp = generateWindow.getInitialModel();
	QString name;
	name = QInputDialog::getText(this, codec->toUnicode("生成魔塔"), codec->toUnicode("请输入您要保存的魔塔游戏文件名："), QLineEdit::Normal, name, &ok);//.toLocal8Bit();
	if (ok) {
		if (name.isEmpty())
		{
			QMessageBox::warning(NULL, codec->toUnicode("魔塔关卡设计"), codec->toUnicode("文件名不能为空！"),
				QMessageBox::Ok, QMessageBox::Ok);
			return;
		}
		temp[0] = map;
		for (int i = 0; i < generateWindow.getList().size(); i++)
		{
			temp.push_back(pFloorFileSet->getFileNumber(generateWindow.getList()[i]));
		}

		if (iGenerate) {
			if (iGenerate->onGenerate(temp, name.toLocal8Bit().toStdString())) {
				QMessageBox::information(NULL, codec->toUnicode("魔塔关卡设计"), codec->toUnicode("已生成当前魔塔！"),
					QMessageBox::Ok, QMessageBox::Ok);
			}
			else {
				QMessageBox::warning(NULL, codec->toUnicode("魔塔关卡设计"), codec->toUnicode("文件名不合法！"),
					QMessageBox::Ok, QMessageBox::Ok);
			}
		}
		std::cout << "Success!" << std::endl;
	}
}