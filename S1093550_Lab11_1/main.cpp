/* Lab 11 Part I */
#include <iostream>
#include<sstream>
#include<stdlib.h>
using namespace std;

struct House {
  int x;
  int y;
};
int main()
{
    int avenue ;
    int street;
    string inputString;
    const int max_num_Relatives = 500 ;
    House ArrHouses [max_num_Relatives]={0};// arrHouses at most 500 relatives
    int numberOfTestCases = 0 ;

    while (getline(cin, inputString)) {// for each case
    int minimumDistance = 0 ;
    stringstream ssLine(inputString);
    int numberOfHouses = 0 ;
    int xArr [30000];
    int yArr [30000];
    House ArrAddresses[30000]; //Storing addresses at most 30000 addresses

    while( ssLine >>     avenue >> street){ //  reads one line at a time , continue reading until the end of the line
         xArr[numberOfHouses] = avenue;
         yArr[numberOfHouses] = street;
         ArrAddresses[numberOfHouses].x = avenue;
         ArrAddresses[numberOfHouses].y = street;
         numberOfHouses++;
    }

     for ( int loop  = 0 ; loop < numberOfHouses-1; loop++){// sorting from ascending order the array of x  and the array of y
        for (int i  = 0 ; i < numberOfHouses - 1 ; i++ ){
            int tempX;
            int tempY;
            if (xArr[i] > xArr[i+1]){
                tempX = xArr[i];
                 xArr[i] =  xArr[i+1];
                xArr[i+1] =  tempX;
            }
             if (yArr[i] > yArr[i+1]){
                tempY = yArr[i];
                 yArr[i] =  yArr[i+1] ;
                yArr[i+1]  =  tempY;
            }


        }
     }
      // getting the median of each array
      int BestLocX = xArr [ (int)numberOfHouses/2];// coordinate x
      int BestLocY =  yArr[ (int)numberOfHouses/2];//  coordinate y

      for(int j=0; j<numberOfHouses; j++){

       int sum = abs( ArrAddresses[j].x  -BestLocX )+ abs( ArrAddresses[j].y - BestLocY);
        minimumDistance+=  sum;

      }
     cout << minimumDistance << endl ;

    numberOfTestCases++;
    }



return 0;
}
