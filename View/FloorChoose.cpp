#include "FloorChoose.h"

FloorChoose::FloorChoose(std::shared_ptr<FloorFileSet> & pffs, QWidget *parent) : pFloorFileSet(pffs)
{
	setFixedSize(120, 300);
	//pFloorFileSet = pffs;
	//setFileList();
}

void FloorChoose::setFileList()
{
	for (int i = 0; i < pFloorFileSet->getSize(); i++)
	{
		addItem(QString::fromStdString(pFloorFileSet->getFilename(i)));
	}
	this->addItem("HAHA1");
	this->addItem("HAHA2");
	this->addItem("HAHA3");
}