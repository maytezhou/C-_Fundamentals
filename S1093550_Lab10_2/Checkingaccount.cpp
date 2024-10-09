#include <iostream>
#include "Checkingaccount.h"
#include "Account.h"

using namespace std;

CheckingAccount::CheckingAccount(double balan ,double intR, double transFeeW ,double transFeeD)
    :Account(balan,intR)

{

    transactFeeD = transFeeD;
    transactFeeW = transFeeW;
}

bool CheckingAccount::debit(double withdw){

    if (withdw > 0 && withdw <= Account::getBalance()){
        double newBalance = Account::getBalance() - withdw - transactFeeW;
        Account::setBalance(newBalance);
        return true ;

    }
    else if (withdw > Account::getBalance()){
        cout << " Debit amount exceeded account balance. " << endl ;
         return false;

    }
  return false;
}

void CheckingAccount::credit(double amountToDeposit){
   if(amountToDeposit > 0 ){
         double newBalance = Account::getBalance() + amountToDeposit - transactFeeD;
         Account::setBalance(newBalance);
     }

}
void CheckingAccount::print(){
  cout << "Checking Account:" << endl;
  cout << " Balance: "  << Account::getBalance() << endl;
  cout << " Interest rate: " << Account::getInterestRate() <<endl ;
  cout << " Transaction fee of withdraw : "  << transactFeeW << endl;
  cout << " Transaction fee of deposition: "  << transactFeeD << endl;
}




bool CheckingToSaving(CheckingAccount& checkAcc, SavingAccount& saveAcc, const double  amountToTranser){ // from checking to saving
   if (amountToTranser <= 0 || amountToTranser > checkAcc.getBalance() ){
     cout << "Transfer transaction fails." << endl;
     return false;

   }else {

        if ( checkAcc.debit(amountToTranser) ){
                saveAcc.credit(amountToTranser);
                return true;
            }else {

                return false;
        }

   }

    return false;
}

