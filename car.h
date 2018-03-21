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

typedef enum {
	NORTH
	EAST
	SOUTH
	WEST
} Origin;

class Car {
	private:
	int ID;
	bool ThroughIntersection;
	Direction DesiredDirection;
	Origin routeorigin;
	
	public:
	Car(int);
	~Car();
	
	int GetID();
	
	Direction GetDesiredDirection();
	Origin getOrigin();
	
	void SetThroughIntersection(bool);
	bool GetThroughIntersection();
	
	void IsThroughIntersection();
	
	
};

Car::Car(int id) {
	this->ID = id;
	int desiredDirection = rand() % 4;
	this->DesiredDirection = static_cast<Direction>(desiredDirection);
	
	this->ThroughIntersection = false;
	
	printf("Created car %i with random direction and origin: ", this->ID);
	switch(this->DesiredDirection) {
		case STRAIGHT:
		printf("STRAIGHT ");
			break;
		case LEFT:
		printf("LEFT ");
			break;
		case RIGHT:
		printf("RIGHT ");
			break;
		case UTURN:
		printf("UTURN ");
			break;
	}

	int rteorigin = rand() % 4;
	this->routeorigin = static_cast<Origin>(rteorigin);


	switch(this->routeorigin) {
		case NORTH:
		printf("NORTH\n");
			break;
		case EAST:
		printf("EAST\n");
			break;
		case SOUTH:
		printf("SOUTH\n");
			break;
		case WEST:
		printf("WEST\n");
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

Origin Car::getOrigin() {
	return this->routeorigin;
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
