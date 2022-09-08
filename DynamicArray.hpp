#pragma once

#include <cassert>
#include <iostream>
using namespace  std;

template <class T> 
class DynamicArray {
private:
	T* data;
	int length;

public:
	//Object constructors:
	//Copy elems from given array
	DynamicArray(T* items, int count) {
		data = new T[count];
        //this->length = count;
		length = count;
		for (int i = 0; i < length; i++) {
			data[i] = items[i];
		}

	} 

	//Create array with *size* length 
	DynamicArray(int size) {
		data = new T[size];
		length = size;
	}

    T operator[](int const index){
        return data[index];
    }

	//Copying constructor
	DynamicArray(DynamicArray <T>& dynamicArray) { 
		length = dynamicArray.length;
//        length = GetSize();
		//DynamicArray(length);
        data = new T[length];
		for (int i = 0; i < length; i++) {
			data[i] = dynamicArray.Get(i);
		}

	} 

	//Decomposion
	// Get elem by index
	//Can throw exceptions (IndexOutofRange if index<0, index>=amount of elems or point not on given elem)
	T Get(int index) {
		assert(index >= 0);
        assert (index < length);
		return data[index];
	}

	//Get size of array
	int GetSize() {
		return length;
	}

	//Operations
	//set an element by index
	void Set(int index, T value) {
		assert(index >= 0);
        assert (index < length);
		data[index] = value;

	} 

	void Swap(int i, int j) override {
		T tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	}

	void Resize(int newsize) {
		assert(newsize >= 0);
		T* newData = new T[newsize];
        int tmpsize = 0;
        tmpsize = (newsize > length)? length:newsize;

        for (int i = 0; i<tmpsize; i++){
            newData[i] = data[i];
        }
		delete data;
        data = newData;
        length = newsize;

	}

    void ResizeRight(int newsize)
    {
        assert(newsize > 0);
        T* newData = new T[newsize];
        int startIndex = (newsize > length)?(newsize - length):0;
        for (int i = startIndex; i < newsize; i++)
            newData[i] = data[i-(newsize - length)];
        delete data;
        data = newData;
        length = newsize;
    }


    void print(){
		if (length == 0) cout << "{}";
        cout << "length: " << length  << endl;
        cout <<"{ ";
        for (int i = 0; i < length; i++){
            cout << data[i] << " ";
        }
        cout<< "}"<<endl;
    }


};