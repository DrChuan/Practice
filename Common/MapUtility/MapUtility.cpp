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


//Floor ��ò�Ҫ��Floor���͵Ĳ������ݣ�ȫ�������ô���

Floor::Floor(string name, int index){ 
	//char nnum[6];
	//snprintf(nnum, 6, "%05d", m_index);
	m_name = name;// +nnum;
	m_index = index;
}

bool Floor::saveFloor() {
	ofstream fout;
	fout.open(m_name, ios_base::out|ios_base::binary);//�˴����Կ��ǸĽ�һ�£��ȼ���ļ��Ƿ���ڣ�����������ʾһ���û��Ƿ񸲸�
	if (!fout.is_open()) {
		cerr << "Can't open the file:" << m_name << "\n";//��ʱ�����������Ժ��ٸ��쳣��ʾ��ʽ
		return false;
	}

	for (auto i : m_name) {//������
		fout.write((char*)& i, sizeof i);
	}
	int mo = 0; 
	fout.write((char*)&mo, 1);//ĩβ��0

	fout.write((char*)& m_index, sizeof m_index);
	for (int i = 0; i < silen; i++)
		for (int j = 0; j < silen; j++)
		{
			fout.write((char *) &m_squares[i][j], len_square);
		}
	fout.close();
	return true;
}

//��¼һ��string��ʹ�ò��淶���µ�bug. m_name+='\0' ������string���¼��size�� 1
bool Floor::loadFloor() {
	ifstream fcin;
	fcin.open(m_name, ios_base::in | ios_base::binary);
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
	}//����0Ϊֹ��ע�����һ��0������string��
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

bool  FloorSet::loadFloorSet() {
	ifstream fcin;
	fcin.open(m_name + "\\" + m_name + ".set", ios_base::in);
	if (!fcin.is_open()) {
		cerr << "Can't open the file:" << m_name << "\n";	//��ʱ�����������Ժ��ٸ��쳣��ʾ��ʽ
		return false;
	}
	char filename[30]; 
	int m_floorNum = 0;
	m_floors.clear();
	while(fcin.getline(filename, 30) && (filename[0]!='\0')) {
		string path = m_name + "\\" + filename;
		m_floors.push_back(Floor::Floor(path,m_floorNum));
		m_floors[m_floorNum].loadFloor();
		m_floors[m_floorNum].setName(filename);
		m_floorNum++;
	}
	fcin.close();
	return true;
}

bool  FloorSet::saveFloorSet() {
	if ((_access(m_name.c_str(), 0) == -1))
		if (_mkdir(m_name.c_str()) != 0) {
			cerr << "Directory is not exists and can't create the directory:" << m_name << "\n";
		}

	ofstream fout;
	fout.open(m_name + "\\" + m_name + ".set", ios_base::out);
	if (!fout.is_open()) {
		cerr << "Can't open the file:" << m_name << "\n";//��ʱ�����������Ժ��ٸ��쳣��ʾ��ʽ
		return false;
	}
	for (Floor& x : m_floors) {
		string filename = x.getName();
		string path = m_name + "\\" + filename;
		x.setName(path);
		x.saveFloor();
		x.setName(filename);
		fout << filename << endl;
	}
	fout << endl;
	fout.close();
	return true;
}

