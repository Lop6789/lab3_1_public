#pragma once
#include "ISort.hpp"

template <class T>
class QuickSort : public ISort<T> {
    private:
        void Qs(Sequence<T>* seq, int l, int r, int (*cmp)(T,T)){
            if (r-l<=0) return;

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
            Sequence<T>* seq = origseq->GetSubsequence(0, origseq->GetLength());
            Qs(seq, 0, seq->GetLength()-1, cmp);
            return seq;
        }
}; 

// void Qs(Sequence<T>* seq, int i, int j, int (*cmp)(T,T)){
//             int l = i, r = j;
//             int size = r-l+1;
//             if (size-1 <= 0) return;
//             /*if (size == 2) {
//                 if (cmp(seq->Get(l), seq->Get(r)) > 0){
//                     seq->Swap(l , r);
//                     return;
//                 }
//             }
//             */
//             T piv = seq->Get((l+r)/2);

//             do{
//                 while (cmp(seq->Get(l), piv) < 0) l++;
//                 while (cmp( seq->Get(r), piv) > 0) r--;

//                 if (l <= r) {
//                     seq->Swap(l++, r--);
//                     //l++;
//                     //r--;
//                 }
//             } while (l <= r);
//             if (r>0) Qs(seq, i, l-1, cmp);
//             if (l<size) Qs(seq, r, j-1, cmp);
//             // Qs(seq, 0, r, cmp);
//             // Qs(seq, l, r, cmp);
//         }