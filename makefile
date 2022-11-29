CC = clang++
CFLAGS = -g -Wall -DDEBUG

all: main
	./main

main: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main

clean:
	rm ./main
