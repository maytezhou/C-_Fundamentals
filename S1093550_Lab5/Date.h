#ifndef  DATE_H
#define DATE_H

class Date {
    public:
    static const int monthsPerYear = 12;// number of months in a year
    Date(int = 1 , int = 1 ,int = 1900 );
    void print() const ;
    int compare ( const Date & d) const;
    Date& setDate ( int year, int month , int day );
    int getYear () const ;
    int getMonth() const ;
    int getDay() const ;

    ~Date();

    private:
    int month;
    int day ;
    int year;

    int checkDay(int ) const;

};

#endif
