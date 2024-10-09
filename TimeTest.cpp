// TimeTest.cpp
// See how the calls are arranged
// Comment each call to indicate what is being tested

#include "Time.h"
#include <iostream>

void TimeTest1(); // Test Time default constructor and display
void TimeTest2(); // Test Time parameterized constructor and display
void TimeTest3(); // Test Time comparison operators
void TimeTest4(); // Test setting time and display
void TimeTest5(); // Test equality of two Time objects

int TimeTest() {
    std::cout << "Time Test Program" << std::endl << std::endl;

    TimeTest1();
    TimeTest2();
    TimeTest3();
    TimeTest4();
    TimeTest5();

    std::cout << std::endl;
    return 0;
}

void TimeTest1() {
    // Test default constructor and display
    Time t;
    std::cout << "Test One: Default Constructor" << std::endl;
    t.display();  // Expected output: 00:00:00
    std::cout << std::endl;
}

void TimeTest2() {
    // Test parameterized constructor and display
    Time t(14, 45, 30);
    std::cout << "Test Two: Parameterized Constructor" << std::endl;
    t.display();  // Expected output: 14:45:30
    std::cout << std::endl;
}

void TimeTest3() {
    // Test comparison operators
    Time t1(12, 30, 45);
    Time t2(14, 30, 45);
    std::cout << "Test Three: Comparison Operators" << std::endl;
    if (t1 < t2) {
        std::cout << "t1 is earlier than t2" << std::endl; // Expected
    }
    std::cout << std::endl;
}

void TimeTest4() {
    // Test setTime method and display
    Time t;
    std::cout << "Test Four: Set Time" << std::endl;
    t.setTime(9, 15, 0);
    t.display();  // Expected output: 09:15:00
    std::cout << std::endl;
}

void TimeTest5() {
    // Test equality operator
    Time t1(10, 10, 10);
    Time t2(10, 10, 10);
    std::cout << "Test Five: Equality Operator" << std::endl;
    if (t1 == t2) {
        std::cout << "t1 is equal to t2" << std::endl;  // Expected
    }
    std::cout << std::endl;
}
