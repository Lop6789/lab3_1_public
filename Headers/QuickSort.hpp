#pragma once
#include "ISort.hpp"

template <class T>
class QuickSort : public ISort<T> {
    private:
        void Qs(Sequence<T>* seq, int l, int r, int (*cmp)(T,T)){
            int size = r-l+1;
            if (size-1 <= 0) return;
            /*if (size == 2) {
                if (cmp(seq->Get(l), seq->Get(r)) > 0){
                    seq->Swap(l , r);
                    return;
                }
            }
            */
            T piv = seq->Get((l+r)/2);

            do{
                while (cmp(seq->Get(l), piv) < 0) l++;
                while (cmp( seq->Get(r), piv) > 0) r--;

                if (l <= r) {
                    seq->Swap(l, r);
                    l++;
                    r--;
                }
            } while (l <= r);
            if (r>0) Qs(seq, 0, r, cmp);
            if (l<size) Qs(seq, l, r, cmp);
        }


    public: 
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T,T)){
            int l = 0, r = seq->GetLength() - 1; 
            Qs(seq, l, r, cmp);
        return seq;
        }
}; 