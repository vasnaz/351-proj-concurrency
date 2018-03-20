//car class
//Brian: Cars and threading
//Beau: Threading

#include <cstdio>
#include <cstdlib>

typedef enum {
	STRAIGHT,
	LEFT,
	RIGHT,
	UTURN
} Direction;

class Car {
	private:
	bool ThroughIntersection;
	Direction DesiredDirection;
	int WaitTime;
	
	public:
	Car();
	~Car();
	
	Direction GetDesiredDirection();
	
	void SetThroughIntersection(bool);
	bool GetThroughIntersection();
	
	void IncrementWaitTime();
	int GetWaitTime();
	
	
};

Car::Car() {
	int desiredDirection = rand() % 4;
	this->DesiredDirection = static_cast<Direction>(desiredDirection);
	
	this->WaitTime = 0;
	this->ThroughIntersection = false;
	
	/*printf("Created car with random direction: ");
	switch(this->DesiredDirection) {
		case STRAIGHT:
		printf("STRAIGHT\n");
			break;
		case LEFT:
		printf("LEFT\n");
			break;
		case RIGHT:
		printf("RIGHT\n");
			break;
		case UTURN:
		printf("UTURN\n");
			break;
	}*/
}

Car::~Car() {
	
}

Direction Car::GetDesiredDirection() {
	return this->DesiredDirection;
}

void Car::SetThroughIntersection(bool through) {
	this->ThroughIntersection = through;
}

bool Car::GetThroughIntersection() {
	return this->ThroughIntersection;
}

void Car::IncrementWaitTime() {
	this->WaitTime++;
}

int Car::GetWaitTime() {
	return this->WaitTime;
}