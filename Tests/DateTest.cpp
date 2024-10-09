/**
 * Author: Chan Jia Hao Isaac
 * Student ID: 35433331
 * Date: 9/10/24
 */

#include "../Headers/Date.h"
#include <iostream>

/**
 * @brief This is a manual test for the Date class without using assert.
 * It tests default constructor, parameterized constructor, and getter/setter
 * methods to ensure the Date class behaves as expected.
 */
int main() {
    // Test default constructor
    const Date defaultDate;
    std::cout << "Testing default constructor..." << std::endl;
    std::cout << "Expected day: 1, Actual day: " << defaultDate.getDay() << std::endl;
    std::cout << "Expected month: 1, Actual month: " << defaultDate.getMonth() << std::endl;
    std::cout << "Expected year: 2024, Actual year: " << defaultDate.getYear() << std::endl;

    if (defaultDate.getDay() == 1 && defaultDate.getMonth() == 1 && defaultDate.getYear() == 2024) {
        std::cout << "Default constructor test passed.\n" << std::endl;
    } else {
        std::cout << "Default constructor test failed.\n" << std::endl;
    }

    // Test parameterized constructor
    Date customDate(15, 8, 2023);
    std::cout << "Testing parameterized constructor..." << std::endl;
    std::cout << "Expected day: 15, Actual day: " << customDate.getDay() << std::endl;
    std::cout << "Expected month: 8, Actual month: " << customDate.getMonth() << std::endl;
    std::cout << "Expected year: 2023, Actual year: " << customDate.getYear() << std::endl;

    if (customDate.getDay() == 15 && customDate.getMonth() == 8 && customDate.getYear() == 2023) {
        std::cout << "Parameterized constructor test passed.\n" << std::endl;
    } else {
        std::cout << "Parameterized constructor test failed.\n" << std::endl;
    }

    // Test setDay method
    std::cout << "Testing setDay method..." << std::endl;
    customDate.setDay(20);
    std::cout << "Expected day: 20, Actual day: " << customDate.getDay() << std::endl;
    if (customDate.getDay() == 20) {
        std::cout << "setDay test passed.\n" << std::endl;
    } else {
        std::cout << "setDay test failed.\n" << std::endl;
    }

    customDate.setDay(32);  // Invalid value, should not change
    std::cout << "Expected day: 20 (unchanged), Actual day: " << customDate.getDay() << std::endl;
    if (customDate.getDay() == 20) {
        std::cout << "setDay invalid value test passed.\n" << std::endl;
    } else {
        std::cout << "setDay invalid value test failed.\n" << std::endl;
    }

    // Test setMonth method
    std::cout << "Testing setMonth method..." << std::endl;
    customDate.setMonth(12);
    std::cout << "Expected month: 12, Actual month: " << customDate.getMonth() << std::endl;
    if (customDate.getMonth() == 12) {
        std::cout << "setMonth test passed.\n" << std::endl;
    } else {
        std::cout << "setMonth test failed.\n" << std::endl;
    }

    customDate.setMonth(13);  // Invalid value, should not change
    std::cout << "Expected month: 12 (unchanged), Actual month: " << customDate.getMonth() << std::endl;
    if (customDate.getMonth() == 12) {
        std::cout << "setMonth invalid value test passed.\n" << std::endl;
    } else {
        std::cout << "setMonth invalid value test failed.\n" << std::endl;
    }

    // Test setYear method
    std::cout << "Testing setYear method..." << std::endl;
    customDate.setYear(1999);
    std::cout << "Expected year: 1999, Actual year: " << customDate.getYear() << std::endl;
    if (customDate.getYear() == 1999) {
        std::cout << "setYear test passed.\n" << std::endl;
    } else {
        std::cout << "setYear test failed.\n" << std::endl;
    }

    return 0;
}
