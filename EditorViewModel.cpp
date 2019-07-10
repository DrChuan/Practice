#include<string>
#include<vector>
#include"MapUtility.h"
#include"FloorFileSet.h"
using std::string;
using std::vector;

class EditorViewModel {
	FloorFileSet m_floorFileSet;
	Floor m_floor;
public:
	void setFloorSquare(int x, int y, int type, int index) {
		m_floor.setSquare(type, index, x, y);
	}
	Floor getFloor() {
		return m_floor;
	}
	void saveFloor() {
		string filename = m_floor.getName();
		string path = "floor_work\\" + filename;
		m_floor.setName(path);
		m_floor.saveFloor();
		m_floor.setName(filename);
	}
	void loadFloor() {
		string filename = m_floor.getName();
		string path = "floor_work\\" + filename;
		m_floor.setName(path);
		m_floor.loadFloor();
		m_floor.setName(filename);
	}
	void generateFloorSet(vector<int> floorsIndex, string filename) {
		FloorSet floors(filename);
		for (int i = 0; i < floorsIndex.size(); i++) {
			string filename = m_floorFileSet.getFilename(floorsIndex[i]);
			string path = "floor_work\\" + filename;
			m_floor.setName(path);
			m_floor.loadFloor();
			m_floor.setName(filename);
			m_floor.setIndex(i);
			floors.addFloor(m_floor);
		}
		floors.saveFloorSet();
	}
};
