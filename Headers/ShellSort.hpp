#pragma once
#include "ISort.hpp"

template <class T>
class ShellSort : public ISort<T> {
    private:
        string name = "shs";

        void Ss(Sequence<T>* seq, int (*cmp)(T,T)){
            int gap, i, j, tmp;
            int n = seq->GetLength();
            for (gap = n/2 ; gap > 0; gap/=2){
                for (i = gap; i < n; i++){
                    for (j = i - gap; j>=0 && cmp(seq->Get(j), seq->Get(j+gap))>0; j-=gap){
                        tmp = seq->Get(j);
                        seq->Set(j, seq->Get(j + gap));
                        seq->Set(j+gap, tmp);
                    }
                }
            }
        }

    public:
        Sequence<T>* Sort(Sequence<T>* origseq, int (*cmp)(T,T)) override {
                Sequence<T>* seq = origseq->GetSubsequence(0, origseq->GetLength());
                Ss(seq, cmp);
                return seq;
            }

        string GetName(){
            return name;
        }


/*
void shellsort (int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
        }
    }
*/

};