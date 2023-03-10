#include <iostream>
#include <sys/time.h>

#include <unistd.h>
#include <string.h>

using namespace std;

/* This is the pipe that will transfer time information back to
 * the main process
 * it following the termination of the child process. You will use 
 * the gettimeofday() function to record the current timestamp. 
 * This function is passed a pointer to a struct timeval object, 
 * which contains two members: tv_sec and tv_usec. These represent 
 * the number of elapsed seconds and microseconds since January 1, 1970
 * (known as the UNIX EPOCH).
 */
//FIXME
//printf("\nElapsed time: %d/%06d seconds\n", elapsed_time.tv_seeconds,
//elapsed_time.tv_usec);
double GetElapsedTime(timeval &first, timeval &second){ // DJB
    double timeElapsed = 0.0;
    if (first.tv_sec > second.tv_sec) return -1; // error
    timeElapsed = second.tv_sec - first.tv_sec;
    // convert seconds given to microseconds
    timeElapsed += (second.tv_usec - first.tv_usec) / 1'000'000.0;
    return timeElapsed;
}

int main(int argc, char* argv[]) {
    int fd[2]; // Create an array for file descriptors
    pid_t pid; // Create a process ID variable
    char message[] = "Hello, parent!"; // Create a message to send

    if (pipe(fd) == -1) { // Create a pipe and check for errors
        std::cerr << "Failed to create pipe" << std::endl;
        return 1;
    }

    pid = fork(); // Create a child process
    if (pid < 0) { // Check for errors in creating child process
        std::cerr << "Failed to fork process" << std::endl;
        return 1;
    }

    if (pid == 0) { // Child process
        close(fd[0]); // Close read end of pipe
        struct timeval firstTv, secondTv; 
        gettimeofday(&firstTv, NULL);
        if (argc > 1){
            string command = "";
            for (int i = 1; i < argc; i++) {
                command += argv[i];
                command += " ";
            }
            command.pop_back(); // trim final whitespace
            system(command.c_str()); // convert string to c_str
        }
        else cout << "NO ARG PASSED\n";
        gettimeofday(&secondTv, NULL);
        double timeElapsed = GetElapsedTime(firstTv,secondTv);
        sprintf(message, "%f", timeElapsed);
        write(fd[1], message, strlen(message) + 1); // Write message to pipe
        close(fd[1]); // Close write end of pipe
    } else { // Parent process
        close(fd[1]); // Close write end of pipe

        char buffer[100]; // Create a buffer to read into
        read(fd[0], buffer, sizeof(buffer)); // Read message from pipe
        std::cout << "Time elapsed: " << buffer << " seconds\n"; // Print message received
        close(fd[0]); // Close read end of pipe
    }
    return 0; // Return 0 to indicate successful execution
}

