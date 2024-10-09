#include <cctype>
#include "Hugeint.h"
using namespace std;

HugeInt::HugeInt( long value ){ // converts a long into a  HugeInt object

    for ( int i =0 ; i < digits; i++ ){
            integer[i] =0 ;

    }

    for ( int j = digits - 1 ; value !=0 && j>= 0 ;j -- ){
        integer[j]  = value % 10 ;
        value /=10;
    }
}


HugeInt:: HugeInt( const string  & number){ // converts a string into a Huge Object
    for (int i = 0 ; i < digits; i ++ ){
        integer[i] = 0 ;

    }

    int length = number.size();

    for (int j = digits - length ,k = 0 ; j < digits ; j ++ ,k++){
            if(isdigit(number[k])){
                integer[j] = number [k] - '0';
            }

    }
}


HugeInt HugeInt:: operator+ (const HugeInt & op2 ) const// hugeInt + hugeInt
{

   HugeInt temp ;
   int carry = 0 ;

   for ( int i = digits-1 ; i >= 0 ; i-- ){
        temp.integer[i] = integer[i] + op2.integer[i] + carry;


   if (temp.integer[i] > 9 ){
    temp.integer[i] %=10;

    carry = 1;

   }
    else
        carry =0 ;
   }
   return temp;
}

HugeInt HugeInt:: operator+( int op2) const {//  HugeInt + int
    return *this + HugeInt(op2);
}
HugeInt operator + (int int1 ,const HugeInt& op2){ // int + HugeInt
return HugeInt(int1) + op2;

}


HugeInt HugeInt:: operator + ( const string  & op2) const // HugeInt + string
{
    return *this + HugeInt(op2);
}

HugeInt operator + ( string str1, const HugeInt& op2) // string + HugeInt
{
    return HugeInt(str1) + op2;
}




 // Prefix and PostFix :
 HugeInt HugeInt::helpIncrement (){ // increments one to the current HugeInt - helper function for prefix and postfix operations

   return *this + 1;
}

HugeInt& HugeInt:: operator ++ ()//   operator prefix ++n1
{
    //helpIncrement();
    *this = *this + 1;
    return *this;

}
HugeInt HugeInt:: operator ++ (int)// operator postfix n1++
{
    HugeInt temp = *this;
    //helpIncrement();
    *this = *this + 1;
    return temp;

}


// Comparisons functions operators

int HugeInt::getSize(){
 return digits;
}
bool operator >= (int int1, HugeInt h1)// int >= HugeInt
{
 return HugeInt(int1) >= h1;


}

bool operator >= (string str1, HugeInt h1)// string >= hugeInt
{
 return HugeInt(str1)>= h1;

}

bool HugeInt::operator >= (HugeInt h1)//  HugeInt >= HugeInt
{

   for ( int i = 0 ; i < digits ; i++ ){
        for (int j = 0 ; j < h1.getSize() ; j ++){
            return integer[i] >= h1.integer[j];


       }


   }


}

bool HugeInt::operator >= (int int1)//  hugeInt >= int
{

  return (*this) >= HugeInt(int1);

}

bool HugeInt::operator >= (string str1)//  hugeInt >= string
{


  return (*this) >=HugeInt(str1);

}



ostream &operator << (ostream & output ,const HugeInt & num ){

      int i ;
      for ( i =0 ; (num.integer[i]==0  ) &&  (i <=   HugeInt::digits); i++  )
            ;

        if ( i ==HugeInt::digits)
            output  << 0;
        else
            for (; i  < HugeInt:: digits; i ++)
                    output  << num.integer[i];

        return output;

}
