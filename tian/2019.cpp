#include <iostream>

template<typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    int i = 1;
    int j = 2;
    double x = 1.5;
    double y = 2.5;
    std::cout << sum(i, j) << std::endl; // prints 3
    std::cout << sum(x, y) << std::endl; // prints 4 (NOT 4.0)
    std::cout << sum<int8_t>(x, y) - 4 << std::endl; // prints 4 (NOT 4.0)
    std::cout << sum<uint8_t>(x, y) - 4 << std::endl; // prints 4 (NOT 4.0)

    /*
    std::cout << sum(i, x) << std::endl;
//  error: no matching function for call to ‘sum(int&, double&)’
//  note:   template argument deduction/substitution failed:
//  note:   deduced conflicting types for parameter ‘T’ (‘int’ and ‘double’)
    */

    return 0;
}