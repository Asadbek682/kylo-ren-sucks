#include <iostream>

// Compile-time factorial using template metaprogramming
template<int N>
struct Factorial {
    static const int value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0> {
    static const int value = 1;
};

// Constexpr function (C++11/14 alternative)
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    // Compile-time computation
    std::cout << "Factorial of 5 (template): " << Factorial<5>::value << std::endl;
    
    // Constexpr computation
    constexpr int fact = factorial(5);
    std::cout << "Factorial of 5 (constexpr): " << fact << std::endl;
    
    return 0;
}
