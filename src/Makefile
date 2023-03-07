CC = g++
CFLAGS = -Wall -g

all: time_pipe time_shm

time_pipe: time_pipe.o
	$(CC) $(CFLAGS) -o time_pipe time_pipe.o

time_shm: time_shm.o
	$(CC) $(CFLAGS) -o time_shm time_shm.o

time_pipe.o: time_pipe.cc
	$(CC) $(CFLAGS) -c time_pipe.cc

time_shm.o: time_shm.cc
	$(CC) $(CFLAGS) -c time_shm.cc

clean:
	rm -f *.o time_shm time_pipe
