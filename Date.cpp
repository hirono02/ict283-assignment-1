/**
 * Author: Chan Jia Hao Isaac
 * Student ID: 35433331
 * Date: 9/10/24
 */

#include "Date.h"

// Default constructor initializes Date to 1/1/2024
Date::Date() {
    day = 1;
    month = 1;
    year = 2024;
}

// Parameterized constructor initializes Date to provided values
Date::Date(const int day, const int month, const int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

// Destructor
Date::~Date() {};

// Set and validate day
void Date::setDay(const int day) {
    if (day >= 1 && day <= 31) {
        this->day = day;
    } else {
        std::cout << "Invalid day. Setting day to 1." << std::endl;
        this->day = 1;
    }
}

// Get day
int Date::getDay() const {
    return day;
}

// Set and validate month
void Date::setMonth(const int month) {
    if (month >= 1 && month <= 12) {
        this->month = month;
    } else {
        std::cout << "Invalid month." << std::endl;
    }
}

// Get month
int Date::getMonth() const {
    return month;
}

// Set year
void Date::setYear(const int year) {
    this->year = year;
}

// Get year
int Date::getYear() const {
    return year;
}

// Output the date in format "DD/MM/YYYY"
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << (date.day < 10 ? "0" : "") << date.day << "/"
       << (date.month < 10 ? "0" : "") << date.month << "/"
       << date.year;
    return os;
}
