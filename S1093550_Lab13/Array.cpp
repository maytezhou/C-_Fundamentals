#include <iostream>
#include<iomanip>
#include<cstdlib>
#include "Array.h"

using namespace std;

Array:: Array ( int arraySize ){
size = (arraySize >0 ? arraySize :10);
ptr = new int [size];

for (int i = 0 ; i < size ; i ++ ){
    ptr[i] = 0 ;// initializes each element of the array = 0
}
}


Array:: Array (const Array &arrayToCopy)
    :size (arrayToCopy.size)

{
    ptr = new int [size];
    for (int i =0 ; i < size ; i ++ ){
        ptr[i] = arrayToCopy.ptr[i];
    }
}
Array ::~Array (){

 delete  [] ptr;

}

int Array :: getSize () const {

    return size;
}

//const return avoids: (a1 =a2)=a3
const Array &Array::operator= (const Array & right )
{


   try {

            if (& right != this){

                if (size != right.size){
                    delete [] ptr;
                    size = right.size;
                    ptr=new int [size];
                }
                for (int i = 0 ; i < size ; i ++ ) {
                    ptr[i] = right.ptr[i];
                }

            }  else {
                throw &right!= this;
            }
    }

    catch ( bool  &areEqual){
       cout << "ARRAY TRIES TO ASSINGN TO ITSELF!!" << endl;
    }

    return *this;
}

const Array &Array::operator- ()
{

        for (int i = 0 ; i < size ; i ++ ) {
            this->ptr[i] = (this->ptr[i])* -1;
        }



    return *this;
}

 Array Array::operator+ (const Array & right)
{
        int sizeNewArr = this->getSize() + right.size;
        Array newArr(sizeNewArr);
        int i , k;
        for ( i = 0 ;i < this->getSize(); i ++ ){
            newArr.ptr[i] = this->ptr[i];
        }
        k = i ;
        for ( i = 0 ; i < right.size; i ++){

                newArr.ptr[k] = right.ptr[i];
                k++;

        }
    return newArr;
}

 const Array &Array::operator>> (int k)
{
        if (k> size){
            k = k% size;
        }


        for (int j =0 ; j <k ; j ++ ){
           int temp= this->ptr[size-1];

          for (int i= size-2 ; i >=0 ;i--){
             this->ptr[i+1] = this->ptr[i];
          }


        this->ptr[0] = temp;
        }

return *this;
}

bool Array::operator ==( const Array & right ) const
{
    if (size !=right.size)
        return false;


    for (int i =0 ;i < size; i ++ )
        if (ptr[i ]!= right.ptr[i])
            return false;



    return true;
}


// overloaded subscript operator for non const arrays
// reference return creates a modifiable lvalue   // For example  integers1[5] = 1000 ;
int & Array::operator[](int subscript){// here you have to add a try and catch block
    try {
         if (subscript < 0 || subscript >= size ){

            cout <<  "Bad array index ( left value): " << subscript << endl;
            throw exception() ;

        }
    }
    catch (exception &  ){
            throw;
    }

    return ptr[subscript];
}


// overloaded subscript operator for const Arrays
// const reference return creates an rvalue   // For example  integers1[5]
int Array::operator[](int subscript) const {// here you have to add a try and catch block

    try {
         if (subscript < 0 || subscript >= size ){
             cout<<  "\nBad array index ( right value): " << subscript << endl;
            throw exception() ;

        }
    }
    catch (exception &  ){
           throw;
    }
    return ptr[subscript];
}

istream &operator>> (istream &input, Array &a){
    for (int i = 0 ; i < a.size ; i ++ ){
        input >> a.ptr[i];
    }
    return input;
}

ostream &operator << (ostream &output, const Array & a ){
    int i ;
    for (int i = 0 ; i < a.size ; i ++ ){
        output << setw(12) << a.ptr[i] ;

        if ((i+ 1 ) % 4 == 0)
            output  << endl;
    }

    if ( i % 4 !=0 )
        output << endl ;

    return output;

}

