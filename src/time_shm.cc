#include <iostream>
using namespace std;


/* Start timer
 * Create a child process
 * Run the function that is passed in as an arg
 * After child is killed, report time taken 
 *
 * ./time <command [args,...]>
 *
 * fork()
 * execvp()
 * gettimeofday()
 * two different IPC Mechanisms
 *
 * 2a) The first version, time_shm.c, will have the child process 
 * write the starting time to a region of shared memory before it 
 * calls execvp(). After the child process terminates, the parent 
 * will read the starting time from shared memory. The region of 
 * shared memory should be established before the child process is 
 * forked, allowing both the parent and child processes access to 
 * the region of shared memory.
 */



int main() {
    cout << "What does shm mean 🤔 ?!!\n";
    return 0;
}

