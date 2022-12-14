#include <iostream>
#include <ctime>
#include <stdio.h>
#include "../Headers/cmd.hpp"
#include "../Headers/Sequence/ArrSeq.hpp"
#include "../Headers/SortHeaders.hpp"
#include "../Headers/tests.hpp"

using namespace std;

int cmp (int a, int b){
    return a - b;
}

int main(int argc, char* argv[]){
    
    int flag;
    if (argc<=1) flag = 0;
    else{
        int start = 0, stop = 0, step = 0, type = 0;
        ArraySequence<ISort<int>*>* ptr = Parse(argc, argv, start, stop, step, type);
        Cmd(ptr, start, stop, step, type, cmp);
        for (int i = 0; i<ptr->GetLength(); delete ptr->Get(i), i++);
        delete ptr;
        flag=1;
    }
    
    srand(time(NULL));
    //Print array:
    /*
    cout << argc << endl;
    
    for (int i = 0; i < argc; i++){
	    cout << argv[i] << endl;
    }
    */

    int arr[] = {1, 9, 8, 3, 4, 1, 40, 4};
    
    Sequence<int>* ptr = new ArraySequence<int>(arr, 8);
    ISort<int>* sorter = new ShellSort<int>(); 

    // Sequence<int>* ptr = new ArraySequence<int>(3);
    //ArraySequence<int>* ptr1 = (ArraySequence<int>*)ptr;
    // ISort<int>* sorter = new ShellSort<int>();
    // ISort<int>* sorter = new QuickSort<int>();
    //ArraySequence<int>* ptr = new ArraySequence<int>(0);
    //ptr->Append(1331);
    int res = 0;
    while (!flag){
        cout << "\nChoose action:\n1)Sort {1, 9, 8, 3, 4, 1, 40, 4}\n2)AutoTest\n3)Sort random array\n4)Sort random array, measure time\n0)Exit\n";
        cin >> res;
        switch (res){
            case 1:{
                // int test1 = ptr->GetFirst();
                // int test2 = ptr->GetLength();
                // cout <<"First: "<<test1 << endl  << "Second: "  << test2 << endl;
                ptr->print();
                cout << "After Sort: " << endl;
                Sequence<int>* output = sorter->Sort(ptr, &cmp);
                output->print();
                cout << endl;
                delete output;

                break;
            }   
            case 2:{
                cout << "\nEnter type: \n1) Array\n2) LinkedList" << endl;
                int type = 0;
                cin >> type;
                AutoTest(&cmp, type);
                break;
            }
            
            case 3:{
                cout << "Generating random array, enter qty" << endl;
                int qty = 0;
                cin >> qty;
                int* randarr = new int[qty];
                for (int i=0; i<qty; i++){
                    randarr[i] = rand()%1000000;
                }
                Sequence<int>* ptr1 = new ArraySequence<int>(randarr, qty);
                ptr1->print();
                Sequence<int>* out = sorter->Sort(ptr1, cmp);
                out->print();
                
                
                delete[] randarr;
                delete ptr1;
                delete out;
                break;
            }

            case 4: {
                cout << "\nEnter qty to generate rangom array and sort" << endl;
                int qty = 0;
                cin >> qty;
                int* randarr = new int[qty];
                for (int i=0; i<qty; i++){
                    randarr[i] = rand()%1000000;
                }
                Sequence<int>* ptr2 = new ArraySequence<int>(randarr, qty);
                clock_t start = clock();
                Sequence<int>* out2 = sorter->Sort(ptr2, cmp);
                clock_t end = clock();
                double time = ((double)(end - start))/CLOCKS_PER_SEC;
                //out2->print();
                cout << time << endl;
                printf("Time: %.10lf\n", time);
                delete[] randarr;
                delete ptr2; delete out2;
                break;
            }

            case 0: {
                flag = 1;
                break;
            }

            default:{
                break;
            }
        }
    }
    delete ptr;
    delete sorter; 
    return 0;
}
