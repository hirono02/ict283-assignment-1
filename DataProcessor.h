#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include "Vector.h"
#include "Data.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>

/**
 * @brief Helper functions to load, process, and calculate statistics on the meteorological data.
 */
class DataProcessor {
public:
    /**
     * @brief Reads the CSV file and stores the data into the given vector.
     * @param filename Name of the CSV file to read.
     * @param data Vector to store the loaded data.
     */
    static void loadData(const std::string& filename, Vector<Data>& data);

    /**
     * @brief Calculates the average and standard deviation for wind speed in a specified month and year.
     * @param data Vector of meteorological data.
     * @param month Month to filter data by.
     * @param year Year to filter data by.
     * @param avg Output parameter for the average wind speed.
     * @param stdev Output parameter for the wind speed standard deviation.
     * @return true if data was found, false otherwise.
     */
    static bool calculateWindStats(const Vector<Data>& data, int month, int year, float& avg, float& stdev);

    /**
     * @brief Calculates the average and standard deviation for temperature in a specified year.
     * @param data Vector of meteorological data.
     * @param year Year to filter data by.
     * @param month Month to filter data by.
     * @param avg Output parameter for the average temperature.
     * @param stdev Output parameter for the temperature standard deviation.
     * @return true if data was found, false otherwise.
     */
    static bool calculateTemperatureStats(const Vector<Data>& data, int month, int year, float& avg, float& stdev);

    /**
     * @brief Calculates the total solar radiation for a specified year and month.
     * @param data Vector of meteorological data.
     * @param month Month to filter data by.
     * @param year Year to filter data by.
     * @param totalSolar Output parameter for the total solar radiation.
     * @return true if data was found, false otherwise.
     */
    static bool calculateSolarStats(const Vector<Data>& data, int month, int year, float& totalSolar);

private:
    /**
     * @brief Helper function to convert m/s to km/h.
     * @param speed Speed in m/s.
     * @return Speed in km/h.
     */
    static float convertWindSpeed(float speed);

    /**
     * @brief Helper function to convert solar radiation from W/m² to kWh/m².
     * @param radiation Solar radiation in W/m².
     * @return Solar radiation in kWh/m².
     */
    static float convertSolarRadiation(float radiation);
};

#endif
