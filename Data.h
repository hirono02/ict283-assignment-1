/**
 * Author: Chan Jia Hao Isaac
 * Student ID: 35433331
 * Date: 9/10/24
 */

#ifndef DATA_H
#define DATA_H

#include "Date.h"
#include "Time.h"

/**
 * @brief A structure to represent meteorological data (wind speed, temperature, solar radiation)
 *        for a given date and time.
 */
struct Data {
    Date date;
    Time time;
    float windSpeed;        // Wind speed in km/h
    float temperature;      // Temperature in Celsius
    float solarRadiation;   // Solar radiation in kWh/m²

    Data() {
        windSpeed = 0.0f;
        temperature = 0.0f;
        solarRadiation = 0.0f;
    }

    Data(const Date& d, const Time& t, float wind, float temp, float solar) {
        date = d;
        time = t;
        windSpeed = wind;
        temperature = temp;
        solarRadiation = solar;
    }
};

#endif
