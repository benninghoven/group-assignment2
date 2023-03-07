#include <iostream>
using namespace std;

/* This is the pipe that will transfer time information back to
 * the main process
 * The second, time_pipe.c, version will use a pipe. The child will 
 * write the starting time to the pipe, and the parent will read from 
 * it following the termination of the child process. You will use 
 * the gettimeofday() function to record the current timestamp. 
 * This function is passed a pointer to a struct timeval object, 
 * which contains two members: tv_sec and tv_usec. These represent 
 * the number of elapsed seconds and microseconds since January 1, 1970
 * (known as the UNIX EPOCH).
 *
 */



int main() {
    cout << "I'm a pipe!\n";
    return 0;
}

