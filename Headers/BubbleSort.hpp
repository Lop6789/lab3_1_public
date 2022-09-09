#include "ISort.hpp"
//#include <iostream>

template <class T>
class BubbleSort : public ISort<T>{
    private:


    public:
        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T,T)){
            for(int i = 0; i<seq->GetLength(); i++){
                for (int j = 0; j<seq->GetLength(); j++){
                    if (cmp(seq->Get(i), seq->Get(j))<0) seq->Swap(i,j);
                }
            }
            return seq;
        }
};
