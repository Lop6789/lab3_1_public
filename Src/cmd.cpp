#include <iostream>
#include <fstream>
#include <cstring>
#include "../Headers/Sequence.hpp"
#include "../Headers/ArrSeq.hpp"

using namespace std;


void CheckSrc(int& argc, char* argv[]){
    string sorts_path = "Data/sorts_list";
    string line;
    ifstream fin(sorts_path);
    ArraySequence<string>* sorts = new ArraySequence<string>();
    if(fin.is_open()) cout << "Success!" << endl;
    while (getline(fin, line)){
        sorts->Append(line);
    }
    fin.close();
    //sorts->print();
    for (int i = 0; i < argc; i++){
        //cout << argv[i] << endl;
        if ((sorts->IndexOf(argv[i]))!=-1){
            cout << argv[i] << endl;
            cout << "YES" << endl;
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
