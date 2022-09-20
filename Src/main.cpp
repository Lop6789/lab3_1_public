#include <iostream>
#include "../Headers/ArrSeq.hpp"
#include "../Headers/BubbleSort.hpp"
#include "../Headers/ShellSort.hpp"
#include "../Headers/QuickSort.hpp"
using namespace std;

// int cmp (int a, int b){
//     if (a > b) return 1;
//     if (a == b) return 0;
//     else return -1;
// }

int cmp (int a, int b){
    return a - b;
}

int main(int argc, char* argv[]){
    //Print array:
    /* 
    cout << argc << endl;
    
    for (int i = 0; i < argc; i++){
	    cout << argv[i] << endl;
    }
    */

    int arr[8] = {1, 9, 8, 3, 4, 1, 34, 4};
    Sequence<int>* ptr = new ArraySequence<int>(arr, 8);
    //ISort<int>* sorter = new BubbleSort<int>();
    //ISort<int>* sorter = new ShellSort<int>();
    ISort<int>* sorter = new QuickSort<int>();
    //ArraySequence<int>* ptr = new ArraySequence<int>(0);
    //ptr->Append(1331);

    int res = 0, choose = 0;
    while (res != -1){
        cout << "Choose: ";
        cin >> choose;
        switch (choose){
            case 1:{
                int test1 = ptr->GetFirst();
                int test2 = ptr->GetLength();
                cout <<"First: "<<test1 << endl  << "Second: "  << test2 << endl;
                ptr->print();
                cout << "After Sort: " << endl;
                sorter->Sort(ptr, &cmp);
                ptr->print();
                cout << "Operator" << endl;
                break;
            }
            case 2:{
                ptr->print();
                ptr = ptr->GetSubsequence(0,ptr->GetLength());
                ptr->print();
                break;
            }

            case 0: {
                res =-1;
                break;
            }

            default:
                break;
        }
    }


    return 0;
}
