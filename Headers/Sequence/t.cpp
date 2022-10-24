#include <iostream>
#include "ArrSeq.hpp"
#include "../SortHeaders.hpp"
#include "LinkedList.hpp"

using namespace std;

int cmp (int a, int b){
    return a - b;
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    srand(time(NULL));

    int qty = 10;
    int* randarr = new int[qty];
    for (int i=0; i<qty; i++){
        randarr[i] = rand()%qty;
    }
    Sequence<int>* ptr = new ArraySequence<int>(randarr, qty);
    // DynamicArray<int>* ptr = new DynamicArray<int>(randarr, qty);
    // Sequence<int>* ptr1 = new ArraySequence(*ptr);
    // Sequence<int>* ptr1 = ptr->GetSubsequence(0, 5);

    LinkedList<int>* ptr2 = new LinkedList<int>(randarr, qty);
    // ptr2->print();
    LinkedList<int>* ptr3 = new LinkedList<int>(*ptr2);
    ptr3->Append(0);
    ptr3->Append(5);
    LinkedList<int>* ptr4 = ptr3->GetSubList(0, 3);
    // LinkedList<int>* ptr4 = new LinkedList<int>();
    // ptr4->Append(7);

    // ptr4->print();
    // cout << ptr2->GetLast() << ptr2->GetFirst() << endl;
    // LinkedList<int>* ptr2 = new LinkedList<int>();
    // ptr = ptr->GetSubsequence(0, 3);
    // ISort<int>* bs= new BubbleSort<int> ();
    // ISort<int>* shs= new ShellSort<int> ();
    // ISort<int>* qs= new QuickSort<int>();
    // Sequence<int>* ptr1 = qs->Sort(ptr, cmp);

    // ptr->print();

    delete[] randarr;
    delete ptr;
    // delete bs; 
    // delete shs;
    // delete qs;
    delete ptr2;
    // delete ptr1;
    delete ptr3;
    delete ptr4;
}