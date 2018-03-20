/* 351-04 Concurrency Project
Project Members: Bill Nazaroff, <insert names> */


#include <iostream>
#include <vector>
#include <string>

//Car
#include "car.h"
#include <cstdlib>

using namespace std;


int main() {

//TO DO: Joon and Bill
//Create Intersection of 5 quadrants
//Create random child processes (cars)
//Create while loop
    /*Loop needs to take in cars, check the path in the intersection, and check locks */

//Process
//1. Enqueue cars into Linked list and add to array (if necessary)
//2. If any cars have gone (i.e. driven their route), move to next quadrant
//2a. Release Current quad lock and next state quad lock
//2b. Lock current quad lock of the next quadrant of the route
//2c. If car is finished with route, release lock and dequeue
//3. Next Car: Lock current quadrant (for clock cycle 1) and lock next state
//4. Look for other cars that can lock current and next state 


	//Create lane queues
	//Queue NorthLeft
	//Queue NorthRight
	//Queue SouthLeft
	//Queue SouthRight
	//Queue EastLeft
	//Queue EastRight
	//Queue WestLeft
	//Queue WestRight

	//Create 400 cars
	for(int i=0;i<400;i++) {
		//Create new car
		Car car;
		
		//Randomly assign car to a lane depending on desired direction
		switch(car.GetDesiredDirection()) {
			case STRAIGHT:
				switch(rand() % 8) {
					case 0:
						//NorthLeft.Add(car);
						break;
					case 1:
						//NorthRight.Add(car);
						break;
					case 2:
						//Southeft.Add(car);
						break;
					case 3:
						//SouthRight.Add(car);
						break;
					case 4:
						//EastLeft.Add(car);
						break;
					case 5:
						//EastRight.Add(car);
						break;
					case 6:
						//WestLeft.Add(car);
						break;
					case 7:
						//WestRight.Add(car);
						break;
				}
				break;
			case LEFT:
			case UTURN:
				switch(rand() % 4) {
					case 0:
						//NorthLeft.Add(car);
						break;
					case 1:
						//SouthLeft.Add(car);
						break;
					case 2:
						//EastLeft.Add(car);
						break;
					case 3:
						//WestLeft.Add(car);
						break;
				}
				break;
			case RIGHT:
				switch(rand() % 4) {
					case 0:
						//NorthRight.Add(car);
						break;
					case 1:
						//SouthRight.Add(car);
						break;
					case 2:
						//EastRight.Add(car);
						break;
					case 3:
						//WestRight.Add(car);
						break;
				}
				break;
		}
	}


	return 0;
}