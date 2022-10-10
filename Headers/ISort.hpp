#pragma once
#include "Sequence.hpp"
#include <string>

using namespace std;

template <class T>
class ISort{
    

    public:
        virtual ~ISort(){}

        virtual Sequence<T>* Sort(Sequence<T>* seq, int (*cmp)(T,T)) = 0;
        virtual string GetName() = 0;
};