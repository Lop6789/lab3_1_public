#pragma once
#include "Sequence.hpp"
#include "DynamicArr.hpp"
#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class ArraySequence : public Sequence <T>{
    private:
        DynamicArray<T>* arr;
    
    public:

        ArraySequence(){
            arr = new DynamicArray<T>();
        };

        ArraySequence(int size){
            arr = new DynamicArray<T>(size);
        }

        ArraySequence(T* items, int size){
            arr = new DynamicArray<T>(items, size);
        }

        ArraySequence(DynamicArray<T>& arr){
            this->arr = new DynamicArray<T>(arr);
        }

        //copy
        ArraySequence(ArraySequence<T>& arrseq){
            arr = new DynamicArray<T>(*(arrseq.arr));
        }

        ~ArraySequence(){
            delete arr;
        }


        T operator[](int const index){
            //assert
            return arr->Get(index);
        }

        T GetFirst() override {
            //assert (length <=0);
            return arr->GetFirst();
        }

        T GetLast() override {
            //assert
            return arr->GetLast();
        }

        T Get(int index) override {
            return arr->Get(index);
        }  
        
        void Set(int index, T value) override {
            arr->Set(index, value);
        }

        int GetLength() override {
            return arr->GetLength();
        }
        
        void Swap(int i, int j) override {
            arr->Swap(i, j);
        }
        

        void Resize(int newsize) {
            arr->Resize(newsize);    
        }

        void Append(T item) override {
            arr->Append(item);
        }

        void Prepend(T item) override {
            arr->Prepend(item);
        }

        void InsertAt (T item, int index) {
            arr->InsertAt(item, index);
        }

        void print() override {
		    arr->print();
        }

        Sequence<T>* GetSubsequence(int startIndex, int endIndex) override{
            ArraySequence<T>* buff = new ArraySequence<T>();
            int diff = endIndex - startIndex;
            buff->Resize(diff);
            for (int i = 0; i < diff; i++) {
                buff->Set(i, Get(startIndex+i));
            }
            return (Sequence<T>*)buff;
        }

        Sequence<T>* Copy() override{
            return (Sequence<T>*)(new ArraySequence<T>(*this));
            }

        int IndexOf(T item){
            return arr->IndexOf(item);
        }
        //Sequence<T>* Concat(Sequence<T>* list) = 0;//
        
};