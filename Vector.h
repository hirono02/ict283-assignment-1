#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

/**
 * @brief Template class for a dynamic vector that resizes itself
 * when full, providing controlled access to elements.
 * 
 * @tparam T The type of elements stored in the vector.
 */
template <typename T>
class Vector {
private:
    T* arr;          ///< Pointer to the dynamic array
    int capacity;    ///< The total capacity of the vector
    int size;        ///< The current number of elements in the vector
    
    /**
     * @brief Resizes the internal array when it is full.
     */
    void resize();

public:
    /**
     * @brief Constructs a new Vector object with the given initial capacity.
     * 
     * @param initialCapacity The initial size of the vector. Defaults to 10.
     */
    Vector(int initialCapacity = 10);

    /**
     * @brief Destructor that cleans up dynamic memory.
     */
    ~Vector();

    /**
     * @brief Adds an element to the end of the vector, resizing if necessary.
     * 
     * @param value The value to add.
     */
    void push_back(const T& value);

    /**
     * @brief Non-const access to elements by index.
     * 
     * @param index The position of the element to access.
     * @return A reference to the element at the given index.
     */
    T& operator[](int index);

    /**
     * @brief Const access to elements by index for const objects.
     * 
     * @param index The position of the element to access.
     * @return A const reference to the element at the given index.
     */
    const T& operator[](int index) const;

    /**
     * @brief Gets the current size of the vector.
     * 
     * @return The number of elements currently in the vector.
     */
    int getSize() const;
};

template <typename T>
Vector<T>::Vector(int initialCapacity) {
    // set initial capacity
    capacity = initialCapacity;
    size = 0;
    // allocate memory
    arr = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() {
    // deallocate memory
    // std::cout << "Destructor called" << std::endl;
    delete[] arr;
}

template <typename T>
void Vector<T>::resize() {
    capacity *= 2;
    T* temp = new T[capacity];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    // check if vector capacity has been reached. if so, we will double the size of the vector
    if (size == capacity) {
        resize();
    }
    // add the value to the end of the vector
    arr[size++] = value;
}

template <typename T>
// overload [] to allow us to access elements by index
T& Vector<T>::operator[](int index) {
    // check if index out of bounds
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

/** READ ONLY ACCESS */
template <typename T>
const T& Vector<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T>
int Vector<T>::getSize() const {
    return size;
}

#endif
