#pragma once
//#include "preInclude.h"
#include <fstream>
#include <string>
#include "IGetSink.h"
using namespace std;
int IGetSink::onCallInt() {
	string name = "floor_ws\\Untitled";
	ofstream fout;
	int i=0;
	fout.open(name + to_string(i), ios_base::in);
	while (fout.is_open()) {
		i++;
		fout.open(name + to_string(i), ios_base::in);
	}
	return i;
}