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


double Account ::getBalance(){

    return balance;
}




void Account::credit(double depos){

     if(depos > 0 ){
         balance = balance + depos;


     }

}



bool Account :: debit (double withdw){

    if (withdw > 0 &&withdw <= balance){
        balance = balance - withdw ;

        return true ;

    }
    else if (withdw > balance){
        cout << " Debit amount exceeded account balance. " << endl ;
        return false;

    }

    return false;

}

void Account::print(){

    cout << " Balance: "  << balance << endl;
    cout << " Interest rate: " << interestRate <<endl ;
}

double Account::calculateInterest(){

   double interest = interestRate * balance;
   balance = balance + interest;
   return interest;

}
