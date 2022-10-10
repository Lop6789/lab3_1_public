#include "Headers/SortHeaders.hpp"
#include "Headers/ArrSeq.hpp"
#include "Headers/Sequence.hpp"
#include "Headers/ISort.hpp"
#include <iostream>
#include <time.h>
#include <cstring>

using namespace std;

int cmp(int val1, int val2)
{
    return val1 - val2;
}

int main()
{
    srand(time(NULL));

    Sequence<int>* Seq = new ArraySequence<int>();
    for (int i = 0; i < 10000; Seq->Append(rand() % 25000), i++);
    ISort<int>* Sort = new BubbleSort<int>();
    clock_t start = clock();
    Sequence<int>* Res = Sort->Sort(Seq, cmp);
    clock_t end = clock();
    double time = double(end- start)/CLOCKS_PER_SEC;

    Res->print();
    cout << time << endl;
    delete Res;
    delete Seq;
    delete Sort;
    return 0;
}