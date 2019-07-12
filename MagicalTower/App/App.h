#pragma once
#include "SelectWindow.h"
#include "EditWindow.h"
#include <QtWidgets/QApplication>
#include "qpushbutton.h"
#include <qtextbrowser.h>
#include "EditorViewModel.h"

class MagicalTower : public QApplication {
public:
	EditorViewModel evm;
	SelectWindow w;
	MagicalTower(int, char*[]);
	void Init();
};