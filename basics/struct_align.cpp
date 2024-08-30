#include <iostream>
#include <cstdint>
#include <type_traits>  // For alignof

struct Info {
    uint8_t a;
    uint8_t c;
    uint16_t b;
};

struct alignas(4) Info2 {
    uint8_t a;
    uint8_t c;
    uint16_t b;
};

int main() {
    std::cout << "sizeof(Info): " << sizeof(Info) << std::endl;   // Expected: 6
    std::cout << "alignof(Info): " << alignof(Info) << std::endl;  // Expected: 2

    std::cout << "sizeof(Info2): " << sizeof(Info2) << std::endl;   // Expected: 8
    std::cout << "alignof(Info2): " << alignof(Info2) << std::endl;  // Expected: 4
    return 0;
}