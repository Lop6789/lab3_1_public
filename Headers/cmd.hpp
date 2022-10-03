#pragma once
#include "../Headers/ArrSeq.hpp"
#include "../Headers/SortHeaders.hpp"
void CheckSrc(int& argc, char** argv);
void Cmd (int& argc, char** argv, ArraySequence<ISort<int>*>*);