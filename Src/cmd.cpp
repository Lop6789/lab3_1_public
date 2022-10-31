#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include "../Headers/Sequence/ArrSeq.hpp"
#include "../Headers/Sequence/LinkedListSeq.hpp"
#include "../Headers/SortHeaders.hpp"

using namespace std;

ArraySequence<ISort<int>*>* Parse(int& argc, char* argv[], int& start, int& stop, int& step, int& type){
    string sorts_path = "Data/sorts_list";
    string line;

    ifstream fin(sorts_path);

    ArraySequence<string>* sorts = new ArraySequence<string>();
   
    ArraySequence<ISort<int>*>* isorts = new ArraySequence<ISort<int>*>();

    if(fin.is_open()) cout << "Success!" << endl;
    while (getline(fin, line)){
        sorts->Append(line);
    }
    fin.close();

    start = 0, stop = 0, step = 0;

    for (int i = 0; i < argc; i++){
        int flag = 0;

        if (!(strcmp(argv[i], "-arr"))) {
            type = 0;
        }

        if ((!strcmp(argv[i], "-list"))) {
            type = 1;
        }

        if (!strcmp(argv[i], "-q")) {
            flag = 1;
            i++;
        }
        if ((sorts->IndexOf(argv[i]))!=-1){

            if (!strcmp(argv[i], "bs")) {
                isorts->Append(new BubbleSort<int>());
            }
            if (!strcmp(argv[i], "qs")) {
                isorts->Append(new QuickSort<int>());
            }
            if (!strcmp(argv[i], "shs")) {
                isorts->Append(new ShellSort<int>());
            }
        }

        if (flag == 1) {
            start = atoi(argv[i++]);
            stop = atoi(argv[i++]);
            step = atoi (argv[i]);

        }
    }
    delete sorts;
    return isorts;

}

Sequence<int>* RandSequence(int qty, int type){
    int* randarr = new int[qty];
        for (int i=0; i<qty; i++){
            randarr[i] = rand()%qty;
    }

    Sequence<int>* res;
    if (type == 0 ) {
        res = new ArraySequence<int>(randarr, qty);
    }
    else if (type == 1) {
        res = new LinkedListSequence<int>(randarr, qty);
    }
    else{
        res = nullptr;
    }

    delete[] randarr;
    
    return res;

}



// Time
void Cmd (ArraySequence<ISort<int>*>* sorts, int start, int stop, int step, int type, int (*cmp)(int, int)){

    clock_t from, to;
    double restime;
    ofstream out("result.csv");

    srand(time(NULL));

    out << "qty ";

    for (int l = 0; l<sorts->GetLength(); l++){
            out << sorts->Get(l)->GetName() << " ";
    }

    out << endl;


    for (int j = start; j<=stop; j+=step){
        out << j << " ";
        Sequence<int>* seq = RandSequence(j, type);
        for (int i = 0; i<sorts->GetLength(); i++){

            from = clock();
            Sequence<int>* res = sorts->Get(i)->Sort(seq, cmp);
            to = clock();

            restime = ((double)(to - from)) / CLOCKS_PER_SEC;
            out << restime << " ";
            delete res;
        }
        delete seq;
        out << endl;
    }
    out.close();
    system("cd Src && python3 draw.py");

}
