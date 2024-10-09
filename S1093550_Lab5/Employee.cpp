#include <iostream>
#include "Employee.h"
#include "Date.h"
#include <string>
using namespace std;

Employee::Employee ( const  string  & first , const string & last , const Date & dateOfBirth, const Date& dateOfHire, Date& dateDismiss, int salaryMon )
    : firstName (first),
      lastName (last),
      birthDate (dateOfBirth),
      hireDate (dateOfHire),
      dismissDate (dateDismiss),
      monSalary(salaryMon)

{

    cout << "Employee object constructor: " << firstName << ' ' << lastName << ' ' << "Monthly paid: " << monSalary << endl ;
     if (! (hireDate.compare(birthDate) == 1) ){//   hireDate should be later than birthDate , when it is different than  1
         cout << firstName << ' ' <<  lastName << " with inconsistent dates!" << endl;
    }

    if ( !checkingDismissDate() && !( dismissDate.compare(hireDate)== 1) ){ // dismissDate should be later than hireDate , when it is different than  1
        cout << firstName << ' ' <<  lastName << " with inconsistent dates!" << endl;
    }

}
void Employee::print() const {

        cout << firstName << lastName << ' ' <<  "Hired: " ;
        hireDate.print();
        cout << " Birthday: " ;
        birthDate.print();
        cout << " Monthly pay: " ;
        cout << monSalary;
        cout << " Dismissing: " ;
        dismissDate.print();
        cout << endl ;
}
 Employee* Employee ::eDismiss( const Date & dateDismiss)  {


    if (!( dateDismiss.compare(hireDate)== 1) ){
         cout << firstName << ' ' <<  lastName << " with inconsistent dates " << endl ;
         return this;
    }else{

        dismissDate.setDate(dateDismiss.getYear(), dateDismiss.getMonth(), dateDismiss.getDay());
        return this;

    }



}

Employee& Employee::increaseSalary(int increment) {

    monSalary += increment;
    return *this;
}

bool Employee::checkingDismissDate(){
    bool isDismissInitialValues;
        if (dismissDate.getYear() ==  1900 && dismissDate.getMonth() == 1 && dismissDate.getDay() == 1 ){
            isDismissInitialValues = true;
        }else{
            isDismissInitialValues = false;
        }
    return isDismissInitialValues;
}

Employee :: ~Employee() {

        cout << "Employee object destructor: " << lastName << "," << firstName << endl;

}
