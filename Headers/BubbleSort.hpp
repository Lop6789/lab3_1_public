#include "ISort.hpp"
//#include <iostream>

template <class T>
class BubbleSort : public ISort<T>{
    private:

        void Bs(Sequence<T>* seq, int (*cmp)(T,T)){
            for(int i = 0; i<seq->GetLength(); i++){
                for (int j = 0; j<seq->GetLength(); j++){   
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

        

};