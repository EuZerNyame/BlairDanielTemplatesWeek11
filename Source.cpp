#include <iostream>
#include <type_traits>
// Templated function to return half of the value
template<typename T>
T half(T value) {
    // Check if T is a floating-point type
    if constexpr (std::is_floating_point<T>::value) {
        return value / 2;
    }
    else {
        // For non-floating point types, perform integer division
        return value / 2;
    }
}
int main() {
    // Testing the half function with different numeric types
    // Floating-point tests
    float fValue = 10.5f;
    double dValue = 20.0;
    std::cout << "Half of " << fValue << " (float) = " << half(fValue) << std::endl;
    std::cout << "Half of " << dValue << " (double) = " << half(dValue) << std::endl;
    // Integer tests
    int iValue = 10;
    long lValue = 100L;
    std::cout << "Half of " << iValue << " (int) = " << half(iValue) << std::endl;
    std::cout << "Half of " << lValue << " (long) = " << half(lValue) << std::endl;
    return 0;
}