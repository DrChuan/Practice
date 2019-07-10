#pragma once
#include <QtWidgets/QMainWindow>
#include "qlabel.h"
#include "qevent.h"

class DrawPlace : public QLabel {
	Q_OBJECT
public:
	void mouseMoveEvent(QMouseEvent *e);
signals:
	void moving(int x, int y);
};