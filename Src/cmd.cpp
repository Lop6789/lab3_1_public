#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include "../Headers/Sequence/ArrSeq.hpp"
#include "../Headers/SortHeaders.hpp"


using namespace std;


ArraySequence<ISort<int>*>* Parse(int& argc, char* argv[], int& start, int& stop, int& step){
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

        if (!strcmp(argv[i], "-q")) {
            flag = 1;
            i++;
        }
        if ((sorts->IndexOf(argv[i]))!=-1){
            // cout << argv[i] << endl;
            //Create()
            if (!strcmp(argv[i], "bs")) {
                // sort1 = new BubbleSort<int>();
                isorts->Append(new BubbleSort<int>());
            }
            if (!strcmp(argv[i], "qs")) {
                // sort2 = new QuickSort<int>();
                isorts->Append(new QuickSort<int>());
            }
            if (!strcmp(argv[i], "shs")) {
                // sort3 = new ShellSort<int>();
                isorts->Append(new ShellSort<int>());
            }
        }

        if (flag == 1) {
            start = atoi(argv[i++]);
            stop = atoi(argv[i++]);
            step = atoi (argv[i]);
            // flag = 2;
        }
            //FILENAME

    }
    delete sorts;
    return isorts;

}

// Sequence<T>* RandSequence(int qty){

// }



// Time
void Cmd (ArraySequence<ISort<int>*>* sorts, int start, int stop, int step, int type, int (*cmp)(int, int)){
    // Sequence<int>* seq = nullptr;
    // if (type == 1) seq = new ArraySequence<int>();
    // else seq = new ListSequence();

    clock_t from, to;
    double restime;
    ofstream out("result.csv");

    srand(time(NULL));

    out << "qty ";

    for (int l = 0; l<sorts->GetLength(); l++){
            out << sorts->Get(l)->GetName() << " ";
    }

    out << endl;


    for (int j = start; j<stop; j+=step){
        out << j << " ";
        for (int i = 0; i<sorts->GetLength(); i++){
            ArraySequence<int>* seq = new ArraySequence<int>();
            for (int k = 0; k<j; k++) seq->Append(rand()%j);

            from = clock();
            
            Sequence<int>* res = sorts->Get(i)->Sort(seq, cmp);

            to = clock();
            restime = ((double)(to - from)) / CLOCKS_PER_SEC;

            out << restime << " ";
            restime = 0;
            delete res;
            delete seq;
            // start = 0; end = 0;
        }
        out << endl;
    }
    out.close();
    //for (int i = 0; i<sorts->GetLength(); delete sorts->Get(i), i++);
    //delete sorts;

    system("cd Src && python3 draw.py");


}


            // auto from = std::chrono::high_resolution_clock::now();
            // auto to = std::chrono::high_resolution_clock::now();
            // double time = std::chrono::duration_cast<std::chrono::microseconds>(to - from).count();


