//
//  date class

//

#include <iostream>
#include <string>

//
class Date {

    //
    public:

        //
        Date();
        Date(Date &date);

        //
        int getDay();
        std::string getMonth();
        int getYear();
        void addDay();
        friend std::ostream& operator<< (std::ostream &os, Date &date);

    //
    private:

        //
        std::string months[] = {
            "Januray",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "September",
            "October",
            "November",
            "December"
        };

        //
        int day;
        int month;
        int year;

};

//
Date::Date() {}

Date::Date(Date &date) {
    this = date;
}

//
int Date::getDay() { return day; }
std::string Date::getMonth() { return months[++month]; }
int Date::getYear() { return year; }

//
std::ostream& operator<<(std::ostream &ostream, Date &date) {
    return ostream  << date.getDay() << " "  
                    << date.getMonth() << " " 
                    << date.getYear(); 
}

