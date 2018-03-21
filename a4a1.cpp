/* 351-04 Concurrency Project
Project Members: Bill Nazaroff, Joon Choi */


#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include <semaphore.h>
#include "car.h"
//#include <intersection.h>

using namespace std;

#define NUM_CARS 200

//Linked List Class for cars from each lane; North, South, East, and West

class CarNode
{
public:

	Car *hold;
	CarNode *next;
	CarNode (Car *niceone, CarNode *ptr = 0) 
	{
		hold = niceone;
		next = ptr;
	}
};

class CarList
{
public:
	CarList()
	{
		end = front = 0;
	}
	void enqueue(Car *a)
	{
		end = new CarNode(a, end);
		if (front == 0)
			front = end;
	}
	int dequeue()
	{
		int temp = front->id;	
		CarNode *tmp = front;	

		if (front == end)		
			front = end = 0;	
		else
		{
			front = front->next;	
		}

		delete tmp;				
		return temp;
	}

	void printAll() const // test purpose
	{
		for (CarNode *tmp = front; tmp != 0; tmp = tmp->next)
			cout << tmp->id << " ";
		cout << endl;
	}


private:
	CarNode *end, *front;
};



void main(int argc, char *argv[]) {
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


	CarList *NorthLeft = new CarList();
	CarList *NorthRight = new CarList();
	CarList *SouthLeft = new CarList();
	CarList *SouthRight = new CarList();
	CarList *EastLeft = new CarList();
	CarList *EastRight = new CarList();
	CarList *WestLeft = new CarList();
	CarList *WestRight = new CarList();

	pthread_t thread[NUM_CARS];

	sem_t quad1;
	sem_t quad2;
	sem_t quad3;
	sem_t quad4;
	sem_t center;

	bool done = false;

	
	for (int i = 0; i < NUM_CARS; i++) {
		Car car(i);

		switch (car.GetDesiredDirection()) {
		case STRAIGHT:
			switch (rand() % 8) {
			case 0:
				NorthLeft->enqueue(&car);
				break;
			case 1:
				NorthRight->enqueue(&car);
				break;
			case 2:
				SouthLeft->enqueue(&car);
				break;
			case 3:
				SouthRight->enqueue(&car);
				break;
			case 4:
				EastLeft->enqueue(&car);
				break;
			case 5:
				EastRight->enqueue(&car);
				break;
			case 6:
				WestLeft->enqueue(&car);
				break;
			case 7:
				WestRight->enqueue(&car);
				break;
			}
			break;
		case LEFT:
			switch (rand() % 4) {
			case 0:
				NorthLeft->enqueue(&car);
				break;
			case 1:
				SouthLeft->enqueue(&car);
				break;
			case 2:
				EastLeft->enqueue(&car);
				break;
			case 3:
				WestLeft->enqueue(&car);
				break;
			}
			break;
		case UTURN:
			switch (rand() % 4) {
			case 0:
				NorthLeft->enqueue(&car);
				break;
			case 1:
				SouthLeft->enqueue(&car);
				break;
			case 2:
				EastLeft->enqueue(&car);
				break;
			case 3:
				WestLeft->enqueue(&car);
				break;
			}
			break;
		case RIGHT:
			switch (rand() % 4) {
			case 0:
				NorthRight->enqueue(&car);
				break;
			case 1:
				SouthRight->enqueue(&car);
				break;
			case 2:
				EastRight->enqueue(&car);
				break;
			case 3:
				WestRight->enqueue(&car);
				break;
			}
			break;

		}
	}
		//need to initialize quads and starrt pthread_creates
		sem_init(&quad1, 0, 1);
		for (int i = 0; i < NUM_THREADS; i++)
		{
			//pthread_create(&thread[i], NULL, (void *) &intersection, (void *) )
		}
		sem_init(&quad2, 0, 1);
		sem_init(&quad3, 0, 1);
		sem_init(&quad4, 0, 1);
		

	}


}