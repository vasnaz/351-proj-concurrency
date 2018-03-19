#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMCARS 400

static void intersection ( void *ptr );

static void eastTo (unsigned int turn, unsigned int *turnList);
static void westTo (unsigned int turn, unsigned int *turnList);
static void northTo (unsigned int turn, unsigned int *turnList);
static void southTo (unsigned int turn, unsigned int *turnList);

static void lock_quad1(sem_t *lock1);
static void lock_quad2(sem_t *lock1);
static void lock_quad3(sem_t *lock1);
static void lock_quad4(sem_t *lock1);

static void unlock_quad1(sem_t *lock1);
static void unlock_quad2(sem_t *lock1);
static void unlock_quad3(sem_t *lock1);
static void unlock_quad4(sem_t *lock1);

//Need functions to lock semaphores

sem_t lock1;
sem_t lock2;
sem_t lock3;
sem_t lock4;
/*
Car1 is thread1
thread invokes intersection
intersection assigns direction
direction executes only if has appriorate locks
*/


int main(int argc, char *argv[]) {
	pthread_t thread[NUMCARS];
	unsigned int carID[NUMCARS];

	//Initialize each semaphore; 0 means shared with threads of processes in contrast to shared with processes 
	sem_init(&lock1,0);
	sem_init(&lock2,0);
	sem_init(&lock3,0);
	sem_init(&lock4,0);

	//Initilize each thread as 1 car that each invokes intersection()
	for(int i=0; i<NUMCARS; i++){
		carID[i] = i;
		pthread_create(&thread[i], NULL, (void *) &intersection, (void*)&carID[i]);
	}

	//Runs all threads
	for(int i=0; i<NUMCARS; i++) {
		pthread_join(thread[i], NULL);
	}

	//Delete semaphores
	sem_destroy(&lock1);
	sem_destroy(&lock2);
	sem_destroy(&lock3);
	sem_destroy(&lock4);

	return 0;
}

//Intersection function
////Assign direction
////Assign list of quadrants for direction according to priority
static void * intersection(void* ptr) {
	unsigned int turnList[3];
	//assign original location (east=0,west=1,north=2,south=3)
	unsigned int originalLocation = random()%4;

	//assign direction (left=0,right=1,straight=2,u-turn=3)
	unsigned int turn = random()%4;

	//create list of necessary quadrants to make turn, with higher numbers having higher priority
	if ( originalLocation == 0 /*east*/) {
		eastTo(turn, *turnList);
	}
	else if ( originalLocation == 1 /*west*/) {
		westTo(turn, *turnList);
	}
	else if ( originalLocation == 2 /*north*/) {
		northTo(turn, *turnList);
	}
	else /*south*/ {
		southTo(turn, *turnList);
	}
	//Critical? - LOCK first necessary quadrant - "get" lock for for first necessary quadrant
	//Wait if not available
	//After you properly lock, shut down "critical"
	//open critical
	//lock next necessary quadrant
	//wait if necessary
	//shut down critical
	//if have all necessary locks, "cross intersection"
	//signal
}

//Declaration of each lock
//lock1
static void lock_quad1(sem_t *lock1) {
	
}
//lock2
//lock3
//lock4

//Declaration of locationTo
static void eastTo(unsigned int turn,unsigned int *turnList) {
	switch(turn) {
		case 0: /*left - will always only need 3*/
			turnList[0]=3;
			turnList[1]=2;
			turnList[2]=1;
			break;
		case 1: /*right - will always only need 1*/
			turnList[0]=1;
			turnList[1]=0;
			turnList[2]=0;
			break;
		case 2: /*straight - will always only need 2*/
			turnList[0]=2;
			turnList[1]=1;
			turnList[2]=0;
			break;
		case 3: /*u-turn - will always only need 2*/
			turnList[0]=4;
			turnList[1]=1;
			turnList[2]=0;
			break;
	}
}

static void westTo(unsigned int turn,unsigned int *turnList) {
	switch(turn) {
		case 0: /*left - will always only need 3*/
			turnList[0]=4;
			turnList[1]=3;
			turnList[2]=1;
			break;
		case 1: /*right - will always only need 1*/
			turnList[0]=3;
			turnList[1]=0;
			turnList[2]=0;
			break;
		case 2: /*straight - will always only need 2*/
			turnList[0]=2;
			turnList[1]=1;
			turnList[2]=0;
			break;
		case 3: /*u-turn - will always only need 2*/
			turnList[0]=3;
			turnList[1]=2;
			turnList[2]=0;
			break;
	}
}
static void northTo(unsigned int turn,unsigned int *turnList) {
	switch(turn) {
		case 0: /*left - will always only need 3*/
			turnList[0]=4;
			turnList[1]=3;
			turnList[2]=2;
			break;
		case 1: /*right - will always only need 1*/
			turnList[0]=2;
			turnList[1]=0;
			turnList[2]=0;
			break;
		case 2: /*straight - will always only need 2*/
			turnList[0]=3;
			turnList[1]=2;
			turnList[2]=0;
			break;
		case 3: /*u-turn - will always only need 2*/
			turnList[0]=2;
			turnList[1]=1;
			turnList[2]=0;
			break;
	}
}

static void southTo(unsigned int turn,unsigned int *turnList) {
	switch(turn) {
		case 0: /*left - will always only need 3*/
			turnList[0]=4;
			turnList[1]=3;
			turnList[2]=1;
			break;
		case 1: /*right - will always only need 1*/
			turnList[0]=3;
			turnList[1]=0;
			turnList[2]=0;
			break;
		case 2: /*straight - will always only need 2*/
			turnList[0]=2;
			turnList[1]=1;
			turnList[2]=0;
			break;
		case 3: /*u-turn - will always only need 2*/
			turnList[0]=4;
			turnList[1]=1;
			turnList[2]=0;
			break;
	}
}