/* Abstract Bank Account */
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

   SavingAccount sAcnt(110.0,0.05);
   CheckingAccount cAcnt(120.0,0.02,4.0,2.0);
   CheckingAccount c2Acnt(500.0,0.025,4.0,2.0);
   SavingAccount s2Acnt(1000.0,0.04,1.0);
   const int numAcc = 4 ;
   vector <Account*> baseAccount(numAcc);
   baseAccount[0] = &sAcnt;
   baseAccount[1] = &cAcnt;
   baseAccount[2] = &c2Acnt;
   baseAccount[3] = &s2Acnt;

   for (int i = 0 ; i < numAcc ; i++ ){
         baseAccount[i]-> debit(10.0);
         baseAccount[i]-> credit(50.0);
         baseAccount[i]-> print();
         SavingAccount *sAcntPtr = dynamic_cast<SavingAccount *> (baseAccount[i]);
         if(sAcntPtr !=0){
            sAcntPtr->calculateInterest();
            cout << "Balance of the saving account after adding interest = " << sAcntPtr->getBalance() << endl;
         }

   }
}
