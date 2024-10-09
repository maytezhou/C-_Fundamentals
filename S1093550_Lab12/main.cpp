/*  Array class Template */
#include <iostream>
#include "Array.h"
using namespace std;

int main()
{
    Array <int> integers1(5);
    Array <int> integers2;

     cout << "\nEnter 15 integers:"<<endl;
    cin >> integers1 >> integers2 ;

    cout << "\nAfter input, the Arrays contain:\n"
    <<"integers1:\n"<<integers1
    <<"\nintegers2:\n"<<integers2;

    cout << "\nEvaluating: integers1 != integers2" << endl;
    if (integers1 != integers2){
        cout << "integers1 and integers2 are not equal"<< endl;
    }

    Array <double> double1(10);
    cout << "\nEnter 10 double precision numbers" << endl;
    cin >> double1 ;



     cout << "\nCreate double2 initialized with double1:" << endl ;
     Array<double> double2(double1);

     cout << "double1:\n" << double1
     << "\ndouble2:\n" << double2;



     cout << "\nEvaluating: double1 == double2" << endl;
     if (double1 == double2){
            cout << "double1 and double2 are equal" << endl ;

     }

     cout << "\n\nAssigning 100.01 to double1[5]" << endl ;
     double1[5] = 100.01;
     cout << "double1:\n" << double1 << endl;

     double1.swap(11,0);
     double1.swap(-1,9);

     cout << "double1[2]: " << double1[2] << " double1[8]: " << double1[8] << endl;
      double1.swap(2,8);
      cout << "After swapping: double1[2]: " << double1[2] << " double1[8]: " << double1[8] << endl;

      Array <string>strA(4);
     cout <<"\nEnter 4 strings:" <<endl;
     cin>> strA;
     cout << "strA[1]: " << strA[1] << " strA[3]: " << strA[3] << endl;
     strA.swap(1,3);
      cout << "After swapping: strA[1]: " << strA[1] << " strA[3]: " << strA[3] << endl;
     cout << "\nAttempt to assign  \"abcd\" to strA[5]" << endl;
     strA[5] = "abcd";
     return 0 ;

}
