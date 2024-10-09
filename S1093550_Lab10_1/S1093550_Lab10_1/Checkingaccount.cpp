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

bool CheckingAccount::debit(double amountToDebit){
   if (Account::debit(amountToDebit)){
     Account::debit(transactFeeW);
     return true;
   }else{
     return false;
   }



}

void CheckingAccount::credit(double amountToDeposit){
    Account::credit(amountToDeposit);
   Account::debit(transactFeeD);


}
void CheckingAccount::print(){
  cout << "Checking Account:" << endl;
  Account::print();
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

