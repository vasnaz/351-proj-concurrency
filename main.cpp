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


intersection<Car> mainint;



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
		Car createcar(i);
		
		mainint.addCar(createcar); //adds car to intersection queue


	}

	return 0;
}