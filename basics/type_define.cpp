#include <iostream>

// Using typedef
typedef char * p_char_typedef;
p_char_typedef a, b, c;

// Using #define
#define p_char_define char *
p_char_define x, y, z;

int main() {
    // All of these are of type 'char*'
    a = nullptr;
    b = nullptr;
    c = nullptr;

    // Only 'x' is of type 'char*'
    // 'y' and 'z' are of type 'char'
    x = nullptr;
    y = 1;
    z = 2;
    // y and z cannot be assigned nullptr because they are not pointers

    std::cout << "All typedef variables are pointers: " << std::endl;
    std::cout << "a: " << static_cast<void*>(a) << std::endl;
    std::cout << "b: " << static_cast<void*>(b) << std::endl;
    std::cout << "c: " << static_cast<void*>(c) << std::endl;

    std::cout << "Only the first define variable is a pointer: " << std::endl;
    std::cout << "x: " << static_cast<void*>(x) << std::endl;
    // std::cout << "y: " << y << std::endl; // Error: 'y' is not a pointer
    // std::cout << "z: " << z << std::endl; // Error: 'z' is not a pointer

    return 0;
}