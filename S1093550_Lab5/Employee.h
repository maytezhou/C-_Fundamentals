#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Date.h"

using namespace std;

class Employee{

public:
 Employee (const string &, const string &, const Date & ,const Date &, Date & , int );
 void print () const ;
 Employee* eDismiss(const Date &);
 Employee& increaseSalary (int );
 bool checkingDismissDate();
 ~Employee();

private:
    string firstName;
    string lastName;
    const Date birthDate;
    const Date hireDate;
    Date dismissDate;
    int monSalary;


};

#endif
