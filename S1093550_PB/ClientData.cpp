#include <string>
#include "ClientData.h"

using namespace std;


ClientData ::ClientData (int accountNumberValue, string lastNameValue, string firstNameValue ,string cityName, double balanceValue){

    setAccountNumber (accountNumberValue);
    setLastName (lastNameValue);
    setFirstName (firstNameValue);
    setCityName(cityName);
    setBalance ( balanceValue);
};

int ClientData::getAccountNumber () const {
  return accountNumber ;
}

void ClientData::setAccountNumber( int accountNumberValue){

 accountNumber =  accountNumberValue ;
}


string ClientData ::getLastName () const {
 return lastName;

}


void ClientData :: setLastName( string lastNameString){

   int length = lastNameString.size();

   length = ( length < 15 ? length : 14);
   lastNameString.copy(lastName, length);
   lastName [length] =  '\0';

}


string ClientData :: getFirstName ( ) const {

  return firstName ;
}
void ClientData::setFirstName(string firstNameString){


 int length = firstNameString.size();
 length = (length < 10 ? length  : 9  );

 firstNameString.copy(firstName, length);
 firstName[length] = '\0';
}

string ClientData :: getCityName ( ) const {

  return cityName ;
}
void ClientData::setCityName(string cityNameString){


 int length = cityNameString.size();
 length = (length < 16 ? length  : 15  );

 cityNameString.copy(cityName, length);
 cityName[length] = '\0';
}



double ClientData :: getBalance() const {

 return balance;
}


void ClientData :: setBalance ( double balanceValue){

 balance = balanceValue ;
}
