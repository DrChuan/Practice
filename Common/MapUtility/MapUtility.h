//���ĵ������б���/��ȡ�����ɵ��ú������˱�֤·���Ĵ����ԣ����ԸĽ�һ����·���������򴴽���
#pragma once
#define silen  11
#include <iostream>
#include <string>
#include <vector>

class Square {
private:
	int m_type, m_index;
	
public:
	Square(int type = -1, int index = -1) : m_type(type), m_index(index) {}

	void setType(int type) { m_type = type; }
	void setIndex(int index) { m_index = index; }

	int getType() { return m_type; }
	int getIndex() { return m_index; }

	friend std::ostream& operator<<(std::ostream& os, const Square& square);
	friend std::istream& operator>>(std::istream& os, const Square& square);

	~Square(){}
};

class Floor {
private:
	static const int len_square = sizeof Square;

	int m_index;

	Square m_squares[11][11];

	std::string m_name;

public:
	
	Floor(std::string name="Focused Floor", int index = -1);

	bool saveFloor(std::string path = "floors_ws");
	bool loadFloor(std::string path = "floors_ws"); 

	int getIndex() { return m_index; }
	void setIndex(int index) { m_index = index; }

	void setSquare(int type, int index, int x, int y) { m_squares[x][y].setIndex(index); m_squares[x][y].setType(type); }
	Square getSquare(int x, int y) { return m_squares[x][y]; }

	std::string& getName() { return m_name; }
	void setName(std::string name) { m_name = name; }
};


class FloorSet {

private:

	std::vector<Floor> m_floors;

	std::string m_name;

public:
	
	FloorSet(std::string name):m_name(name){}//���캯��

	bool loadFloorSet(std::string path="game"); //save�ᴴ��һ��m_name�ļ��У������ļ����ڱ����ļ���load��ȡͬ��
	bool saveFloorSet(std::string path="game"); //ͬ�ϣ��������������������void�ͣ��ָ�Ϊbool�͡�����Ͷ�ȡ������

	int getFloorNum() { return m_floors.size(); }

	void setName(std::string name) { m_name = name; }
	std::string getName() { return m_name; }

	Square getSquare(int floor_index, int x, int y) { return m_floors[floor_index].getSquare(x, y); }
	void setSquare(int floor_index, int type, int index, int x, int y) { m_floors[floor_index].setSquare(type, index, x, y); }

	void addFloor(Floor floor) { m_floors.push_back(floor);  }

};
