#include <iostream>
#include "../Headers/ArrSeq.hpp"

using namespace std;

int main(int argc, char* argv[]){
    /*
    cout << argc << endl;
    
    for (int i = 0; i < argc; i++){
	    cout << argv[i] << endl;
    }
    */

    int arr[8] = {1, 9, 8, 3, 4, 1, 34, 4};
    Sequence<int>* ptr = new ArraySequence<int>(arr, 8);
    
    //ArraySequence<int>* ptr = new ArraySequence<int>(0);
    //ptr->Append(1331);

    int res = 0;
    while (res != -1){
        cout << "Choose: ";
        cin >> res;
        switch (res){
            case 1:{
                int test1 = ptr->GetFirst();
                int test2 = ptr->GetLength();
                cout <<"First: "<<test1 << endl  << "Second: "  << test2 << endl;
                ptr->print();
                break;
            }
            case 2:{
                break;
            }

        default:
            break;
        }
    }


    return 0;
}
