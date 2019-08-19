OBJS	= A.o main.o
SOURCE	= A.cpp main.cpp
HEADER	= A.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

A.o: A.cpp
	$(CC) $(FLAGS) A.cpp -std=c++14

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++14


clean:
	rm -f $(OBJS) $(OUT)

run: $(OUT)
	./$(OUT)
