#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static void myfunc1 (void *ptr);

char buf[24];
int ticketNum = 20;
sem_t readSemaphore;

int main(int argc, char *argv[])
{
	pthread_t thread[4];
	char *msg1[4] = {"Thread 1", "Thread 2", "Thread 3", "Thread 4"};
	
	sem_init(&readSemaphore, 0, 1);
	for(int i = 0; i < 4; i++)
	{
		pthread_create (&thread[i], NULL, (void *) &myfunc1, (void*) msg1[i]);
		//pthread_join(thread[i], NULL);
	}
	for(int i = 0; i < 4; i++)
	{
		pthread_join(thread[i], NULL);
	}
	
	sem_destroy(&readSemaphore);

	return 0;
}

static void myfunc1 (void *ptr)
{
	bool done = false;
	int sleepR = 15000, sleepM = 5000, sleept;
	while(!done)
	{
	//sleept = sleepM + (rand() % sleepR);
	sleept = (rand() % 5);
	sleep(sleept);
	sem_wait(&readSemaphore);
	char *msg = (char*) ptr;
	printf("%s: ", msg);
	if(ticketNum == 0)
	{
		done = true;
		printf("Sold Out!\n");
	}
	else
	{
		ticketNum--;
		printf("%d\n", ticketNum+1);
	}
	
	
	sem_post(&readSemaphore);
	}
	pthread_exit(0);
}

