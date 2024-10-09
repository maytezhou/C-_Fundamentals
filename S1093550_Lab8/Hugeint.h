#ifndef HUGEINT_H
#define HUGEINT_H
#include <iostream>
#include <string>

using namespace std;

class HugeInt {
    // comparisons operations to be performed as global functions
    friend HugeInt operator + (int, const HugeInt& h1);// int + hugeInt
    friend HugeInt operator + (string, const HugeInt& h1);// string + hugeInt
    friend bool operator >=(int , HugeInt h1 ); // // int >= HugeInt
    friend bool operator >=(string, HugeInt h1 ); // // string >= HugeInt


    friend ostream  &operator << (ostream & , const HugeInt &);
public:
    static const int digits = 30 ;
    // converters
    HugeInt ( long= 0 );
    HugeInt(const string & );
    // adding operations to be performed :
    HugeInt operator + (const HugeInt&) const;// hugeInt + HugeInt
    HugeInt operator +(int ) const ; // hugeInt + int
    HugeInt operator + (const string &) const ; // hugeInt +string


    /* Prefix and postfix operations to be performed */
    HugeInt &operator++(); // prefix increment operator
    HugeInt operator++( int ); // postfix increment operator

    // comparisons operations to be performed
    bool operator >=(HugeInt h1 ); // // hugeInt >= HugeInt
    bool operator >=(int int1 ); // // hugeInt >= int
    bool operator >=(string str1 ); // // hugeInt >= string
    int getSize();

private:
    short integer[digits];
    HugeInt helpIncrement();


};

#endif // HUGEINT_H
