#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void test_default_constructor() {
    Array<int> defaultArray;
    std::cout << "Default constructor test passed. Size: " << defaultArray.size() << std::endl;
}

void test_parameterized_constructor() {
    Array<int> paramArray(MAX_VAL);
    std::cout << "Parameterized constructor test passed. Size: " << paramArray.size() << std::endl;
}

void test_copy_constructor() {
    Array<int> original(MAX_VAL);
    for (size_t i = 0; i < MAX_VAL; i++) {
        original[i] = i;
    }
    Array<int> copy(original);
    bool passed = true;
    for (size_t i = 0; i < MAX_VAL; i++) {
        if (original[i] != copy[i]) {
            passed = false;
            break;
        }
    }
    std::cout << (passed ? "Copy constructor test passed." : "Copy constructor test failed.") << std::endl;
}

void test_assignment_operator() {
    Array<int> array1(MAX_VAL);
    for (size_t i = 0; i < MAX_VAL; i++) {
        array1[i] = i;
    }
    Array<int> array2;
    array2 = array1;
    bool passed = true;
    for (size_t i = 0; i < MAX_VAL; i++) {
        if (array1[i] != array2[i]) {
            passed = false;
            break;
        }
    }
    std::cout << (passed ? "Assignment operator test passed." : "Assignment operator test failed.") << std::endl;
}

void test_element_access() {
    Array<int> array(MAX_VAL);
    for (size_t i = 0; i < MAX_VAL; i++) {
        array[i] = i;
    }
    bool passed = true;
    for (size_t i = 0; i < MAX_VAL; i++) {
        if (array[i] != static_cast<int>(i)) {
            passed = false;
            break;
        }
    }
    std::cout << (passed ? "Element access test passed." : "Element access test failed.") << std::endl;
}

void test_out_of_range_access() {
    Array<int> array(MAX_VAL);
    try {
        array[MAX_VAL] = 0;
        std::cout << "Out of range access test failed." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range access test passed. Exception: " << e.what() << std::endl;
    }
    try {
        array[-1] = 0;
        std::cout << "Out of range access test failed." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Out of range access test passed. Exception: " << e.what() << std::endl;
    }
}

void test_all() {
    std::cout << "Testing default constructor..." << std::endl;
    test_default_constructor();
    
    std::cout << "Testing parameterized constructor..." << std::endl;
    test_parameterized_constructor();
    
    std::cout << "Testing copy constructor..." << std::endl;
    test_copy_constructor();
    
    std::cout << "Testing assignment operator..." << std::endl;
    test_assignment_operator();
    
    std::cout << "Testing element access..." << std::endl;
    test_element_access();
    
    std::cout << "Testing out of range access..." << std::endl;
    test_out_of_range_access();
}

int main() {
    test_all();
    return 0;
}

