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
	int ID;
	bool ThroughIntersection;
	Direction DesiredDirection;
	
	public:
	Car(int);
	~Car();
	
	int GetID();
	
	Direction GetDesiredDirection();
	
	void SetThroughIntersection(bool);
	bool GetThroughIntersection();
	
	void IsThroughIntersection();
	
	
};

Car::Car(int id) {
	this->ID = id;
	int desiredDirection = rand() % 4;
	this->DesiredDirection = static_cast<Direction>(desiredDirection);
	
	this->ThroughIntersection = false;
	
	printf("Created car %i with random direction: ", this->ID);
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
	}
}

Car::~Car() {
	
}

int Car::GetID() {
	return this->ID;
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

void Car::IsThroughIntersection() {
	this->ThroughIntersection = true;
	
	printf("Car %i has ", this->ID);
	
	switch(this->DesiredDirection) {
		case STRAIGHT:
		printf("gone straight");
			break;
		case LEFT:
		printf("made a left turn");
			break;
		case RIGHT:
		printf("made a right turn");
			break;
		case UTURN:
		printf("made a u-turn");
			break;
	}
	
	printf(" through the intersection\n");
}
