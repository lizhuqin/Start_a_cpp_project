#include "hello_world.h"
#include "for_test/for_test.h"
#include <iostream>

int main() {
    hello_world();
    std::cout << "Sum of 3 and 5: " << Sum(3, 5) << std::endl;
    std::cout << "Is 7 odd? " << (IsOdd(7) ? "Yes" : "No") << std::endl;
    return 0;
}