#pragma once
#include "Sequence.hpp"
template <class T>
class ISort{
    

    public:
        virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T,T)) = 0;
};