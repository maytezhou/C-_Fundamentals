/* Array Exception Handling */
#include <iostream>
#include "Array.h"
#include <new>

using namespace std;

int main()
{
    Array integers1(5);
    Array integers2;

    cout << "\nEnter 15 integers:"<<endl;
    cin >> integers1 >> integers2 ;


    cout << "\nAfter input, the Arrays contain:\n"
    <<"integers1:\n"<<integers1
    <<"\nintegers2:\n"<<integers2;

    cout << "\nEvaluating: integers1 != integers2" << endl;
    if (integers1 != integers2){
        cout << "integers1 and integers2 are not equal"<< endl;
    }

     const Array integers3(integers1);

     cout << "\nAssigning integers2 to integers1:" << endl ;

     integers1 = integers2;

     cout << "integers1:\n" << integers1 << "\nintegers2:\n" << integers2 ;

     cout << "\nExecute integers2 = integers2:" << endl;
     integers2 = integers2;
     cout << "\nintegers1[2] is " << integers1[2]  << endl ;
     try {

            cout << "\nintegers3[25] is " << integers3[25]  << endl ;
     }
     catch (exception & ){
                cout << "Array reading is  not done. " << endl ;
     }

     cout << "\n\nAssigning 1000 to integers1[8]" << endl ;
     integers1[8] = 1000;
     cout << "integers1:\n" << integers1;


     cout << "\nAttempt to assign 1000 to integers1[23]" << endl;

     try{
     integers1[23] = 1000;
     }
      catch (exception & ){
                cout << "Array writting is  not done.\n" << endl ;
     }

     double* ptr[50];
     try {
                cout << "Memory allocation for creating large arrays.\n";

        for ( int i = 0 ; i < 50000000; i ++){ // In my laptop  I had to used this value 50000000 to make the system produce an exception of type bad memory allocation
            ptr[i] = new double [50000000];
            cout << "ptr[" << i <<  "] points to  50 000 000  new integers\n";
        }
     }

     catch (bad_alloc &memoryAllocationException){
         cerr << "Memory allocation exception occurs: " << memoryAllocationException.what() << endl ;

     }


}

