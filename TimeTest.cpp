#include "Time.h"
#include <iostream>

/*
 * TimeTest1: tests the default constructor and verifies that it initializes the time to 00:00:00.
 * 
 * TimeTest2: tests the parameterized constructor such that it correctly sets the time to the given values.
 * 
 * TimeTest3: tests the comparison operators (specifically the < operator) to verify proper time comparison.
 * 
 * TimeTest4: tests the setTime method and checks that it correctly updates the time values.
 * 
 * TimeTest5: tests the '==' operator (==)  to ensure it correctness in comparing two Time objects.
 */

void TimeTest1(); 
void TimeTest2(); 
void TimeTest3(); 
void TimeTest4(); 
void TimeTest5(); 

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
int main() {
    TimeTest();
    return 0;
}

void TimeTest1() {
    // test default constructor and display
    Time t;
    std::cout << "Test One: Default Constructor" << std::endl;
    t.display();  // expected output: 00:00:00
    std::cout << std::endl;
}

void TimeTest2() {
    // test parameterized constructor and display
    Time t(14, 45, 30);
    std::cout << "Test Two: Parameterized Constructor" << std::endl;
    t.display();  // expected output: 14:45:30
    std::cout << std::endl;
}

void TimeTest3() {
    // test comparison operators
    Time t1(12, 30, 45);
    Time t2(14, 30, 45);
    std::cout << "Test Three: Comparison Operators" << std::endl;
    if (t1 < t2) {
        std::cout << "t1 is earlier than t2" << std::endl; // expected print statement
    }
    std::cout << std::endl;
}

void TimeTest4() {
    // test setTime method and display
    Time t;
    std::cout << "Test Four: Set Time" << std::endl;
    t.setTime(9, 15, 0);
    t.display();  // expected output: 09:15:00
    std::cout << std::endl;
}

void TimeTest5() {
    // test equality operator
    Time t1(10, 10, 10);
    Time t2(10, 10, 10);
    std::cout << "Test Five: Equality Operator" << std::endl;
    if (t1 == t2) {
        std::cout << "t1 is equal to t2" << std::endl;  // expected print statement
    }
    std::cout << std::endl;
}
