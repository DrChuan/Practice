#include"MapUtility.h"
#include <fstream>
#include <cstdlib>
#include <io.h>
#include <direct.h>
using namespace std;
//Square

ostream& operator<<(ostream& os, const Square& square) {
	os << square.m_type << " " << square.m_index;
	return os;
}

istream& operator>>(istream& os, const Square& square) {
	os >> square.m_type >> square.m_index;
	return os;
}


//Floor 最好不要有Floor类型的参数传递，全部用引用代替

Floor::Floor(string name, int index){ 
	//char nnum[6];
	//snprintf(nnum, 6, "%05d", m_index);
	m_name = name;// +nnum;
	m_index = index;
}

bool Floor::saveFloor(string path) {
	string name;
	if (path.c_str()!=nullptr)
		name = path + "\\" + m_name;
	else 
		name = m_name;
	ofstream fout;
	fout.open(name.c_str(), ios_base::out|ios_base::binary);//此处可以考虑改进一下，先检查文件是否存在，若存在则提示一下用户是否覆盖
	if (!fout.is_open()) {
		cerr << "Can't open the file:" << m_name << "\n";//暂时先这样，，以后再改异常提示方式
		return false;
	}

	for (auto i : m_name) {//存名字
		fout.write((char*)& i, sizeof i);
	}
	int mo = 0; 
	fout.write((char*)&mo, 1);//末尾存0

	fout.write((char*)& m_index, sizeof m_index);
	for (int i = 0; i < silen; i++)
		for (int j = 0; j < silen; j++)
		{
			fout.write((char *) &m_squares[i][j], len_square);
		}
	fout.close();
	return true;
}

//记录一个string类使用不规范导致的bug. m_name+='\0' 将导致string类记录的size加 1
bool Floor::loadFloor(string path) {
	string name;
	if (path.c_str()!=nullptr)
		name = path +"\\"+ m_name;
	else
		name = m_name;
	ifstream fcin;
	fcin.open(name.c_str(), ios_base::in | ios_base::binary);
	if (!fcin.is_open()) {
		cerr << "Can't open the file:" << m_name << "\n";
		return false;
	}
	m_name = "\0";
	char a;
	fcin.read((char*)& a, 1);
	while (a != 0) {
		m_name += a;
		fcin.read((char*)& a, 1);
	}//读到0为止，注意最后一个0不能用string加
	//fcin.read((char*)&m_name, sizeof m_name);
	fcin.read((char*)& m_index, sizeof m_index);
	for (int i = 0; i < silen; i++)
		for (int j = 0; j < silen; j++)
		{
			fcin.read((char *) &m_squares[i][j], len_square);
		}
	fcin.close();
	return true;
}


//FloorSet

bool  FloorSet::loadFloorSet(string path) {
	string Npath;
	if (path.c_str() == nullptr)
		Npath = m_name;
	else
		Npath = path + "\\" + m_name;

	ifstream fcin;
	fcin.open(Npath + "\\" + m_name + ".set", ios_base::in);
	if (!fcin.is_open()) {
		cerr << "Can't open the file:" << m_name << "\n";	//暂时先这样，，以后再改异常提示方式
		return false;
	}
	char filename[30]; 
	int m_floorNum = 0;
	m_floors.clear();
	while(fcin.getline(filename, 30) && (filename[0]!='\0')) {
		m_floors.push_back(Floor::Floor(filename,m_floorNum));
		m_floors[m_floorNum].loadFloor(Npath);
		m_floorNum++;
	}
	fcin.close();
	return true;
}

bool  FloorSet::saveFloorSet(string path) {
	string Npath;
	if (path.c_str() == nullptr)
		Npath = m_name;
	else
		Npath = path + "\\" + m_name;	
	
	if ((_access((Npath).c_str(), 0) == -1))
		if (_mkdir((Npath).c_str()) != 0) {
			cerr << "Can't open or create the directory:" << m_name << "\n";
		}

	ofstream fout;
	fout.open(Npath + "\\" + m_name + ".set", ios_base::out);//这边最好加一下不存在目录则创建
	if (!fout.is_open()) {
		cerr << "Can't open the file:" << m_name << "\n";//暂时先这样，，以后再改异常提示方式
		return false;
	}
	
	for (Floor& x : m_floors) {
		if(!x.saveFloor(Npath))  return false;
		fout << x.getName() << endl;
	}
	fout << endl;
	fout.close();
	return true;
}

