#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include "Checkingaccount.h"
#include "Account.h"
using namespace std ;

class CheckingAccount;
class SavingAccount:public Account
 {

    friend bool SavingToChecking(SavingAccount &,CheckingAccount &, const double );
 public :
     SavingAccount(double = 0.0 , double = 0.0 , double = 3.0 );
     virtual bool debit ( double = 0.0 );
     virtual void print();



 private:

    double transactFee;

};
#endif // SAVINGACCOUNT_H
