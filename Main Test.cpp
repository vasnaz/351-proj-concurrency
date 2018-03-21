#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "car.h"

#define NUM_CARS 400
using namespace std;

class CarNode
{
public:

	Car *hold;
	CarNode *next;
	CarNode(Car *niceone, CarNode *ptr = 0)
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
			cout << tmp->hold->GetID()<< " ";
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

int main()
{
	CarList *North = new CarList();
	CarList *South = new CarList();
	CarList *East = new CarList();
	CarList *West = new CarList();

	for (int i = 0; i < NUM_CARS; i++)
	{
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


	Car car(3);

	cout << "The list: ";
	car.GetID();
	North->enqueue(&car);
	Car car2(5);
	North->enqueue(&car2);
	Car car3(10);
	North->enqueue(&car3);


	cout << "North List: ";
	North->printAll();
	cout << "South List: ";
	South->printAll();
	cout << "East List: ";
	East->printAll();
	cout << "West List: ";
	West->printAll();

	North->dequeue();
	cout << "The list After Dequeue1: ";
	North->printAll();

	North->dequeue();
	cout << "The list After Dequeue2: ";
	North->printAll();

	delete North;
	delete South;
	delete East;
	delete West;

	system("PAUSE");
}