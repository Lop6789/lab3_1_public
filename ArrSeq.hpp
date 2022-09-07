#pragma once
#include "Sequence.hpp"
#include <cassert>
#include <iostream>

template <class T>
class ArraySequence : public Sequence{
    private:
        T* data;
        int length;
    
    public:
        ArraySequence(int size){
            data = new T[size];
        }

        ArraySequence(T* items, int size){
            data = new T[size];
            for (int i = 0; i < size; i++){
                data[i] = items[i];
            }
        }
        //copy
        ArraySequence(ArraySequence<T>& arrseq){
            data = new T[length];
            for (int i=0; i<length; i++){
                data[i] = arrseq[i];
            }
        }

        T operator[](int const index){
            //assert
            return data[index];
        }

        T GetFirst() override {
            //assert (length <=0);
            return data[0];
        }

        T GetLast() override {
            //assert
            return data[length];
        }

        T Get(int index) override {
            return data[index];
        }  
        
        void Set(int index, T value) override {
            data[index] = value;
        }

        int GetLength() override {
            return length;
        }
        
        void Swap(int i, int j) override {
            T tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
        

        void Resize(int newsize) override {
            T* newData = new T[newsize];
            int tmpsize = 0;
            tmpsize = (newsize > length)? length:newsize;

            for (int i = 0; i<tmpsize; i++){
                newData[i] = data[i];
            }

		    delete[] data;
            data = newData;
            length = newsize;
        }

        void Append(T item) override {
            Resize(length+1);
            Set(length+1, item);
        }

        void Prepend(T item) override {
            
        }

        void InsertAt (T item, int index) {
            int newLength = length+1;
            Resize(newLength);
            T buff;
            int diff = newLength - index - 1;

            for (int i = 0; i < diff; i++) {
                buff = Get(newLength - i - 2);
                Set(newLength - i - 1, buff);
            }
            Set(index, item);
        }

        void print() override {
		    if (length == 0) cout << "{}";
            cout << "length: " << length  << endl;
            cout <<"{ ";
            for (int i = 0; i < length; i++){
                cout << data[i] << " ";
            }
            cout<< "}"<<endl;
        }

        Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
        Sequence<T>* Concat(Sequence<T>* list) = 0;
};