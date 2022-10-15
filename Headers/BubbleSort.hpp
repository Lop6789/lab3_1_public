#pragma once
#include "ISort.hpp"
#include <cstring>
#include <iostream>

template <class T>
class BubbleSort : public ISort<T>{
    private:
        string name = "bs";

        void Bs(Sequence<T>* seq, int (*cmp)(T,T)){
            int size = seq->GetLength()-1;
            for(int i = 0; i<size; i++){
                for (int j = 0; j<size - i; j++){   
                    if (cmp(seq->Get(j), seq->Get(j+1))>0) seq->Swap(j,j+1);
                }
            }
        }


    public:

        Sequence<T>* Sort(Sequence<T>* origseq, int (*cmp)(T,T)) override {
            Sequence<T>* seq = origseq->Copy();
            Bs(seq, cmp);
            return seq;
        }

        string GetName(){
            return name;
        }
    
        

};