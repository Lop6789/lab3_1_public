#include <iostream>
#include "../Headers/Sequence/ArrSeq.hpp"
#include "../Headers/Sequence/LinkedListSeq.hpp"
#include "../Headers/SortHeaders.hpp"

using namespace std;

int AutoTest(int(*cmp)(int, int), int type){
    int qty = 13;
    int* randarr = new int[qty];
        for (int i=0; i<qty; i++){
            randarr[i] = rand()%qty;
    }
    Sequence<int>* origseq = nullptr;
    if (type == 1) origseq = new ArraySequence<int>(randarr, qty);
    else origseq = new LinkedListSequence<int>(randarr, qty);
    ISort<int>* bs = new BubbleSort<int>();
    ISort<int>* qs = new QuickSort<int>();
    ISort<int>* shs = new ShellSort<int>();

    Sequence<int>* sortedseq1 = bs->Sort(origseq, cmp);
    Sequence<int>* sortedseq2 = shs->Sort(origseq, cmp);
    Sequence<int>* sortedseq3 = shs->Sort(origseq, cmp);

    cout << "Randomly created Sequence: " << endl;
    origseq->print();
    cout << "Sorted with BubbleSort: " << endl;
    sortedseq1->print();
    cout << "Sorted with QuickSort: " << endl;
    sortedseq2->print();
    cout << "Sorted with ShellSort: " << endl;
    sortedseq3->print();

    delete[] randarr;
    delete origseq;
    delete sortedseq1;
    delete sortedseq2;
    delete sortedseq3;
    delete bs;
    delete qs;
    delete shs;
    return 0;
}