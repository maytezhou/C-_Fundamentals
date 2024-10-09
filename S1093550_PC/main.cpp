/* Processing Bank Accounts with containers STL */
#include <iostream>
#include <fstream>
#include <iomanip>
#include<cstdlib>
#include <map>
#include <iterator>


#include "ClientData.h"
using namespace std;


void outputLine (ostream &,const ClientData & );
void readFromRandomFile(ifstream &, multimap<string, ClientData> &) ;// added
void printAllRecords(multimap<string, ClientData> ) ; // added
void sameLastName(multimap<string, ClientData>, const string) ; // added




int main()
{
    ifstream inCredit;
    multimap <string, ClientData> mLastName;
    string lastName;

   if ( !inCredit )
   {
      cerr << "File could not be opened." << endl;
      exit ( 1 );
   }
   readFromRandomFile(inCredit, mLastName);
   inCredit.clear();
   printAllRecords(mLastName);
   inCredit.close();
   cout << "Enter the last name of a customer (QUIT for quit): " << endl;
   cin >> lastName;
   while (lastName != "QUIT"){
        sameLastName(mLastName, lastName);
        cout << "Enter the last name of a customer (QUIT for quit): " << endl;
        cin >> lastName;
   }
    return 0;
}


void readFromRandomFile( ifstream & readFromFile , multimap <string,ClientData  > & Mmc){

     readFromFile.open("inputFilePC.dat",ios::in |ios::binary);
     if(!readFromFile){
        cout << "Input File C could not be opened" << endl;
     }

     ClientData client;
     readFromFile.seekg(0);
     readFromFile.read(reinterpret_cast <char*> (&client), sizeof(ClientData));// reading first record
     while ( readFromFile  && !readFromFile.eof()){
        if (client.getAccountNumber() != 0 ){ // while the record has information

           outputLine(cout,client);
           Mmc.insert(make_pair(client.getLastName(),client)) ;// put it inside of a map
        }
        readFromFile.read(reinterpret_cast <char*> (&client), sizeof(ClientData));// reading all remain records
     }

}

void printAllRecords(  multimap<string, ClientData> Mcm ) {

    for ( auto it = Mcm.begin(); it!=Mcm.end(); ++it){
       outputLine(cout, it->second);

    }

}


void sameLastName(multimap<string, ClientData> Mcm, const string lastName){


    for ( auto it = Mcm.begin(); it != Mcm.end();++it){
        if (it -> first == lastName){
              outputLine(cout, it->second);
        }

    }

}


void outputLine ( ostream &output , const ClientData &record  ){

        output << left << setw (10) << record.getAccountNumber()
              <<setw (16) << record.getLastName()
              << setw(11) << record.getFirstName()
              //<< setw(17) <<  record.getCityName()
              << setw (10) << setprecision(2) << right << fixed
              << showpoint << record.getBalance( ) << endl ;

}
