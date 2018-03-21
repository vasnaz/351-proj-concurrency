#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>
#include "intersection.h"

#define NUM_THREADS 4

intersection a;
int b[4][2] = { {1, 4}, {2, 1}, {3, 2}, {4, 3} };
void *PrintHello(void *threadid)
{
	long tid;
	tid = (long)threadid;
	for(int i = 0; i< 2; i++)
	{
		sleep(rand()%2);
		while(!a.access(b[tid][i], tid))
		{
			//cout << "Thread: " << tid << endl;
		}
	}
	for(int i = 0; i< 2; i++)
	{
		a.setFree(b[tid][i], tid);
	}
	cout << "-----"<< tid << " Thread: " << tid << ", has driven straight." << endl;
	pthread_exit(NULL);
}
int main()
{
	pthread_t threads[NUM_THREADS];
	int rc;
	int i;
	sem_init(&readA, 0, 1);
	
	for(i = 0; i < NUM_THREADS; i++)
	{
		cout << "main (): creating thread: "<< i << endl;
		rc = pthread_create(&threads[i], NULL, PrintHello, (void*) i);
		if(rc)
		{
			cout << "unable to create thread: "<< i << endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
	
	sem_destroy(&readA);
	
	return 0;
}
