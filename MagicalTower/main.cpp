#include "App.h"

int main(int argc, char *argv[])
{
	MagicalTower Q(argc, argv);
	Q.Init();
	return Q.exec();
}
