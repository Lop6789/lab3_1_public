#include <iostream>
#include <fstream>
#include <cstring>
#include "../Headers/ArrSeq.hpp"
#include "../Headers/SortHeaders.hpp"


using namespace std;


void CheckSrc(int& argc, char* argv[]){
    string sorts_path = "Data/sorts_list";
    string line;
    ifstream fin(sorts_path);
    ArraySequence<string>* sorts = new ArraySequence<string>();
    ISort<int>* sort1 = nullptr;
    ISort<int>* sort2 = nullptr;
    ISort<int>* sort3 = nullptr;
    // ISort<int>** isorts = new ISort<int>()[argc];
    if(fin.is_open()) cout << "Success!" << endl;
    while (getline(fin, line)){
        sorts->Append(line);
    }
    fin.close();
    //sorts->print();
    for (int i = 0; i < argc; i++){
        //cout << argv[i] << endl;
        if ((sorts->IndexOf(argv[i]))!=-1){
            // cout << argv[i] << endl;
            // cout << "YES" << endl;
            //Create()
            // if (argv[i] == "-bs") sort1 = new BubbleSort<int>*
            // if (argv[i] == "-qs") sort1 = new QuickSort<int>*
            // if (argv[i] == "-shs") sort1 = new SHellSort<int>*
            // switch (argv[i]){
            //     case "-bs":
            //         {   
            //             sort1 = new BubbleSort<int>();
            //             break;
            //         }
            // }
        }
    }

}

void Cmd (int& argc, char** argv, ArraySequence<string>* sorts){
    for (int i = 0; i < argc; i++){
        if (!(sorts->IndexOf(argv[i]))){
            cout << "YES" << endl;
        }

    }
}
