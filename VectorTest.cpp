// VectorTest.cpp
// See how the calls are arranged
// Comment each call to indicate what is being tested

#include "Vector.h"
#include <iostream>

void Test1(); // Test Vector default size and push_back
void Test2(); // Test Vector resizing mechanism
void Test3(); // Test Vector element access
void Test4(); // Test Vector boundary conditions
void Test5(); // Test Vector size reporting

int VectorTest() {
    std::cout << "Vector Test Program" << std::endl << std::endl;

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    std::cout << std::endl;
    return 0;
}

void Test1() {
    // Test Vector default size and push_back
    Vector<int> v(2);
    std::cout << "Test One: Default size and push_back" << std::endl;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    std::cout << "Expected: 10 20 30" << std::endl;
    for (int i = 0; i < v.getSize(); i++) {
        std::cout << v[i] << " ";  // Expected output: 10 20 30
    }
    std::cout << std::endl << std::endl;
}

void Test2() {
    // Test Vector resizing mechanism
    Vector<int> v(2);
    std::cout << "Test Two: Resizing mechanism" << std::endl;
    for (int i = 0; i < 5; i++) {
        v.push_back(i + 1);
    }
    std::cout << "Expected: 1 2 3 4 5" << std::endl;
    for (int i = 0; i < v.getSize(); i++) {
        std::cout << v[i] << " ";  // Expected output: 1 2 3 4 5
    }
    std::cout << std::endl << std::endl;
}

void Test3() {
    // Test Vector element access
    Vector<int> v(3);
    v.push_back(50);
    v.push_back(60);
    std::cout << "Test Three: Element access" << std::endl;
    std::cout << "Element at index 1: " << v[1] << std::endl;  // Expected output: 60
    std::cout << std::endl;
}

void Test4() {
    // Test Vector boundary conditions
    Vector<int> v(2);
    v.push_back(5);
    std::cout << "Test Four: Boundary condition" << std::endl;
    try {
        std::cout << v[2] << std::endl;  // Expected: throw out_of_range
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;  // Expected: Index out of range
    }
    std::cout << std::endl;
}

void Test5() {
    // Test Vector size reporting
    Vector<int> v(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::cout << "Test Five: Vector size" << std::endl;
    std::cout << "Vector size: " << v.getSize() << std::endl;  // Expected output: 3
    std::cout << std::endl;
}
