#include "ISort.hpp"
//#include <iostream>

template <class T>
class BubbleSort{
    private:
    void Swap(){

    }


    public:

        Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T,T)){
            for(int i = 0; i<seq->GetLength; i++){
                for (int j = 0; j<seq->GetLength; j++){
                    if (cmp>0) Swap (seq[i], seq[j]);
                }
            }
            return seq;
        }
};
