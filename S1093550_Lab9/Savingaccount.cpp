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

bool SavingAccount::debit(double amountToDebit){
    if (Account::debit(amountToDebit)){
         Account::debit(transactFee);

         return true;
    }else{
       return false;
    }

}

void SavingAccount::print(){
   cout << "Saving Account:" << endl;
   Account::print();
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
