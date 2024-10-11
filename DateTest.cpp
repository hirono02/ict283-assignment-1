/**
 * Author: Chan Jia Hao Isaac
 * Student ID: 35433331
 * Date: 9/10/24
 */

#include "Date.h"
#include <iostream>

void DateTest1(); // Test default constructor and getter methods
void DateTest2(); // Test parameterized constructor and getter methods
void DateTest3(); // Test setDay method
void DateTest4(); // Test setDay with invalid input
void DateTest5(); // Test setMonth method
void DateTest6(); // Test setMonth with invalid input
void DateTest7(); // Test setYear method

int DateTest() {
    std::cout << "Date Test Program" << std::endl << std::endl;

    DateTest1();
    DateTest2();
    DateTest3();
    DateTest4();
    DateTest5();
    DateTest6();
    DateTest7();

    std::cout << std::endl;
    return 0;
}

int main() {
    DateTest();
    return 0;
}

void DateTest1() {
    // Test default constructor and getter methods
    Date defaultDate;
    std::cout << "Test One: Default Constructor" << std::endl;
    std::cout << "Expected day: 1, Actual day: " << defaultDate.getDay() << std::endl;
    std::cout << "Expected month: 1, Actual month: " << defaultDate.getMonth() << std::endl;
    std::cout << "Expected year: 2024, Actual year: " << defaultDate.getYear() << std::endl;
    std::cout << std::endl;
}

void DateTest2() {
    // Test parameterized constructor and getter methods
    Date customDate(15, 8, 2023);
    std::cout << "Test Two: Parameterized Constructor" << std::endl;
    std::cout << "Expected day: 15, Actual day: " << customDate.getDay() << std::endl;
    std::cout << "Expected month: 8, Actual month: " << customDate.getMonth() << std::endl;
    std::cout << "Expected year: 2023, Actual year: " << customDate.getYear() << std::endl;
    std::cout << std::endl;
}

void DateTest3() {
    // Test setDay method
    Date customDate(15, 8, 2023);
    customDate.setDay(20);
    std::cout << "Test Three: setDay Method" << std::endl;
    std::cout << "Expected day: 20, Actual day: " << customDate.getDay() << std::endl;
    std::cout << std::endl;
}

void DateTest4() {
    // Test setDay with invalid input
    Date customDate(15, 8, 2023);
    customDate.setDay(32); // Invalid day
    std::cout << "Test Four: Invalid setDay" << std::endl;
    std::cout << "Expected day: 15 (unchanged), Actual day: " << customDate.getDay() << std::endl;
    std::cout << std::endl;
}

void DateTest5() {
    // Test setMonth method
    Date customDate(15, 8, 2023);
    customDate.setMonth(12);
    std::cout << "Test Five: setMonth Method" << std::endl;
    std::cout << "Expected month: 12, Actual month: " << customDate.getMonth() << std::endl;
    std::cout << std::endl;
}

void DateTest6() {
    // Test setMonth with invalid input
    Date customDate(15, 8, 2023);
    customDate.setMonth(13); // Invalid month
    std::cout << "Test Six: Invalid setMonth" << std::endl;
    std::cout << "Expected month: 8 (unchanged), Actual month: " << customDate.getMonth() << std::endl;
    std::cout << std::endl;
}

void DateTest7() {
    // Test setYear method
    Date customDate(15, 8, 2023);
    customDate.setYear(1999);
    std::cout << "Test Seven: setYear Method" << std::endl;
    std::cout << "Expected year: 1999, Actual year: " << customDate.getYear() << std::endl;
    std::cout << std::endl;
}
