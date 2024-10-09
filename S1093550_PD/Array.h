/* Operator Overloading*/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

template  <typename T>
class Array {
     template  < typename U> friend ostream &operator<<(ostream & , const Array <U> & );
     template  <typename U > friend istream &operator >>(istream &, Array <U> &);
public:
    Array (int = 3, int = 3 );// by default an array with 10 arrays ,and each array will have 10 elements
    Array (const Array & );
    ~Array();
    int getRow() const ;
    int getCol() const ;
    const Array &operator = (const Array & );
    bool operator ==(const Array & ) const;
    bool operator !=(const Array & right) const
    {
    return !(*this == right );

    }

    T & operator() (int,int);
    T operator ()(int,int)const ;

private:
    int row; // number of rows
    int col; // number of columns
    T** ptr; // pointer to a pointers arrays


};
#endif // ARRAY_H



template  <typename T> // constructor
Array <T>:: Array ( int rw, int cl )
:row (rw >0 ? rw :3),col (cl >0 ? cl :3)

{

 try {

      ptr = new T*[row] ;// new array of arrays(pointers)
    for (int i =0 ; i < row ; i ++ ){
        ptr[i] = new T [col]; // for each array  I want to allocate  an array of col number of T elements

    }
 }
 catch(bad_alloc  & memoryAllocExcep ){

   cout << "ERROR: Memory allocation exception for Array occurs: " << memoryAllocExcep.what() << endl ;
 }



}

template  <typename T>
Array <T>:: Array (const Array &arrayToCopy)//copy constructor
    :row (arrayToCopy.row),col (arrayToCopy.col)

{
    ptr = new T*[row] ;//  allocating for new array of arrays(pointers)
    for (int i =0 ; i < row ; i ++ ){
            ptr[i] = new T[col];     //  allocating  memory for each array of  T elements
    }

    for (int i =0 ; i < row; i ++ ){
            for ( int j =0 ; j < col ; j++ )
             ptr[i][j] = arrayToCopy.ptr[i][j]; // copying each element of one array to the other
    }


}

template  <typename T>
Array<T> ::~Array (){
  for (int i =0 ; i < row ; ++i ){
      delete [] ptr[i] ;
  }
 delete  [] ptr;

}


template  <typename T>
int Array<T> :: getRow () const {

    return row;
}

template  <typename T>
int Array<T> :: getCol () const {

    return col;
}


template  <typename T>
const Array<T> & Array <T>::operator= (const Array & right )
{
    if (&right != this && row == right.row  && col == right.col){
        for (int i = 0 ; i < row ; i ++ ) {
            for (int j = 0 ; j < col ; j ++ )
            ptr[i][j] = right.ptr[i][j];
        }

    }

    return *this;
}


template  <typename T>
bool Array <T>::operator ==( const Array<T>& right ) const
{
    if (row !=right.row || col != right.col)
        return false;


    for (int i =0 ;i < row; i ++ ){
        for (int j = 0 ; j < col ; j ++){
              if (ptr[i ][j]!= right.ptr[i][j])
                return false;
        }
    }
    return true;
}



template  <typename T> // addded
T & Array <T>::operator()(int subscriptRow, int subscriptCol){// returns modifiable value  lvalue integers1[1][2] = 1000



         if (subscriptRow < 0 || subscriptRow >= row  ){
                //cerr<<  "\nError: Row subscript is out of range" << endl;
                throw ("\nError: Row subscript is out of range");
          }

          if (subscriptCol < 0 || subscriptCol >= col  ){
                 //cerr<<  "\nError: Column subscript is out of range." << endl;
                throw("\nError: Column subscript is out of range." );

          }



    return ptr[subscriptRow][subscriptCol];
}


template  <typename T> // added
T  Array <T>::operator()(int subscriptRow, int subscriptCol) const { // returns non modifiable value  rvalue integers1[1][2]

         if (subscriptRow < 0 || subscriptRow >= row  ){
                throw ("\nError: Row subscript is out of range");
          }
          if (subscriptCol < 0 || subscriptCol >= col  ){
                 //cerr<<  "\nError: Column subscript is out of range." << endl;
                throw("\nError: Column subscript is out of range." );

          }

    return ptr[subscriptRow][subscriptCol];
}

template  <typename U>
istream &operator>> (istream &input, Array <U> &a){
    for (int i = 0 ; i < a.row ; i ++ ){
        for (int j =0 ;j < a.col ; j++){
               input >> a.ptr[i][j];
        }

    }
    return input;
}


template  <typename U>
ostream &operator << (ostream &output, const Array <U> &a ){
    int j ;
    for (int i = 0 ; i < a.row ; i ++ ){

       for ( j =0 ; j < a.col ; j ++ ){

          output << setw(12) << a.ptr[i][j] ;



       }
       output<<endl;
    }



    return output;

}
