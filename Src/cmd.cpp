#include <iostream>
#include <fstream>
#include <cstring>
#include "../Headers/ArrSeq.hpp"
#include "../Headers/SortHeaders.hpp"


using namespace std;


ArraySequence<ISort<int>*>* CheckSrc(int& argc, char* argv[]){
    string sorts_path = "Data/sorts_list";
    string line;

    ifstream fin(sorts_path);

    ArraySequence<string>* sorts = new ArraySequence<string>();
    ISort<int>* sort1 = nullptr;
    ISort<int>* sort2 = nullptr;
    ISort<int>* sort3 = nullptr;
    ArraySequence<ISort<int>*>* isorts = new ArraySequence<ISort<int>*>();
    // ArraySequence<ISort>
    if(fin.is_open()) cout << "Success!" << endl;
    while (getline(fin, line)){
        sorts->Append(line);
    }
    fin.close();

    for (int i = 0; i < argc; i++){
        //cout << argv[i] << endl;
        if ((sorts->IndexOf(argv[i]))!=-1){
            // cout << argv[i] << endl;
            // cout << "YES" << endl;
            //Create()
            if (argv[i] == "-bs") {
                sort1 = new BubbleSort<int>();
                isorts->Append(sort1);
            }
            if (argv[i] == "-qs") {
                sort2 = new QuickSort<int>();
                isorts->Append(sort2);
            }
            if (argv[i] == "-shs") {
                sort3 = new ShellSort<int>();
                isorts->Append(sort3);
            }
        }

    }
    return isorts;

}


void Cmd (int& argc, char** argv, ArraySequence<ISort<int>*>* sorts){
    sorts = CheckSrc(argc, argv);
    for (int i = 0; i<sorts->GetLength(); i++){
        // tim
    }
}
