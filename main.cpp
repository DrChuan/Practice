#include "SelectWindow.h"
#include "EditWindow.h"
#include <QtWidgets/QApplication>
#include "qpushbutton.h"
#include <qtextbrowser.h>

int main(int argc, char *argv[])
{
	EditorViewModel evm;
	QApplication a(argc, argv);
	SelectWindow w(&evm);
	w.show();
	return a.exec();
}
