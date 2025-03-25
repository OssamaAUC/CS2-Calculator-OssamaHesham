#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    static double add(double a, double b);
    static double subtract(double a, double b);
    static double multiply(double a, double b);
    static double divide(double a, double b);
    
    static int factorial(int n);
    static int gcd(int a, int b);
    static int lcm(int a, int b);
    
    static int random(int min, int max);
};

#endif // CALCULATOR_H