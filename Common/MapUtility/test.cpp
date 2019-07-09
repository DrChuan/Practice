#include "MapUtility.h"
#include<iostream>

int main() {
	Square s(1,2);
	std::cout << "type is: " << s.getType() << std::endl;
	std::cout << "index is: " << s.getIndex() << std::endl;
	s.setIndex(-1); s.setType(2);
	std::cout << s << std::endl;

	Floor floor("a");
	std::cout << floor.getIndex() << std::endl;
	floor.setIndex(2);
	floor.setSquare(0, 1, 2, 3);
	std::cout << floor.getSquare(2, 3)<<std::endl;
	floor.saveFloor();
	floor.setSquare(3, 3, 2, 3);
	floor.loadFloor();
	std::cout << floor.getSquare(2, 3)<<std::endl;
	std::cout << floor.getName()<<std::endl;

	FloorSet floors("k");
	floors.addFloor(Floor::Floor("b", 0));
	floors.addFloor(Floor::Floor("x", 1));
	floors.setSquare(1, 1, 1, 2, 2);
	std::cout << floors.getFloorNum()<<" "<<floors.getName()<<std::endl;
	std::cout << floors.getSquare(1, 2, 2) << std::endl;
	floors.saveFloorSet();
	floors.loadFloorSet();
	std::cout << floors.getSquare(1, 2, 2) << std::endl;

}