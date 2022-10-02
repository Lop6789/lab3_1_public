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


template <class T>
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
            for (int i = 0; i<size; i++){
                Append(items[i]);
            }
        }

        ListSequence(ListSequence& list){
            for (int i = 0; i<list.length; i++){
                Append(list.Get(i));
            }
        }

        ~ListSequence(){
            Item<T>* ptr = head, ptr_prev;
            while (ptr){
                ptr_prev = ptr;
                ptr = ptr->next;
                delete(ptr_prev);
            }
        }

        T Get (int index) override{
            Item<T>* ptr = head;
            for (int i = 0; i<index; i++){
                ptr = ptr->next;
            }
            return ptr->data;
        }    

        T GetFirst (int index) override{
            return head->data;
        } 

        T GetLast (int index) override{
            return tail->data;
        } 

        void Set(int index, T value) override{
            Item<T>* ptr = head;
            for(int i = 0, i<index, i++){
                ptr = ptr->next;
            }
            ptr->data = value;
        }

        int GetLength() override{
            return length;
        }

        void Append(T Item){
            Item<T>* buff = new Item<T>;
            buff->next = nullptr;
            buff->data = item;
            if (!head) {
                head = buff;
                head->prev = nullptr;
                tail = head;
            }else {
                tail->next = buff;
                buff->prev = tail;
                tail = buff;
            }
            length++;
        }

        void Prepend(T item) override{
            Item<T>* buff = new Item<T>;
            buff->next = nullptr;
            buff->data = item;
            if (!head){
                head = buff;
                head->prev = nullptr;
                tail = head;
            }else {
                head->prev = buff;
                buff->next = head;
                head = buff;
            }
            length++;
        }

        void InsertAt (T item, int index) override{
            Item<T>* ptr_prev = &(Get(index));

            if (!prevItem){
                Append(item)
            }else {
                Item<T>* ptr = new Item<T>;
                ptr->data = item;
                ptr->prev = ptr_prev;
                ptr->next = ptr_prev->next;
                ptr_prev->next->prev = ptr;
                ptr_prev->next = ptr;
                length++:
            }
        }

        void print() override{
            cout << "Length: " << length << endl;
            cout << "[ ";
            Item<T>* buff = head;
            for (int i = 0; i < length; i++) {
                cout << buff->data << " ";
                buff = buff->next;
            }
            cout << "]" << endl;
        } 

        Sequence<T>* GetSubsequence(int startIndex, int endIndex) {
        }


        void Swap(int i, int j) override{
            T tmp = Get(i);
            Set(i, Get(j));
            Set(j, tmp);
        }


};