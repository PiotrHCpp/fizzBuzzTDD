#include "fizzBuzz.hpp"

#include <stdexcept>
#include <string>

std::string fizzBuzz(unsigned argument) {
    if(100 < argument) {
        throw std::out_of_range("argument is out of range (>100)");
    }
    if(0 == argument) {
        return "0";
    }
    const bool valueIsMultipleOf3 = (0 == (argument % 3));
    const bool valueIsMultipleOf5 = (0 == (argument % 5));
    if(valueIsMultipleOf3 && valueIsMultipleOf5) {
        return "FizzBuzz";
    }
    if(valueIsMultipleOf3) {
        return "Fizz";
    }
    if(valueIsMultipleOf5) {
        return "Buzz";
    }
    return std::to_string(argument);
}
