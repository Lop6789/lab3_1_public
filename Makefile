CC = g++
PREF_HEAD = ./Headers/
PREF_SRC = ./Src/

SOURCE = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, %.o, $(SOURCE))

all:
	$(CC) -Wall -g -c $(SOURCE)
	$(CC) -Wall -g -o lab1 $(OBJ)
	rm *.o
