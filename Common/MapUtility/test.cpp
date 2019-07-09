#include "MapUtility.h"
#include<iostream>

int main() {
	Square s(1,2);
	std::cout<<"New Square with (type=1,index=2)"<<std::endl;
	std::cout << "type is: " << s.getType() << std::endl;
	std::cout << "index is: " << s.getIndex() << std::endl;
	std::cout<<"Change (type,index) into (-1, 2)"<<std::endl;
	s.setIndex(-1); s.setType(2);
	std::cout << s << std::endl;

	Floor floor("a");
	std::cout<<"New Floor with (name= a )"<<std::endl;
	std::cout << "The default index is"<<floor.getIndex() << std::endl;
	floor.setIndex(2);
	std::cout<<"set floor with index=2"<<std::endl;
	std::cout<<"The index of the floor is"<<floor.getIndex()<<std::endl;
	floor.setSquare(0, 1, 2, 3);
	std::cout<<"Set square(2,3) in floor with (type=0, index=1)"<<std::endl;
	std::cout << "Square(2,3) is "<<floor.getSquare(2, 3)<<std::endl;
	std::cout<<"save the floor"<<std::endl;
	floor.saveFloor();
	floor.setSquare(3, 3, 2, 3);
	std::cout<<"Reset square(2,3) with (type=3, index=3)"<<std::endl;
	floor.loadFloor();
	std::cout<<"load the floor"<<std::endl;
	std::cout <<"The square(2,3) is " << floor.getSquare(2, 3)<<std::endl;
	std::cout <<"The floor name is"<< floor.getName()<<std::endl;

	FloorSet floors("k");
	std::cout<<"New FloorSet with name= k "<<std::endl;
	floors.addFloor(Floor::Floor("b", 0));
	std::cout<<"Add a floor with (\"b\",0)"<<std::endl;
	floors.addFloor(Floor::Floor("x", 1));
	std::cout<<"Add a floor with (\"x\",1)"<<std::endl;
	floors.setSquare(1, 1, 1, 2, 2);
	std::cout<<"Set the square(2,2) of the second floor with (1,1)"<<std::endl;
	std::cout <<"floorsNum & name of the floorset is: "<< floors.getFloorNum()<<" "<<floors.getName()<<std::endl;
	std::cout <<"The square(2,2) of the second floor is"<< floors.getSquare(1, 2, 2) << std::endl;
	floors.saveFloorSet();
	std::cout<<"Save floorset"<<std::endl;
	floors.loadFloorSet();
	std::cout<<"load the floorset"<<std::endl;
	std::cout <<"The square(2,2) of the second floor is"<< floors.getSquare(1, 2, 2) << std::endl;

}