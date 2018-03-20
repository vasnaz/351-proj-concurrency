#include <cstdio>
#include "car.h"

int main() {
	int Straight = 0;
	int Left = 0;
	int Right = 0;
	int UTurn = 0;
	
	//Create new car object
	//Car car;
	
	//Create 10 cars
	for(int i=0;i<100;i++) {
		Car car(i);
		
		switch(car.GetDesiredDirection()) {
			case STRAIGHT:
				Straight++;
				break;
			case LEFT:
				Left++;
				break;
			case RIGHT:
				Right++;
				break;
			case UTURN:
				UTurn++;
				break;
		}
		
		car.IsThroughIntersection();
	}
	
	printf("Straight: %i\n", Straight);
	printf("Left: %i\n", Left);
	printf("Right: %i\n", Right);
	printf("UTurn: %i\n", UTurn);
	
	
}