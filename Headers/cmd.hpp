#pragma once
#include "../Headers/Sequence/ArrSeq.hpp"
#include "../Headers/SortHeaders.hpp"
void CheckSrc(int& argc, char** argv);
ArraySequence<ISort<int>*>* Parse(int& argc, char* argv[], int& start, int& stop, int& step, int& type);
void Cmd (ArraySequence<ISort<int>*>* sorts, int start, int stop, int step, int type, int (*cmp)(int, int));
Sequence<int>* RandSequence(int qty, int type);