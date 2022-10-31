#pragma once
#include "ISort.hpp"

template <class T>
class QuickSort : public ISort<T> {
    private:
        string name = "qs";

        void Qs(Sequence<T>* seq, int l, int r, int (*cmp)(T,T)){
            int i = l, j = r;
            T piv = seq->Get((l+r)/2); 

            while (i<=j){
                while ((cmp(seq->Get(i), piv)) < 0) i++;
                while ((cmp(seq->Get(j), piv)) > 0) j--;
                if (i<=j){
                    seq->Swap(i++, j--);
                }
            }
            if (i < r) Qs(seq, i, r, cmp);
            if (l < j) Qs(seq, l, j, cmp);
        }


    public:
        Sequence<T>* Sort(Sequence<T>* origseq, int (*cmp)(T,T)){
            if (!origseq) return nullptr;
            Sequence<T>* seq = origseq->Copy();
            Qs(seq, 0, seq->GetLength()-1, cmp);
            return seq;
        }

        string GetName(){
            return name;
        }
};