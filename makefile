CC = clang++
CFLAGS = -g -Wall -DDEBUG

all: main.exe
	./main.exe

main.exe: main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.exe

clean:
	rm *.exe
