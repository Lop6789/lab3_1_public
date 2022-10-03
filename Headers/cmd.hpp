#pragma once
#include "../Headers/ArrSeq.hpp"
#include "../Headers/SortHeaders.hpp"
void CheckSrc(int& argc, char** argv);
ArraySequence<ISort<int>*>* Parse(int& argc, char* argv[], int& start, int& stop, int& step);