#include <string>
#include <vector>
class FloorFileSet {
private:
	std::vector<std::string> filenameSet;

public:
	void filenameSetInit();
	//初始化/重置filenameSet。会读取当前文件夹下的floors_ws文件夹内所有文件名（忽略子目录）

	std::string getFilename(int index) { return filenameSet[index]; }

	int getFileNumber(std::string filename);

	unsigned int getSize() { return (unsigned int)filenameSet.size(); }

};