#pragma once
#include "ISort.hpp"
#include <cstring>
//#include <iostream>

template <class T>
class BubbleSort : public ISort<T>{
    private:
        string name = "bs";

        void Bs(Sequence<T>* seq, int (*cmp)(T,T)){
            int size = seq->GetLength();
            for(int i = 0; i<size; i++){
                for (int j = 0; j<size; j++){   
                    if (cmp(seq->Get(i), seq->Get(j))<0) seq->Swap(i,j);
                }
            }
        }


    public:

        Sequence<T>* Sort(Sequence<T>* origseq, int (*cmp)(T,T)) override {
            Sequence<T>* seq = origseq->GetSubsequence(0, origseq->GetLength());
            Bs(seq, cmp);
            return seq;
        }

        string GetName(){
            return name;
        }
    
        

};