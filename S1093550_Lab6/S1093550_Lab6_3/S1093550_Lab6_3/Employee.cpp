/*  Output 3 A deeper look into classes Employee Count*/
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;


void print(const Employee E){
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


 Employee::Employee(const Employee &obj ){
    firstName = obj.firstName;
    lastName = obj.lastName;
    gender = obj.gender;
    if (gender =='F' ){
        fCount++;
    }
    if (gender == 'M'){
        mCount++;

    }
     count++;


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
