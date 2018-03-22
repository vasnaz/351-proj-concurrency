
/* 351-04 Concurrency Project
Project Members: Bill Nazaroff, Joon Choi */


#include <iostream>
#include <vector>
#include <string>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "car.h"
#include "intersection.h"

using namespace std;

#define NUM_CARS 400
#define NUM_THREADS 4

//Linked List Class for car queue for each direction

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
	void enqueue(Car *add)
	{
		if (end != 0)
		{
			end->next = new CarNode(add);
			end = end->next;
		}
		else
			front = end = new CarNode(add);
	}
	Car dequeue()
	{
		Car *temp = front->hold;	
		CarNode *tmp = front;	

		if (front == end)		
			front = end = 0;	
		else
		{
			front = front->next;	
		}

		delete tmp;				
		return *temp;
	}
	
	void printAll() const // test purpose
	{
		for (CarNode *tmp = front; tmp != 0; tmp = tmp->next)
			cout << tmp->hold->GetID() << " ";
		cout << endl;
	}
	
	~CarList()
	{
		while (front != NULL)
		{
			CarNode *temp = front->next;
			delete[] front;
			front = temp;
		}
	}

private:
	CarNode *end, *front;
};

intersection a;
CarList *North = new CarList();
CarList *South = new CarList();
CarList *East = new CarList();
CarList *West = new CarList();
void simN(Car b);
void simE(Car b);
void simS(Car b);
void simW(Car b);
void *simStart(void* threadid)
{
	long tid;
	tid = (long)threadid;
	while(1)
	{
	int choice = rand() % 4;
	if(choice == 0)
	{
		simN(North->dequeue());
	}
	else if(choice == 1)
	{
		simE(East->dequeue());
	}	
	else if(choice == 2)
	{
		simE(South->dequeue());
	}
	else if(choice == 3)
	{
		simE(West->dequeue());
	}
	}
cout << "visited\n";
	pthread_exit(NULL);
}
int main(int argc, char *argv[]) {
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


	

	pthread_t threads[NUM_THREADS];
	int rc;
	int i;

	sem_t quad1;
	sem_t quad2;
	sem_t quad3;
	sem_t quad4;
	sem_t center;

	bool done = false;

	
	for (int i = 0; i < NUM_CARS; i++) {
		Car *car = new Car(i);
		switch (rand() % 4) {
			case 0:
				North->enqueue(car);
				break;
			case 1:
				South->enqueue(car);
				break;
			case 2:
				East->enqueue(car);
				break;
			case 3:
				West->enqueue(car);
				break;
		}
		
	}
		//need to initialize quads and starrt pthread_creates
	for (i = 0; i < 4; i++)
	{
		sem_init(&readA[i], 0, 1);
	}
	for (i = 0; i < NUM_THREADS; i++)
	{
		cout << "main (): creating thread: " << i << endl;
		rc = pthread_create(&threads[i], NULL, simStart, (void*) (intptr_t) i);
		if (rc)
		{
			cout << "unable to create thread: " << i << endl;
			exit(-1);
		}
	}
	//sim1(NorthRight->dequeue());
	pthread_exit(NULL);
	for (i = 0; i < 4; i++)
	{
		sem_destroy(&readA[i]);
	}
	return 0;

	}
//only cars that are North will be here
void simN(Car b)
{
	
	switch (b.GetDesiredDirection()) {
		case STRAIGHT:
			a.access(3);
			a.access(2);
			a.setFree(3);
			a.setFree(2);
			cout << "--Car drove straight.\n";
			break;
		case LEFT:
			a.access(4);
			a.access(3);
			a.access(2);
			a.setFree(4);
			a.setFree(3);
			a.setFree(2);
			cout << "--Car made Left turn.\n";
			break;
		case UTURN:
			a.access(2);
			a.access(1);
			a.setFree(2);
			a.setFree(1);
			cout << "--Car made U-turn.\n";
			break;
		case RIGHT:
			a.access(2);
			a.setFree(2);
			cout << "--Car made right turn.\n";
			break;

		}
}
void simE(Car b)
{
	
	switch (b.GetDesiredDirection()) {
		case STRAIGHT:
			a.access(2);
			a.access(1);
			a.setFree(2);
			a.setFree(1);
			cout << "--Car drove straight.\n";
			break;
		case LEFT:
			a.access(3);
			a.access(2);
			a.access(1);
			a.setFree(3);
			a.setFree(2);
			a.setFree(1);
			cout << "--Car made Left turn.\n";
			break;
		case UTURN:
			a.access(4);
			a.access(1);
			a.setFree(4);
			a.setFree(1);
			cout << "--Car made U-turn.\n";
			break;
		case RIGHT:
			a.access(1);
			a.setFree(1);
			cout << "--Car made Right turn.\n";
			break;

		}
}
void simS(Car b)
{
	
	switch (b.GetDesiredDirection()) {
		case STRAIGHT:
			a.access(4);
			a.access(1);
			a.setFree(4);
			a.setFree(1);
			cout << "--Car drove straight.\n";
			break;
		case LEFT:
			a.access(4);
			a.access(2);
			a.access(1);
			a.setFree(4);
			a.setFree(2);
			a.setFree(1);
			cout << "--Car made Left turn.\n";
			break;
		case UTURN:
			a.access(4);
			a.access(3);
			a.setFree(4);
			a.setFree(3);
			cout << "--Car made U-turn.\n";
			break;
		case RIGHT:
			a.access(4);
			a.setFree(4);
			cout << "--Car made Right turn.\n";
			break;

		}
}
void simW(Car b)
{
	
	switch (b.GetDesiredDirection()) {
		case STRAIGHT:
			a.access(4);
			a.access(3);
			a.setFree(4);
			a.setFree(3);
			cout << "--Car drove straight.\n";
			break;
		case LEFT:
			a.access(4);
			a.access(3);
			a.access(1);
			a.setFree(4);
			a.setFree(3);
			a.setFree(1);
			cout << "--Car made Left turn.\n";
			break;
		case UTURN:
			a.access(3);
			a.access(2);
			a.setFree(3);
			a.setFree(2);
			cout << "--Car made U-turn.\n";
			break;
		case RIGHT:
			a.access(3);
			a.setFree(3);
			cout << "--Car made Right turn.\n";
			break;

		}

}
