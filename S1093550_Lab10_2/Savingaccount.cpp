#include <iostream>
#include "Savingaccount.h"
#include "Account.h"
#include <string>
using namespace std;

SavingAccount::SavingAccount(double bala,double intRate, double transFee)
 :Account(bala,intRate)
{
     transactFee = transFee;
}

bool SavingAccount::debit(double withdw){

    if (withdw > 0 && withdw <= Account::getBalance()){
        double newBalance = Account::getBalance() - withdw ;
        Account::setBalance(newBalance);
        double newBal = Account::getBalance() - transactFee ;
         Account::setBalance(newBal);
       return  true ;

    }
    else if (withdw > Account::getBalance()){
        cout << " Debit amount exceeded account balance. " << endl ;
       return false;

    }
    return false;

}


void SavingAccount::credit(double amountToDeposit){
   if(amountToDeposit > 0 ){
         double newBalance = Account::getBalance() + amountToDeposit;
         Account::setBalance(newBalance);

     }


}

void SavingAccount::print(){
   cout << "Saving Account:" << endl;
   cout << " Balance: "  << Account::getBalance() << endl;
   cout << " Interest rate: " << Account::getInterestRate() <<endl ;
   cout << " Transaction fee of withdraw: "  << transactFee << endl;

}


bool SavingToChecking(SavingAccount & saveAcc,CheckingAccount & checkAcc, const double amountToTransfer ){
   if ( amountToTransfer <= 0 || amountToTransfer > saveAcc.getBalance()){
        cout << "Transfer transaction fails." << endl;
        return false;
   }else {

            if ( saveAcc.debit(amountToTransfer)){
                    checkAcc.credit(amountToTransfer);
                    return true;
            }else {

                return false;
            }


   }

}
