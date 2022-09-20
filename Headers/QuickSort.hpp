#pragma once
#include "ISort.hpp"

template <class T>
class QuickSort : public ISort<T> {

    public: 
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T,T)){
            size = seq->GetLength();
            if (size <=1) return;

            int l = 0, r = size -1, x = (l+r)/2
            T piv = seq->Get(x);

            do{
                while (cmp(seq->Get(l), piv) < 0) l++;
                while (cmp(seq->Get(r), piv) > 0) r++;

                if (l < r) {
                    seq->Swap(l, r);
                    l++;
                    r--;
                }
            } while (l <= r);
            if (r>0) QuickSort(seq->GetSubsequence(), cmp);
            
        }
};