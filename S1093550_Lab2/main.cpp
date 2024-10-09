/* Creating and comparing Time Class Objects*/
#include <iostream>
#include <iomanip>
using namespace std;

// Time class declaration
class Time
{
    public:
    Time(); // constructor, the name must be the same as class name
    void setTime( int, int, int ); // set hour, minute and second
    void printUniversal(); // print time in universal-time format
    void printStandard(); // print time in standard-time format
    void setT1toT2(Time);// added
    void compareTime(Time t2);// added
    private:
    int hour; // 0 - 23 (24-hour clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
};


void Time::compareTime(Time t2){

    if(t2.hour > hour) cout << "Later" << endl;
        else if (t2.hour == hour){
                    if (t2.minute > minute) cout << "Later" << endl ;
                    else if (t2.minute < minute) cout << "Early" << endl ;
                    else{
                            if(t2.second > second)cout << "Later" << endl;
                            else if (t2.second < second) cout << "Early" << endl ;
                            else cout << "\nSame" << endl ;
                    }


        }else cout << "Early" << endl ;


};

void Time::setT1toT2(Time t2){

    hour = t2.hour;
    minute = t2.minute;
    second = t2.second;
}

// Time constructor initializes each data member to zero.
// Ensures all Time objects start in a consistent state.
Time::Time() { // :: is called scope operator

    hour = minute = second = 0;
} // end Time constructor


// set new Time value using universal time; ensure that
// the data remains consistent by setting invalid values to zero

void Time::setTime( int h, int m, int s ) {

    hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
    minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
    second = ( s >= 0 && s < 60 ) ? s : 0; // validate second

} // end function setTime

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() {

    cout << "\nUniversal Time: " << setfill( '0' ) << setw( 2 ) << hour << ":" << setw( 2 ) << minute << ":" << setw( 2 ) << second;

}


// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard(){

    cout <<  "\nStandard Time: " << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":" << setfill( '0' ) << setw( 2 ) << minute << ":" << setw( 2 ) << second << ( hour < 12 ? " AM" : " PM" );
}

int main()
{
    Time t;
    Time t1,t2; //#######
    Time* tPtr; //#######
    tPtr = &t;  //#######
    Time& tRef = t; //#######



    // output Time object t's initial values
    t.printUniversal(); // 00:00:00
    t.printStandard(); // 12:00:00 AM

    t.setTime( 18, 20, 0 ); //#######

    // output Time object t's new values
   //    using object name as a handle
    t.printUniversal();
    t.printStandard();

    // output Time object t's new values
   // using object reference as a handle
    tRef.printUniversal();
    tRef.printStandard();


    // output Time object t's new values
   // using object pointer as a handle
    tPtr->printUniversal();
    tPtr->printStandard();


    t1.setTime( 13, 27, 6 ); // set a new time

    // output Time object t1's new values
    t1.printUniversal(); // 13:27:06
    t1.printStandard(); // 1:27:06 PM



    t2.setTime( 9, 9, 9); //*******************
    // output t2's values after specifying invalid values
    t2.printUniversal(); //*******************
    t2.printStandard();//*******************


    Time t3;
    t3.setT1toT2(t2);
    t3.compareTime(t2);
    t2.compareTime(t1);
    t1.compareTime(t);
    t.compareTime(t1);
}

