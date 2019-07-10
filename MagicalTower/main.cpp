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
	SelectWindow w;

	w.editWindow = new EditWindow();
	w.editWindow->iss = evm.m_sssink;
	w.editWindow->isgi = evm.m_sgIink;
	w.editWindow->isgt = evm.m_sgTink;
	w.show();
	return a.exec();
}
