#pragma once
#include "Sequence.hpp"
#include "LinkedList.hpp"
//Don't forget to add : public Seq<T>

template <class T>
class LinkedListSequence : public Sequence<T> {
    private:
        LinkedList<T>* list;

    public:
        LinkedListSequence(){
            list = new LinkedList<T>();
        }

        LinkedListSequence(T* items, int size){
            list = new LinkedList<T>(items, size);
        }

        LinkedListSequence(LinkedListSequence<T>& listseq){
            this->list = new LinkedList<T>(*(listseq.list));
        }

        LinkedListSequence(LinkedList<T>& list){
            this->list = new LinkedList<T>(list);
        }

        ~LinkedListSequence(){
            delete list;
        }

        T Get (int index) override{
            return list->Get(index);
        }

        T GetFirst() override{
            return list->GetFirst();
        }

        T GetLast() override{
            return list->GetLast();
        }

        Sequence<T>* GetSubsequence(int startIndex, int endIndex) override{
            return (Sequence<T>*) (new LinkedListSequence<T>(*(list->GetSubList(startIndex, endIndex))));
        }

        int GetLength() override{
            return list->GetLength();
        }

        int IndexOf(T item) override{
            return list->IndexOf(item);
        }

        void Append(T item) override {
            list->Append(item);
        }

        void Prepend (T item) override {
            list->Prepend(item);
        }

        void InsertAt(T item, int index) override{
            list->InsertAt(item, index);
        }

        void Set(int index, T item) override{
            list->Set(index, item);
        }

        void Swap(int i, int j) override{
            T tmp = list->Get(i);
            list->Set(i, Get(j));
            list->Set(j, tmp);
        }

        Sequence<T>* Copy() override{
            return (Sequence<T>*) (new LinkedListSequence<T>(*this));
        }

        void print() override{
            return list->print();
        }

        
};