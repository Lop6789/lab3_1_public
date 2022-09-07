#pragma once
#include "Sequence.hpp"
#include "DynamicArray.hpp"

template <class T>
class ArraySequence : public Sequence<T>{
private:
    DynamicArray<T>* data;
public:
    ArraySequence(){
        data = new DynamicArray<T>(0);
    }

    ArraySequence(int n) {
        data = new DynamicArray<T>(n);
    }
    ArraySequence(T* items, int count){
        data = new DynamicArray<T>(0);
        data->Resize(count);
        for (int i = 0; i < count; i++){
            data->Set(i, items[i]);
        }
    }

    ~ArraySequence() {
        delete[] data;
    }

    ArraySequence(ArraySequence<T>& list){
        data = new DynamicArray<T>(0);
        data->Resize(list.GetLength());
        for (int i = 0; i < (list.GetLength()); i++){
            data->Set(i, list.Get(i));
        }
    }

    T GetFirst() override{
        return this->Get(0);
    }

    T GetLast() override{
        return this->Get(data->GetSize()-1);
    }

    T Get(int index) override{
        return data->Get(index);
    }

    T operator[](int const index) override{
        return data->operator[](index);
    }

    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override{
        ArraySequence<T>* buff = new ArraySequence<T>;
        int diff = endIndex - startIndex;
        buff->Resize(diff);
        for (int i = 0; i < diff; i++) {
            buff->Set(i, this->Get(startIndex+i));
        }
        return buff;
    }

    void Sum(ArraySequence<T>* arr) {
        for (int i = 0; i < (data->GetSize()); i++) {
            this->Set(i, (this->Get(i)) + (arr->Get(i)));
        }
    }

    

    int GetLength() override{
        return data->GetSize();
    }

    void Set(int index, T value) override{
        data->Set(index, value);
    }

    void Append(T item) override{
        data->Resize(data->GetSize()+1);
        data->Set(data->GetSize()-1, item);
    }

    void Prepend(T item) override{
        data->ResizeRight(data->GetSize()+1);
        data->Set(0, item);
    }

    void InsertAt(T item, int index) override{
        int newLength = this->GetLength()+1;
        this->Resize(newLength);
        T buff;
        int diff = newLength - index - 1;
        for (int i = 0; i < diff; i++) {
            buff = this->Get(newLength - i - 2);
            this->Set(newLength - i - 1, buff);
        }
        this->Set(index, item);
    }

    Sequence <T>* Concat(Sequence<T>* list) override {
        int oldLength = this->GetLength();
        for (int i = 0; i < ((ArraySequence <T>*)list)->GetLength(); i++) {
            this->Append(list->Get(i));
        }
        return (Sequence<T>*)this;
    }
 
    void Resize(int newSize){
        data->Resize(newSize);
    }

    void ResizeRight(int newSize)
    {
        data->ResizeRight(newSize);
    }

    void print() override{
        data->print();
    }

};