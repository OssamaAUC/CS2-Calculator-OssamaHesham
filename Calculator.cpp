#include "calculator.h"
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

double Calculator::add(double a, double b) { return a + b; }
double Calculator::subtract(double a, double b) { return a - b; }
double Calculator::multiply(double a, double b) { return a * b; }

double Calculator::divide(double a, double b) {
    if (b == 0) throw std::runtime_error("Division by zero");
    return a / b;
}

int Calculator::factorial(int n) {
    if (n < 0) throw std::runtime_error("Factorial of negative number");
    return (n == 0) ? 1 : n * factorial(n - 1);
}

int Calculator::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int Calculator::lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

int Calculator::random(int min, int max) {
    if (min > max) std::swap(min, max);
    return min + rand() % (max - min + 1);
}