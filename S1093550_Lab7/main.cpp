/* Operator Overloading*/
#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    Array integers1(7);
    Array integers2;
    cout << "Size of Array integers1 is " << integers1.getSize() <<"\nArray after inizialization:\n" << integers1 ;


    cout << "\nSize of Array integers 2 is "
    << integers2.getSize()
    <<"\nArray after inizialization:\n" << integers2;


    cout << "\nEnter 17 integers:"<<endl;
    cin >> integers1 >> integers2 ;


    cout << "\nAfter input, the Arrays contain:\n"
    <<"integers1:\n"<<integers1
    <<"\nintegers2:\n"<<integers2;

    cout << "\nEvaluating: integers1 != integers2" << endl;
    if (integers1 != integers2){
        cout << "integers1 and integers2 are not equal"<< endl;
    }

    Array integers3(integers1);

    cout << "\nSize of Array integers3 is "
     << integers3.getSize()
     << "\nArray after initialization\n" << integers3;
     cout << "\nAssigning integers2 to integers1:" << endl ;

     integers1 = integers2;

     cout << "integers1:\n" << integers1
     << "\nintegers2:\n" << integers2 ;



     cout << "\nEvaluating: integers1 == integers2" << endl;
     if (integers1 == integers2){
            cout << "integers1 and integers2 are equal" << endl ;

     }

     cout << "\nintegers1[5] is " << integers1[5] ;


     cout << "\n\nAssigning 1000 to integers1[5]" << endl ;
     integers1[5] = 1000;
     cout << "integers1\n" << integers1;


     //insert the new statements here
     integers3=-integers3;
     cout <<"\nintegers2 :\n" << integers2 <<endl;
     cout <<"integers3 :\n" << integers3 << endl;
     Array C ;
     C = integers1 + integers2 + integers3;
     cout << " Array C = integers1 + integers2 + integers3 \n" << C;
     int k = 30;
     C >> k ;
     cout << "\nShifting the elements of C to the right by" << k << "places:\n" << C;

     cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
     integers1[15] = 1000;

}
