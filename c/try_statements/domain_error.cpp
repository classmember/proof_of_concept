#include <stdexcept>
#include <iostream>
#include <cmath>
#include <string>
#include <new>
#include <climits>

void test_sqrt() {
    float answer = 0;
    try {
        answer = sqrt(-2);
    } catch(...) {
        std::cout << "Exception!\n";
    }
    std::cout << "test_sqrt()  |  "
              << "sqrt(-2) = "
              << answer
              << "\n";
}

void test_cast() {
    std::string not_a_number = "0";
    try {
        not_a_number;
    } catch(...) {
        std::cout << "Exception!\n";
    }
    std::cout << "test_cast()  |  "
              << "increment string \"0\" : "
              << "error"
              << "\n";
}

void test_bad_alloc() {
    int* myarray;
    long long int huge = ULLONG_MAX;
    std::string error = "";
    try {
        myarray = new int[huge];
        int* ay = new int[huge];
    } catch(std::bad_alloc& e) {
        error += "bad_alloc caught: ";
        error += e.what();
    } catch(...) {
        std::cout << "General exception caught!";
    }
    std::cout << "test_bad_alloc()  |  "
              << "myarray = new int[10000] : "
              << error
              << "\n";
}

int main() {
    std::cout << "Testing try...catch blocks.\n";
    test_sqrt();
    test_cast();
    test_bad_alloc();
}
