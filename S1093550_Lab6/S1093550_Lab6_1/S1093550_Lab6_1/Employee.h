/*Deeper look into classes Employee Count Program output 1 */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;


class Employee {
    friend void print(const Employee&);
    public:
    Employee (const string &, const string &,char);
    ~Employee ();
    string getFirstName() const;
    string getLastName() const ;
    static int getCount();
    static int getfCount();
    static int getmCount();
    static void printCount();
    Employee& printFirstName();
    Employee* printLastName();

    private:
    string firstName;
    string lastName;
    char gender;
    static int count;
    static int fCount;
    static int mCount;

};


#endif // EMPLOYEE_H
