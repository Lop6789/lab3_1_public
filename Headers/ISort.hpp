#pragma once
#include "Sequence.hpp"
template <class T>
class ISort{
    

    public:
        //virtual ~ISort(){}

        virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T,T)) = 0;
        virtual string GetName() = 0;
};