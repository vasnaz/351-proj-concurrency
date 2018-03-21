//quadrant class
//Jonathan and Beau


#include <iostream>
#include <vector>
#include <semaphore.h>
using namespace std;
//sem_t lockQSem;
sem_t readA[4];
struct quadrant {

    //current state lock 
    // next state lock
    int num;
    bool full;
};


//template <typename E>

class intersection {
private:

    vector<quadrant> Q;

public:
    intersection()
    {
        //initiallize the semaphore. Might move this onto main if necessary.
        //make 4 quadrants that are numbered 1-4 and set their states to not full
        for(int i = 0; i < 4; i++)
        {
            quadrant p;
            p.num = i+1;
            p.full = false;
            Q.push_back(p);
        }
    }
//functions to lock areas of intersection
    void access(int quad)//, int tid)
    {
        //cout << "Thread " << tid << ": Waiting for quad " << quad << endl;
        if(quad <= 0 || quad > 4){return;}
        cout<< "Waiting for quad: " << quad << endl;
        sem_wait(&readA[quad-1]);
        
        /*if(!Q[quad-1].full)
        {
            Q[quad-1].full = true;
            cout << tid << ": Quadrant " << Q[quad-1].num << " available and snatched.\n";
            sem_post(&readA);
            return true;
        }
        else
        {
            //cout << tid << ": Quadrant " << Q[quad-1].num << " unavailable.\n";
            sem_post(&readA);
            return false;
        }
        */
        //cout << "Thread "<< tid << ": Now have quad " << quad << endl;
        cout << "Reserved quad: " << quad << endl;        
        
    }
    void setFree(int quad)//, int tid)
    {
        if(quad <= 0 || quad > 4){return;}
        //cout << "!Thread" << tid << ": set free: " << quad << endl;
        cout << "Set Free quad: " << quad << endl;        
        sem_post(&readA[quad-1]);
        /*Q[quad-1].full = false;
        cout << tid << ": Quadrant " << Q[quad-1].num << " is free.\n";
        */
    }





};
