#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include "../Headers/ArrSeq.hpp"
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
            // cout << "YES" << endl;
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
    
    return isorts;

}

// double Measure (ISort<int>* sorter, int qty, int flag){
 
//     if (flag == 0) Sequence<int>* seq1 = new ArraySequence<int>();
//     // else Sequence<int>* seq = new ListSequence<int>(randarr, qty);
//     srand(time(NULL));
//     for (int i = 0;, i<qty; i++){
//         seq->Append(rand()%qty)
//     }
//     clock_t start = clock();
//     Sequence<int>* out2 = sorter->Sort(ptr2, cmp);
//     clock_t end = clock();
//     double time = ((double)(end - start))/CLOCKS_PER_SEC;
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
            // auto from = std::chrono::high_resolution_clock::now();
            Sequence<int>* res = sorts->Get(i)->Sort(seq, cmp);
            // auto to = std::chrono::high_resolution_clock::now();
            // double time = std::chrono::duration_cast<std::chrono::microseconds>(to - from).count();
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
    delete sorts;

    system("cd Src && python3 draw.py");


}


