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
    ISort<int>* Sort1 = new BubbleSort<int>();
    ISort<int>* Sort2 = new QuickSort<int>();
    ISort<int>* Sort3 = new ShellSort<int>();
    ArraySequence<ISort<int>*>* sorts = new ArraySequence<ISort<int>*>();
    sorts->Append(Sort1);
    sorts->Append(Sort2);
    sorts->Append(Sort3);

int start = 10000, stop = 10003, step = 1;

for (int j = start; j<stop; j+=step){
    for (int i = 0; i<3 ; i++){
      for (int k = 0; k<j; k++) seq->Append(rand()%j);
      clock_t start = clock();
      Sequence<int>* res = sorts->Get(i)->Sort(Seq, cmp);
      clock_t end = clock();
      double time = double(end- start)/CLOCKS_PER_SEC;
      cout << time << endl;
      delete res;
      res = nullptr;
      cout << time << endl;
    }
    
}
    

    // Res->print();
    
    // delete Res;
    delete Seq;
    delete Sort1;
    delete Sort2;
    delete Sort3;
    delete sorts;
    delete[] randarr;
    return 0;
}