#include "Headers/SortHeaders.hpp"
#include "Headers/ArrSeq.hpp"
#include "Headers/Sequence.hpp"
#include "Headers/ISort.hpp"
#include <iostream>
#include <time.h>
#include <cstring>

using namespace std;

int cmp(int vol1, int vol2)
{
  if (vol2 > vol1) return true;
  else return false;
}

int main()
{
    srand(time(NULL));
    int qty = 10000;
    int* randarr = new int[qty];
    for (int i=0; i<qty; i++){
        randarr[i] = rand()%qty;
    }
    Sequence<int>* Seq = new ArraySequence<int>(randarr, qty);
    // for (int i = 0; i < 100; Seq->Append(rand() % 25), i++);
    ISort<int>* Sort = new BubbleSort<int>();
    clock_t start = clock();
    Sequence<int>* Res = Sort->Sort(Seq, cmp);
    clock_t end = clock();
    double time = double(end- start)/CLOCKS_PER_SEC;

    // Res->print();
    cout << time << endl;
    delete Res;
    delete Seq;
    delete Sort;
    delete[] randarr;
    return 0;
}