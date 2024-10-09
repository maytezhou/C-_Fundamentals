/*Deeper look into classes Employee Count Program output 1 */
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;


void print(const Employee& E){ // Remember to comment this function, when void print(const Employee E) is used
    if (E.gender == 'F' || E.gender == 'M'){
         cout << E.firstName << " " << E.lastName << " " << E.gender<< endl ;
    }

}


Employee::Employee (const string & first, const string & last, char gendr)
    : firstName (first), lastName (last), gender (gendr) {
        ++count;
         if (gender != 'F' && gender != 'M'){
            cout << "Employee's gender specification is incorrect. " << gender << endl ;
        }

        if (gender == 'F'){
            ++fCount;
        }
         if (gender == 'M'){
            ++mCount;
        }



        cout << "Employee constructor for " << firstName
        << ' ' << lastName << " called." <<  endl ;


}

int Employee:: getfCount(){
    return fCount;
}

int Employee:: getmCount (){
    return mCount;
}

void Employee::printCount(){
    cout << "Number of Employees= " << count << " ";
    cout << "Male employees= " << mCount << " ";
    cout << "Female employees= " << fCount << endl ;

}
Employee& Employee::printFirstName(){
  cout << " " << firstName << ' ';
  return *this;
}
Employee* Employee::printLastName(){
    cout << lastName ;
    return this;
}

Employee:: ~Employee  (){

    cout << "~Employee() called for " << firstName
    << ' ' << lastName << endl;
    -- count;
    if (gender == 'F'){
        fCount--;
    }
    if (gender =='M'){
        mCount--;
    }

}

string Employee::getFirstName () const
{
    return firstName;
}

string Employee::getLastName () const
{
    return lastName;
}
