#include "DataProcessor.h"
#include <cstdlib>  // For strtol and strtof

void DataProcessor::loadData(const std::string& filename, Vector<Data>& data) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;

    // Skip the header row
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string token;

        Date date;
        Time time;
        float windSpeed = 0, temperature = 0, solarRadiation = 0;

        // Parse the Date and Time (they are separated by space)
        std::getline(ss, token, ',');  // Read the full date and time token, e.g. "2/03/2014 17:20"
        
        // Find the space that separates the date and time
        std::size_t spacePos = token.find(' ');
        if (spacePos == std::string::npos) {
            std::cerr << "Error: Invalid date-time format in CSV: " << token << std::endl;
            continue;
        }

        std::string dateStr = token.substr(0, spacePos);  // Extract date part, e.g. "2/03/2014"
        std::string timeStr = token.substr(spacePos + 1); // Extract time part, e.g. "17:20"

        // Parse the Date (assuming format DD/MM/YYYY)
        const char* dateCStr = dateStr.c_str();
        char* endPtr;

        // Convert day
        int day = std::strtol(dateCStr, &endPtr, 10);
        if (*endPtr != '/' || day < 1 || day > 31) {
            std::cerr << "Error: Invalid day in CSV: " << dateStr << std::endl;
            continue;
        }

        // Convert month
        int month = std::strtol(endPtr + 1, &endPtr, 10);
        if (*endPtr != '/' || month < 1 || month > 12) {
            std::cerr << "Error: Invalid month in CSV: " << dateStr << std::endl;
            continue;
        }

        // Convert year
        int year = std::strtol(endPtr + 1, &endPtr, 10);
        if (year < 0) {
            std::cerr << "Error: Invalid year in CSV: " << dateStr << std::endl;
            continue;
        }

        date.setYear(year);
        date.setMonth(month);
        date.setDay(day);

        // Parse the Time (handle both H:MM and HH:MM formats)
        const char* timeCStr = timeStr.c_str();
        char* timeEndPtr;

        // Convert hour
        int hour = std::strtol(timeCStr, &timeEndPtr, 10);
        if (*timeEndPtr != ':' || hour < 0 || hour > 23) {
            std::cerr << "Error: Invalid hour in CSV: " << timeStr << std::endl;
            continue;
        }

        // Convert minute
        int minute = std::strtol(timeEndPtr + 1, &timeEndPtr, 10);
        if (*timeEndPtr != '\0' && *timeEndPtr != ' ') {
            std::cerr << "Error: Invalid minute in CSV: " << timeStr << std::endl;
            continue;
        }

        time.setTime(hour, minute, 0);

        // Parse Wind Speed (in m/s, convert to km/h)
        std::getline(ss, token, ',');
        windSpeed = convertWindSpeed(std::strtof(token.c_str(), &endPtr));
        if (*endPtr != '\0' && *endPtr != ' ') {
            std::cerr << "Error: Invalid wind speed in CSV: " << token << std::endl;
            continue;
        }

        // Parse Temperature (in Celsius)
        std::getline(ss, token, ',');
        temperature = std::strtof(token.c_str(), &endPtr);
        if (*endPtr != '\0' && *endPtr != ' ') {
            std::cerr << "Error: Invalid temperature in CSV: " << token << std::endl;
            continue;
        }

        // Parse Solar Radiation (in W/m², convert to kWh/m²)
        std::getline(ss, token, ',');
        solarRadiation = convertSolarRadiation(std::strtof(token.c_str(), &endPtr));
        if (*endPtr != '\0' && *endPtr != ' ') {
            std::cerr << "Error: Invalid solar radiation in CSV: " << token << std::endl;
            continue;
        }

        // Add the record to the data vector
        Data record(date, time, windSpeed, temperature, solarRadiation);
        data.push_back(record);
    }

    file.close();
}

float DataProcessor::convertWindSpeed(float speed)
{
    return speed * 3.6f; // Convert m/s to km/h
}

float DataProcessor::convertSolarRadiation(float radiation)
{
    return (radiation / 1000.0f) * (1.0f / 6.0f); // Convert W/m² (10 minutes) to kWh/m²
}

bool DataProcessor::calculateWindStats(const Vector<Data> &data, int month, int year, float &avg, float &stdev)
{
    float sum = 0.0f, sumSq = 0.0f;
    int count = 0;

    for (int i = 0; i < data.getSize(); i++)
    {
        if (data[i].date.getYear() == year && data[i].date.getMonth() == month)
        {
            sum += data[i].windSpeed;
            sumSq += data[i].windSpeed * data[i].windSpeed;
            count++;
        }
    }

    if (count == 0)
    {
        return false;
    }

    avg = sum / count;
    stdev = std::sqrt((sumSq / count) - (avg * avg));
    return true;
}

bool DataProcessor::calculateTemperatureStats(const Vector<Data> &data, int month, int year, float &avg, float &stdev)
{
    float sum = 0.0f, sumSq = 0.0f;
    int count = 0;

    for (int i = 0; i < data.getSize(); i++)
    {
        if (data[i].date.getYear() == year && data[i].date.getMonth() == month)
        {
            sum += data[i].temperature;
            sumSq += data[i].temperature * data[i].temperature;
            count++;
        }
    }

    if (count == 0)
    {
        return false;
    }

    avg = sum / count;
    stdev = std::sqrt((sumSq / count) - (avg * avg));
    return true;
}

bool DataProcessor::calculateSolarStats(const Vector<Data> &data, int month, int year, float &totalSolar)
{
    totalSolar = 0.0f;
    int count = 0;

    for (int i = 0; i < data.getSize(); i++)
    {
        if (data[i].date.getYear() == year && data[i].date.getMonth() == month)
        {
            totalSolar += data[i].solarRadiation;
            count++;
        }
    }

    return count > 0; // Return true if data was found, false otherwise
}
