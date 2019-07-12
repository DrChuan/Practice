#pragma once

#include <QtWidgets/QMainWindow>
#include "qlistwidget.h"
#include "FloorFileSet.h"

class FloorChoose : public QListWidget {
public:
	FloorChoose(std::shared_ptr<FloorFileSet> & pffs, QWidget *parent = Q_NULLPTR);
	void setFileList();
private:
	std::shared_ptr<FloorFileSet> & pFloorFileSet;
};