/* Bank Account with Polymorphism Part I */
#include <iostream>
#include <typeinfo>
#include<string>
#include<vector>
#include "Savingaccount.h"
#include "Checkingaccount.h"
#include "Account.h"
using namespace std;

int main()
{
   Account bAcnt(100.0);
   SavingAccount sAcnt(110.0,0.05);
   bAcnt = sAcnt;
   CheckingAccount cAcnt(120.0,0.02,4.0,2.0);
   CheckingAccount c2Acnt(500.0,0.025,4.0,2.0);
   SavingAccount s2Acnt(1000.0,0.04,1.0);
   const int numAcc = 5 ;
   vector <Account*> baseAccount(numAcc);
   baseAccount[0] = &cAcnt;
   baseAccount[1] = &c2Acnt;
   baseAccount[2] = &bAcnt;
   baseAccount[3] = &sAcnt;
   baseAccount[4] = &s2Acnt;

   for (int i = 0 ; i < numAcc ; i++ ){
        cout << "\nAccount type = " << typeid(*baseAccount[i]).name() << endl;
         baseAccount[i]-> debit(20.0);
         baseAccount[i]-> credit(100.0);
         baseAccount[i]-> print();
         CheckingAccount *cAcntPtr = dynamic_cast<CheckingAccount *> (baseAccount[i]);
         if(cAcntPtr !=0){
            cAcntPtr->calculateInterest();
            cout << "Balance of the checking account after adding interest = " << cAcntPtr->getBalance() << endl;

         }else{
         SavingAccount *sAcntPtr = dynamic_cast<SavingAccount *> (baseAccount[i]);
            if (sAcntPtr != 0){
                sAcntPtr->calculateInterest();
                cout << "Balance of the saving account after adding interest = " << sAcntPtr->getBalance()<< endl;

            }else {

                cout << "A base account, balance= " << baseAccount[i]->getBalance() << endl;
            }

         }

   }
}
