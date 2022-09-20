#pragma once
#include "ISort.hpp"

template <class T>
class ShellSort : public ISort<T> {
    private:

    public:
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T,T)){
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
            return seq;
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