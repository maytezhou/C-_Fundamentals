/* Operator Overloading HugeInteger */
#include <iostream>
#include "Hugeint.h"
#include<string>
using namespace std;

int main()
{
    HugeInt n1(7654321);
    HugeInt n3 ("99999999999999999999999999999");
    HugeInt n4 ("1");
    HugeInt n5 (n4);

    cout<<"n1 is " << n1 <<"\nn3 is " << n3
    << "\nn4 is " << n4<< "\nn5 is "<< n5 << "\n\n";
    HugeInt n6 = n3+ n4;
    cout << "n6 = " << n3 << " + " << n4 << " = " << n6 << "\n\n";
    cout << "9+ n1 = " << 9 + n1 << " " << "9"+ n1 << " " << n1 + 9 << endl;
    cout << "n4+100+900+n5= " << n4+100+"900"+n5 << endl;


   cout << "n3++=" << n3++<< endl;
    cout <<"n3 = " << n3 << endl;
  cout <<"++n3 = " << ++n3 << endl;
    cout <<"n3 = " << n3 << endl;
   if (n3>=n1)
        cout<<"\nyes-1"<< endl;
    else cout<< "\nno-1"<< endl;
    if(n3>=100)
        cout<<"yes-2"<<endl;
    else cout<<"no-2"<< endl;
    if(100>=n3)
        cout<<"yes-3"<<endl;
    else cout<<"no-3"<< endl;
    if(n3>="100")
        cout<<"yes-4"<<endl;
    else cout<<"no-4"<< endl;
     if("100">=n3)
        cout<<"yes-5"<<endl;
    else cout<<"no-5"<< endl;

    return 0;
}
