#include "FloorChoose.h"

FloorChoose::FloorChoose(std::shared_ptr<FloorFileSet> & pffs, QWidget *parent) : pFloorFileSet(pffs)
{
	setFixedSize(121, 300);
}

void FloorChoose::setFileList()
{
	clear();
	for (int i = 0; i < pFloorFileSet->getSize(); i++)
	{
		addItem(QString::fromLocal8Bit(pFloorFileSet->getFilename(i).c_str()));
		//addItem(QString::fromStdString(pFloorFileSet->getFilename(i)));
	}
}