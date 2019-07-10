#include "SelectWindow.h"
#include "EditWindow.h"
#include <QtWidgets/QApplication>
#include "qpushbutton.h"
#include <qtextbrowser.h>
#include "EditorViewModel.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EditorViewModel evm;
	SelectWindow w(&evm);
	w.show();
	return a.exec();
}
