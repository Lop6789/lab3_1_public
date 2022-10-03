#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


void CheckSrc(){
    string sorts_path = "Data/sorts_list";
    ifstream fin(sorts_path);
    if(fin.is_open()) cout << "Success!" << endl;
    fin.close();
}

void Cmd (int& argc, char** atgv){

}
