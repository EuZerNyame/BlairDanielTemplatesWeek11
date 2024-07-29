/*
 * This program defines a templated function 'half' that calculates and returns half of
 * a given value. For floating-point types (float, double), it directly returns half of the
 * value. For integer types (int, long), it returns half of the value rounded according
 * to usual rounding rules. The main function allows the user to input their own test
 * values and demonstrates the function's behavior.
 */
#include <iostream>
#include <type_traits>
#include <cmath>
using namespace std;
// Templated function to return half of the value
template<typename T>
T half(T value) {
    if constexpr (is_floating_point<T>::value) {
        // For floating-point types, return half of the value
        return value / 2;
    }
    else if constexpr (is_integral<T>::value) {
        // For integer types, return half with rounding
        return static_cast<T>(round(value / 2.0));
    }
    else {
        static_assert(always_false<T>::value, "Unsupported type");
    }
}
// Helper struct to create a static_assert for unsupported types
template<class T>
struct always_false : false_type {};
int main() {
    // Variables for user input
    char type;
    cout << "Enter type (f for float, d for double, i for int, l for long): ";
    cin >> type;
    if (type == 'f') {
        float value;
        cout << "Enter a float value: ";
        cin >> value;
        cout << "Half of " << value << " (float) = " << half(value) << endl;
    }
    else if (type == 'd') {
        double value;
        cout << "Enter a double value: ";
        cin >> value;
        cout << "Half of " << value << " (double) = " << half(value) << endl;
    }
    else if (type == 'i') {
        int value;
        cout << "Enter an int value: ";
        cin >> value;
        cout << "Half of " << value << " (int) = " << half(value) << endl;
    }
    else if (type == 'l') {
        long value;
        cout << "Enter a long value: ";
        cin >> value;
        cout << "Half of " << value << " (long) = " << half(value) << endl;
    }
    else {
        cout << "Unsupported type!" << endl;
    }

    return 0;
}