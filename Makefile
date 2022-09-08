CC = g++
SOURCE = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

all:
	#$(CC) -c $(SOURCE)
	#$(CC) -o lab1 $(OBJ)
	#rm *.o

	$(CC) -o lab1 $(SOURCE)
