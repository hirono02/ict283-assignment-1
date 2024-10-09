/**
 * Author: Chan Jia Hao Isaac
 * Student ID: 35433331
 * Date: 9/10/24
 */

#include "Time.h"
#include <iostream>

/**
 * @brief Default constructor initializes the time to 00:00:00.
 */
Time::Time() : hours(0), minutes(0), seconds(0) {}

/**
 * @brief Parameterized constructor to initialize time.
 * 
 * @param h Hours
 * @param m Minutes
 * @param s Seconds
 */
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

/**
 * @brief Set the time value.
 * 
 * @param h Hours
 * @param m Minutes
 * @param s Seconds
 */
void Time::setTime(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
}

/**
 * @brief Displays the time in HH:MM:SS format.
 */
void Time::display() const {
    std::cout << (hours < 10 ? "0" : "") << hours << ":"
              << (minutes < 10 ? "0" : "") << minutes << ":"
              << (seconds < 10 ? "0" : "") << seconds << std::endl;
}

/**
 * @brief Overload the less-than operator for time comparison.
 * 
 * @param t Another Time object to compare with.
 * @return true If this time is earlier than the other.
 * @return false Otherwise.
 */
bool Time::operator<(const Time& t) const {
    if (hours != t.hours) return hours < t.hours;
    if (minutes != t.minutes) return minutes < t.minutes;
    return seconds < t.seconds;
}

/**
 * @brief Overload the equality operator for time comparison.
 * 
 * @param t Another Time object to compare with.
 * @return true If the times are equal.
 * @return false Otherwise.
 */
bool Time::operator==(const Time& t) const {
    return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
}
