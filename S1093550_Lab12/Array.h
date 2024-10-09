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
    Array (int = 10 );
    Array (const Array & );
    ~Array();
    int getSize() const ;
    const Array &operator = (const Array & );
    const Array &operator>> (int k);
    Array operator + (const Array & );
    const Array &operator- ();// declare each operator
    bool operator ==(const Array & ) const;
    bool operator !=(const Array & right) const
    {
    return !(*this == right );

    }
    T & operator[] (int);
    T operator [](int)const ;
    void swap(int , int );
private:
    int size;
    T * ptr;


};
#endif // ARRAY_H



template  <typename T>
Array <T>:: Array ( int arraySize )
:size (arraySize >0 ? arraySize :10),
ptr (new T [size])


{

}

template  <typename T>
Array <T>:: Array (const Array &arrayToCopy)
    :size (arrayToCopy.size)

{
    ptr = new T [size];
    for (int i =0 ; i < size ; i ++ ){
        ptr[i] = arrayToCopy.ptr[i];
    }
}

template  <typename T>
Array<T> ::~Array (){

 delete  [] ptr;

}


template  <typename T>
int Array<T> :: getSize () const {

    return size;
}


template  <typename T>
  void  Array<T> :: swap(int index1 , int index2 ){


   if ( (index1 >=0 && index1 < size) &&  (index2 >=0 && index2 < size)){

          T temp ;
          temp =  ptr[index1] ;
          ptr[index1] = ptr[index2];
          ptr[index2] = temp ;
    }

     if (  (index1 < 0 || index1 >= size)){
        cerr<<  "\n** Error: swapping fails, subscript " << index1
        << " out of range. " << endl;


    }


    if ((index2 < 0 || index2 >= size) ){
           cerr<<  "\n** Error: swapping fails, subscript " << index2
        << " out of range. " << endl;

    }




  }

template  <typename T>
const Array<T> & Array <T>::operator= (const Array & right )
{
    if (& right != this){

            if (size != right.size){
                delete [] ptr;
                size = right.size;
                ptr=new T [size];
            }
        for (int i = 0 ; i < size ; i ++ ) {
            ptr[i] = right.ptr[i];
        }

    }

    return *this;
}


template  <typename T>
const Array<T> & Array <T>::operator- ()
{

        for (int i = 0 ; i < size ; i ++ ) {
            this->ptr[i] = (this->ptr[i])* -1;
        }



    return *this;
}


template  <typename T>
 Array<T> Array <T>::operator+ (const Array & right)
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


template  <typename T>
 const Array<T>&Array <T>::operator>> (int k)
{
        if (k> size){
            k = k% size;
        }


        for (int j =0 ; j <k ; j ++ ){
           T temp= this->ptr[size-1];

          for (int i= size-2 ; i >=0 ;i--){
             this->ptr[i+1] = this->ptr[i];
          }


        this->ptr[0] = temp;
        }

return *this;
}


template  <typename T>
bool Array <T>::operator ==( const Array<T>& right ) const
{
    if (size !=right.size)
        return false;


    for (int i =0 ;i < size; i ++ )
        if (ptr[i ]!= right.ptr[i])
            return false;



    return true;
}


template  <typename T>
T & Array <T>::operator[](int subscript){

    if (subscript < 0 || subscript >= size ){
        cerr<<  "\nError: Subscript " << subscript
        << " is out of range " << endl;
        exit(1);

    }

    return ptr[subscript];
}



template  <typename U>
istream &operator>> (istream &input, Array <U> &a){
    for (int i = 0 ; i < a.size ; i ++ ){
        input >> a.ptr[i];
    }
    return input;
}


template  <typename U>
ostream &operator << (ostream &output, const Array <U> &a ){
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
