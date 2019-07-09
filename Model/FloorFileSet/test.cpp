#include <iostream>
#include "FloorFileSet.h"
using namespace std;
int main() {
	FloorFileSet set;
	set.filenameSetInit();
	for (int i = 0; i < set.getSize(); i++) {
		cout << set.getFilename(i) << endl;
	}
	int stop;
	cin >> stop;
	set.filenameSetInit();
	for (int i = 0; i < set.getSize(); i++) {
		cout << set.getFilename(i) << endl;
	}
}