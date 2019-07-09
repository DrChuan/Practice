#include <io.h>
#include "FloorFileSet.h"

void FloorFileSet::filenameSetInit() {
	intptr_t   hFile = 0; //文件信息 
	struct _finddata_t fileinfo;
	std::string path = "floors_ws";
	std::string p;
	filenameSet.clear();
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR)==0)//如果不是目录
			{
				filenameSet.push_back(p.assign(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

int FloorFileSet::getFileNumber(std::string filename) {
	for (int i = 0; i < filenameSet.size(); i++) {
		if (filenameSet[i] == filename)
			return i;
	}
}