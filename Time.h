/**
 * Author: Chan Jia Hao Isaac
 * Student ID: 35433331
 * Date: 9/10/24
 */

#ifndef TIME_H
#define TIME_H

/**
 * @brief A class to represent time in hours, minutes, and seconds.
 */
class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    /**
     * @brief Default constructor initializes the time to 00:00:00.
     */
    Time();

    /**
     * @brief Parameterized constructor to initialize time.
     * 
     * @param h Hours
     * @param m Minutes
     * @param s Seconds
     */
    Time(int h, int m, int s);

    /**
     * @brief Set the time value.
     * 
     * @param h Hours
     * @param m Minutes
     * @param s Seconds
     */
    void setTime(int h, int m, int s);

    /**
     * @brief Displays the time in HH:MM:SS format.
     */
    void display() const;

    /**
     * @brief Overload the less-than operator for time comparison.
     * 
     * @param t Another Time object to compare with.
     * @return true If this time is earlier than the other.
     * @return false Otherwise.
     */
    bool operator<(const Time& t) const;

    /**
     * @brief Overload the equality operator for time comparison.
     * 
     * @param t Another Time object to compare with.
     * @return true If the times are equal.
     * @return false Otherwise.
     */
    bool operator==(const Time& t) const;
};

#endif
