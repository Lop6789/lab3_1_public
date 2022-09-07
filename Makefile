SOURCE = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

all:
	g++ -c $(SOURCE)
	g++ -o lab1 $(OBJ)
	rm *.o