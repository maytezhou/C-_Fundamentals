#include <iostream>
#include "Account.h"
#include <string>
using namespace std;

Account::Account(double bal, double iRate){

    if (bal> 0 )
        balance = bal;
    else
        balance = 0 ;

    if (iRate > 0 )
        interestRate = iRate;
    else
        interestRate = 0 ;

}

double Account::getInterestRate() {
    return interestRate;
}
void Account::setBalance(double newBal){
    balance = newBal;
}

void Account::setInterestRate(double newIntR){
    interestRate = newIntR;
}

double Account ::getBalance(){
    return balance;
}


double Account::calculateInterest(){

   double interest = interestRate * balance;
   balance = balance + interest;
   return interest;

}
