/**
 * Author: Chan Jia Hao Isaac
 * Student ID: 35433331
 * Date: 9/10/24
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>

/**
 * @class Date
 * @brief A class to represent a Date with day, month, and year.
 */
class Date {
private:
 int day;    ///< Day of the month (1-31)
 int month;  ///< Month of the year (1-12)
 int year;   ///< Year in full (e.g., 2023)

public:
 /**
  * @brief Default constructor that initializes the date to 1/1/2000.
  */
 Date();

 /**
  * @brief Constructor that initializes the date to the provided values.
  * @param day The day of the month.
  * @param month The month of the year.
  * @param year The year.
  */
 Date(int day, int month, int year);

 /**
  * @brief Destructor for the Date class.
  */
 ~Date();

 /**
  * @brief Set the day.
  * @param day The day to set.
  */
 void setDay(int day);

 /**
  * @brief Get the day.
  * @return The day.
  */
 int getDay() const;

 /**
  * @brief Set the month.
  * @param month The month to set.
  */
 void setMonth(int month);

 /**
  * @brief Get the month.
  * @return The month.
  */
 int getMonth() const;

 /**
  * @brief Set the year.
  * @param year The year to set.
  */
 void setYear(int year);

 /**
  * @brief Get the year.
  * @return The year.
  */
 int getYear() const;

 /**
  * @brief Output the date in a readable format.
  * @param os The output stream.
  * @param date The date object to output.
  * @return The output stream with the date.
  */
 friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif // DATE_H
