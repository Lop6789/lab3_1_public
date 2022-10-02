#pragma once
#include "Sequence.hpp"
#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class Item {
    private:
        T data;
        Item<T>* next;
        Item<T>* prev;
};

class ListSequence : public Sequence <T>{
    private:
        Item<T>* head;
        Item<T>* tail;
        int length;

    public:
        ListSequence(){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        ListSequence(T* items, int size){

        }
        
        