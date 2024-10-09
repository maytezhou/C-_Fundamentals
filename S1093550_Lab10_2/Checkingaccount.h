#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "Savingaccount.h"
#include "Account.h"
using namespace std;
class SavingAccount;
class CheckingAccount:public Account
{

friend bool CheckingToSaving(CheckingAccount&, SavingAccount&,const double );
public:
CheckingAccount(double =0.0 , double =0.0 , double = 3.0 , double = 2.0 );
virtual bool debit (double = 0.0);
virtual void credit(double = 0.0);
virtual void print();

private :
    double transactFeeW;
    double transactFeeD;


};

#endif // CHECKINGACCOUNT_H

