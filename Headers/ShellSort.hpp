#pragma once
#include "ISort.hpp"

template <class T>
class ShellSort : public ISort<T> {
    private:

    public:
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T,T)){
            int gap, i, j, tmp;
            int n = seq->GetLength();
            for (gap = n/2 ; gap>0; gap/=2){
                for (i = gap; i<n; i++){
                    for (j = i - gap; j>=0 && seq->Get(j) > seq->Get(j+gap); j-=gap){
                        tmp = seq->Get(j);
                        seq->Set(seq->Get(j), seq->Get(j + gap));
                        seq->Set(seq->Get(j+gap), tmp);
                    }
                }
            }
            return seq;
        }

};