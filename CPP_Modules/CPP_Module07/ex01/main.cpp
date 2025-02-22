#include "iter.hpp"
#include <iostream>

// Example function to be applied to each element
template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

// Another example function to be applied to each element
template <typename T>
void incrementElement(T& element) {
    ++element;
}

int main() {
    // Test with an array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    unsigned int intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incremented int array: ";
    iter(intArray, intArrayLength, incrementElement<int>);
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    // Test with an array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Original double array: ";
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;

    std::cout << "Incremented double array: ";
    iter(doubleArray, doubleArrayLength, incrementElement<double>);
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;

    return 0;
}