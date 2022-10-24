#pragma once
#include <iostream>
#include "Sequence.hpp"
#include <cassert>

using namespace std;

template <class T>
class ListNode {
    public:
        T data;
        ListNode<T>* next;
        ListNode<T>* prev;

    ListNode(T data){this->data = data;}
};


//Don't forget to add : public Seq<T>
template <class T>
class LinkedList {
    private:
        ListNode<T>* head;
        ListNode<T>* tail;
        int length;

    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        LinkedList(T* items, int size){
            length = size;
            head = new ListNode<T>(items[0]);
            ListNode<T>* ptr = head;    
            for (int i = 1; i < size; i++){
                ptr->next = new ListNode<T>(items[i]);
                ptr = ptr->next;    
            }
            tail = ptr;
        }

        LinkedList(LinkedList<T>& list){
            length = list.length;
            head = new ListNode<T>(list.head->data);

            ListNode<T>* ptr_this = head;
            ListNode<T>* ptr_other = list.head;

            for (int i = 1; i < length; i++){
                ptr_this->next = new ListNode<T>(ptr_other->next->data);
                ptr_this = ptr_this->next;
                ptr_other = ptr_other->next;
            }
            tail = ptr_this;
        }
        


        T GetFirst(){
            return head->data;
        }

        T GetLast(){
            return tail->data;
        }

        T Get (int index){
            ListNode<T>* ptr = head;
            for (int i = 0; i < length; i++){
                ptr = ptr->next;
            }
            return ptr;
        }

        int GetLength(){
            return length;
        }




        void print() {
            cout << "Length: " << length << endl;
            cout << "[ ";
            ListNode<T>* buff = head;
            for (int i = 0; i < length; i++) {
                cout << buff->data << " ";
                buff = buff->next;
            }

        cout << "]" << endl;
    }
};
        