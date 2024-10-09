/*  Output 3 A deeper look into classes Employee Count*/
#include <iostream>
#include "Employee.h"
#include <string>

using namespace std;


int Employee::count =0;
int Employee::fCount =0;
int Employee::mCount =0;

int Employee::getCount(){
    return count ;
}

int main()
{
    cout << "Number of employees before instantiation of any objects is "
    << Employee::getCount() << endl ;

    {
        Employee e1 ("Susan","Baker",'M');
        Employee e2 ("Robert", "Jones",'F');
        Employee e3 ("Emily", "Willow", 'F');
        Employee e4 ("Jhon","Reid",'K');
        Employee e5 ("Maria", "Vinci",'M');
        Employee e6 ("Vincent", "Url", 'F');
        Employee e7 ("RB","Lin", 'M');
        print(e5);
        print (e6);

        cout << "Number of employees after objects are instantiated is "
        << Employee:: getCount() << endl;

        cout << "\n\nEmployee 1: "
            << e1.getFirstName() << " " << e1.getLastName()
            << "\nEmployee 2: "
            << e2.getFirstName() << " " << e2.getLastName() << "\n\n";

        Employee e8 ("Tomas","Hwang",'F');
        Employee e9 ("James","Wang", 'F');
        cout << "Number of employees after objects are instantiated is: \n";
            Employee::printCount();

            cout << "\n\nEmployee 3:";
            e3.printFirstName().printLastName();
            cout << "\nEmployee 3: ";
            e3.printLastName()->printFirstName();

            cout << "\nEmployee 4:";
            e4.printFirstName().printLastName();
            cout << "\nEmployee 4: ";

            e4.printLastName()->printFirstName();

            cout << endl << endl ;;
    }

    cout << "\nNumber of employees after objects are deleted is "
         << "Number of employees= " << Employee::getCount() <<  " Female employees= "
         << Employee::getfCount() << " Male employees= " << Employee::getmCount() << endl;

    return 0;
}
