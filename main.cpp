#include "fizzBuzz.hpp"

#include <iostream>

int main() {
    std::cout << "Calling fizzBuzz with arguments from 0 to 100:\n";
    constexpr size_t upperLoopLimit = 100;
    for(size_t i = 0; i < upperLoopLimit; ++i) {
        std::cout << fizzBuzz(i) << '\n';
    }
    return 0;
}