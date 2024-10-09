/* Bank Account Transactions */
#include <iostream>
#include <fstream>
#include <iomanip>
#include<cstdlib>
#include "ClientData.h"
using namespace std;


int enterChoice();
void createTextFile (fstream & );
void updateRecord (fstream & );
void newRecord (fstream &);
void deleteRecord ( fstream &);
void outputLine (ostream &,const ClientData & );
int getAccount ( const char  * const );

void printAllRecords(fstream & );// added // it can be change for fstream

void createRandomFile(ifstream &, fstream &, const int);


enum Choices { PRINT  = 1 ,UPDATE,NEW,DELETE,END };


int main()
{
    ifstream inFile ( "inputFilePB.dat", ios::in);
    fstream inOutCredit;
    inOutCredit.close();
    inOutCredit.open("binaryFilePB.dat",ios::out | ios::binary);

    const int numAcc = 100;
    createRandomFile(inFile,inOutCredit,numAcc);
    inOutCredit.clear();
    inOutCredit.seekg(0);
    printAllRecords(inOutCredit);// added
    int choice ;
    while ( (choice = enterChoice() ) != END){

                switch (choice ){
                case PRINT:
                    createTextFile (inOutCredit);
                    break;

                case UPDATE :
                    updateRecord(inOutCredit);
                    break;

                case NEW:
                    newRecord(inOutCredit);
                    break;

                case DELETE:
                    deleteRecord(inOutCredit);
                    break;

                default:
                    cerr << "Incorrect choice" << endl;
                    break;


                }
        inOutCredit.clear();

    }

   printAllRecords(inOutCredit);
   inOutCredit.close();

    return 0;
}

int enterChoice (){

  cout << "\nEnter your choice" << endl
    << "1 - store a formatted text file of accounts" << endl
    << " called \"print.txt\" for printing" << endl
    << "2 - update an account" << endl
    <<"3 - add a new account" << endl
    <<"4 - delete an account" << endl
    << "5 - end program \n? " ;

    int menuChoice;
    cin >> menuChoice;
    return menuChoice ;

}


void createTextFile( fstream & readFromFile){
    ofstream outPrintFile("print.txt", ios:: out);

    if (!outPrintFile){
        cerr << "File could not be created." << endl;
        exit(1);
    }
    outPrintFile << left << setw(10) << "Account"
    << setw(16) << "Last Name"
     << setw(11) << "Fist Name"
      << setw(17) << "City Name"
       << right << setw(10) << "Balance" << endl ;

     readFromFile.seekg(0);

     ClientData client;

     readFromFile.read(reinterpret_cast <char*> (&client), sizeof(ClientData));

     while (!readFromFile.eof()){

        if (client.getAccountNumber() != 0 )
            outputLine(outPrintFile, client);
        readFromFile.read(reinterpret_cast <char*> (&client), sizeof (ClientData));

     }


}




void createRandomFile( ifstream & readFromFile , fstream & binaryHandle, const int numAcc){
     if (!readFromFile){
        cerr << " ifstream File could not be opened" << endl;
        exit(1);
     }
     int accountN;
     string lastN, firstN,cityN;
     double bal;
     ClientData blankClient;
     ClientData client;

     for (int i =0 ; i <numAcc ; i++){// creating a random access file with  blank records
            binaryHandle.write(reinterpret_cast<const char * > (&blankClient),
            sizeof(ClientData));
     }


     while ( readFromFile >> accountN >> lastN>> firstN >> cityN >> bal ){

            client.setAccountNumber(accountN);
            client.setLastName(lastN);
            client.setFirstName(firstN);
            client.setCityName(cityN);
            client.setBalance(bal);
           // outputLine(cout,client);
            binaryHandle.seekp(  (client.getAccountNumber() - 1 ) * sizeof(ClientData));
            binaryHandle.write(reinterpret_cast<const char * > (&client),
                               sizeof(ClientData));
                              // binaryHandle.clear();
     }
     //binaryHandle.close();
}
void printAllRecords ( fstream & readFromFile){//  reading from binary file to print with cout

   readFromFile.close();
   readFromFile.open("binaryFilePB.dat",ios::in| ios::out| ios::binary);

   if (!readFromFile){
      cout << "Binary file could not be opened " << endl;
      exit(1);
   }
     ClientData client;
     readFromFile.read(reinterpret_cast <char*> (&client), sizeof(ClientData));

      cout << left <<setw(10) << "Account" << setw(16) << "Last Name" << setw(11) << "First Name" << setw(17) << "City Name" << right << setw(10) << "Balance" << endl ;

     while (!readFromFile.eof()){

        if (client.getAccountNumber() != 0 )
            outputLine(cout, client);
        readFromFile.read(reinterpret_cast <char*> (&client), sizeof (ClientData));

     }
}


void updateRecord ( fstream & updateFile){

   int accountNumber = getAccount ( "Enter account to update");

   updateFile.seekg(  (accountNumber - 1 ) * sizeof ( ClientData));


   ClientData client ;
   updateFile.read(reinterpret_cast <char* > (&client ), sizeof (   ClientData));


   if (client.getAccountNumber () != 0 ){


    outputLine ( cout ,client );

    cout << "\nEnter charge (+) or payment (-): " ;
    double transaction;
    cin >> transaction ;

    double oldBalance = client.getBalance() ;
    client.setBalance( oldBalance + transaction );
    outputLine( cout , client );

    updateFile.seekp ( (accountNumber - 1)  * sizeof  ( ClientData)) ;

    updateFile.write(reinterpret_cast < const char * > (&client), sizeof ( ClientData));

   }

   else
        cerr << "Account #" << accountNumber
           << " has no information." << endl ;


}





void newRecord( fstream &insertInFile){

    int accountNumber = getAccount("Enter new account number");// changed

    insertInFile.seekg(   (accountNumber - 1 ) * sizeof (ClientData));

    ClientData client;

    insertInFile.read(reinterpret_cast <char* > ( & client ), sizeof (ClientData));


    if (client.getAccountNumber () ==0 ){

        string lastName;
        string firstName;
        string cityName; // added
        double balance;

        cout << "Enter lastname, firstname,cityName, balance \n?";
        cin >> setw(15) >> lastName;
        cin >> setw(10) >> firstName;
        cin >> setw(17) >> cityName; // added
        cin >> balance;


        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setCityName(cityName);// added
        client.setBalance(balance);
        client.setAccountNumber(accountNumber);


        insertInFile.seekp( (accountNumber - 1 ) * sizeof ( ClientData));

        insertInFile.write(reinterpret_cast < const char * > ( & client ),sizeof (ClientData));



    }
    else
    cerr  << "Account #" <<  accountNumber
        << "already contains information." << endl;



}



void deleteRecord( fstream & deleteFromFile){

    int accountNumber = getAccount ("Enter account to delete ");

    deleteFromFile.seekg( ( accountNumber - 1 ) * sizeof  ( ClientData)) ;
    ClientData client;
    deleteFromFile.read ( reinterpret_cast < char * > ( & client ), sizeof (ClientData));


    if ( client.getAccountNumber() != 0 ) {


        ClientData blankClient;


        deleteFromFile.seekp ( (accountNumber - 1 ) * sizeof ( ClientData ));

        deleteFromFile.write (  reinterpret_cast < const char * >  ( & blankClient), sizeof (ClientData));

        cout << "Account #" << accountNumber << " deleted.\n";


    }

    else
           cout << "Account #" << accountNumber << " is empty.\n";

}


void outputLine ( ostream &output , const ClientData &record  ){

        output << left << setw (10) << record.getAccountNumber()
              <<setw (16) << record.getLastName()
              << setw(11) << record.getFirstName()
              << setw(17) <<  record.getCityName()
              << setw (10) << setprecision(2) << right << fixed

               << showpoint << record.getBalance( ) << endl ;

}



int getAccount ( const char * const prompt ){


 int accountNumber ;
  do {

    cout << prompt << " (1-100):";
    cin >> accountNumber;

  }while (accountNumber  < 1 || accountNumber > 100 );

  return accountNumber;

}
