#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;

class Account{

public:
   Account(double = 0.0 ,double = 0.0);
   virtual void credit(double = 0.0 ) = 0;
   virtual bool debit (double = 0.0) = 0 ;
   double getBalance();
   double calculateInterest();
   virtual void print() = 0 ;
   void setBalance(double); /*added*/
   void setInterestRate(double);/*added*/
   double getInterestRate(); /*added*/
private:
    double balance;
    double interestRate;


};
#endif // ACCOUNT_H

