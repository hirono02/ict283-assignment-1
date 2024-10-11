#include "DataProcessor.h"
#include "Data.h"
#include "Vector.h"
#include <iostream>
#include <fstream>

/**
 * @brief Displays the menu options to the user.
 */
void showMenu();

/**
 * @brief Handles the option to calculate the average wind speed and standard deviation for a specified month and year.
 * @param data The vector containing the meteorological data.
 */
void option1(const Vector<Data> &data);

/**
 * @brief Handles the option to calculate the average temperature and standard deviation for each month of a specified year.
 * @param data The vector containing the meteorological data.
 */
void option2(const Vector<Data> &data);

/**
 * @brief Handles the option to calculate the total solar radiation for each month of a specified year.
 * @param data The vector containing the meteorological data.
 */
void option3(const Vector<Data> &data);

/**
 * @brief Handles the option to export wind speed, temperature, and solar radiation statistics to a CSV file.
 * @param data The vector containing the meteorological data.
 */
void option4(const Vector<Data> &data);

int main()
{
    Vector<Data> data;
    std::string dataFile;

    // load file name from data source
    std::ifstream file("data_source.txt");
    if (!file)
    {
        std::cerr << "Error: Unable to open data_source.txt" << std::endl;
        return 1;
    }
    
    // read file name 
    file >> dataFile;
    file.close();

    // load file data
    std::cout << "Loading Data" << std::endl;
    DataProcessor::loadData(dataFile, data);

    int choice;
    do
    {
        showMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            option1(data);
            break;
        case 2:
            option2(data);
            break;
        case 3:
            option3(data);
            break;
        case 4:
            option4(data);
            break;
        case 5:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void showMenu()
{
    std::cout << "Menu:\n";
    std::cout << "1. The average wind speed and sample standard deviation for this wind speed given a specified month and year.\n";
    std::cout << "2. Average ambient air temperature and sample standard deviation for each month of a specified year.\n";
    std::cout << "3. Total solar radiation in kWh/m2 for each month of a specified year.\n";
    std::cout << "4. Average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year.\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void option1(const Vector<Data> &data)
{
    int month, year;

    // validate month
    while (true)
    {
        std::cout << "Please enter a month (1-12): ";
        if (std::cin >> month && month >= 1 && month <= 12)
        {
            // If input is valid and within range, break out of the loop
            break;
        }
        // clear error 
        std::cin.clear();
        // clear input from input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 12." << std::endl;
    }

    std::cout << "Enter year: ";
    std::cin >> year;

    float avg, stdev;
    if (DataProcessor::calculateWindStats(data, month, year, avg, stdev))
    {
        std::cout << "Average wind speed: " << avg << " km/h\n";
        std::cout << "Standard deviation: " << stdev << "\n";
    }
    else
    {
        std::cout << "No data for " << month << "/" << year << "\n";
    }
}

void option2(const Vector<Data> &data)
{
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;

    for (int month = 1; month <= 12; ++month)
    {
        float avg, stdev;
        if (DataProcessor::calculateTemperatureStats(data, month, year, avg, stdev))
        {
            std::cout << "Month " << month << ": Average temperature: " << avg << "°C, Std Dev: " << stdev << "\n";
        }
        else
        {
            std::cout << "Month " << month << ": No data\n";
        }
    }
}

void option3(const Vector<Data> &data)
{
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;

    for (int month = 1; month <= 12; ++month)
    {
        float totalSolar;
        if (DataProcessor::calculateSolarStats(data, month, year, totalSolar))
        {
            std::cout << "Month " << month << ": Total solar radiation: " << totalSolar << " kWh/m²\n";
        }
        else
        {
            std::cout << "Month " << month << ": No data\n";
        }
    }
}

void option4(const Vector<Data> &data)
{
    int year;
    std::cout << "Enter year: ";
    std::cin >> year;

    std::ofstream outFile("WindTempSolar.csv");
    if (!outFile)
    {
        std::cerr << "Error: Could not open WindTempSolar.csv for writing.\n";
        return;
    }

    outFile << "Year,Month,Average Wind Speed (km/h),Std Dev,Average Temperature (C),Std Dev,Solar Radiation (kWh/m²)\n";
    outFile << year << "\n";

    bool hasData = false;
    for (int month = 1; month <= 12; ++month)
    {
        float avgWind, stdevWind, avgTemp, stdevTemp, totalSolar;

        bool windExists = DataProcessor::calculateWindStats(data, month, year, avgWind, stdevWind);
        bool tempExists = DataProcessor::calculateTemperatureStats(data, month, year, avgTemp, stdevTemp);
        bool solarExists = DataProcessor::calculateSolarStats(data, month, year, totalSolar);

        if (windExists || tempExists || solarExists)
        {
            outFile << month << ",";
            if (windExists)
            {
                outFile << avgWind << "(" << stdevWind << "),";
            }
            else
            {
                outFile << ",";
            }
            if (tempExists)
            {
                outFile << avgTemp << "(" << stdevTemp << "),";
            }
            else
            {
                outFile << ",";
            }
            if (solarExists)
            {
                outFile << totalSolar;
            }
            outFile << "\n";
            hasData = true;
        }
    }

    if (!hasData)
    {
        outFile << "No Data\n";
    }

    outFile.close();
    std::cout << "Data exported to WindTempSolar.csv\n";
}
