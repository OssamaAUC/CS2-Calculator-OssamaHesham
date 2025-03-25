#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <ctime>
#include "calculator.h"

void displayMenu() {
    cout << "\nCalculator Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Factorial\n";
    cout << "6. GCD (Greatest Common Divisor)\n";
    cout << "7. LCM (Least Common Multiple)\n";
    cout << "8. Random Number Generation\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}



double getNumber(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        if (cin >> num) {
            break;
        } else {
            cout << "Invalid input. Please enter a number.\n";
        
        }
    }
  
    return num;
}

int getPositiveInteger(const string& prompt) {
    int num;
    while (true) {
        num = static_cast<int>(getNumber(prompt));
        if (num >= 0) {
            break;
        }
        cout << "Please enter a non-negative integer.\n";
    }
    return num;
}

int main() {
    cout << "Welcome to the Interactive Calculator!\n";
    
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
    
    int choice;
    do {
        displayMenu();
        
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
        
            displayMenu();
        }
    
        
        switch (choice) {
            case 1: {
                double a = getNumber("Enter first number: ");
                double b = getNumber("Enter second number: ");
                cout << "Result: " << Calculator::add(a, b) << "\n";
                break;
            }
            case 2: {
                double a = getNumber("Enter first number: ");
                double b = getNumber("Enter second number: ");
                cout << "Result: " << Calculator::subtract(a, b) << "\n";
                break;
            }
            case 3: {
                double a = getNumber("Enter first number: ");
                double b = getNumber("Enter second number: ");
                cout << "Result: " << Calculator::multiply(a, b) << "\n";
                break;
            }
            case 4: { 
                double a = getNumber("Enter numerator: ");
                double b = getNumber("Enter denominator: ");
                try {
                    cout << "Result: " << Calculator::divide(a, b) << "\n";
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 5: { 
                int n = getPositiveInteger("Enter a non-negative integer: ");
                try {
                    cout << "Result: " << Calculator::factorial(n) << "\n";
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 6: {
                int a = getPositiveInteger("Enter first number: ");
                int b = getPositiveInteger("Enter second number: ");
                cout << "Result: " << Calculator::gcd(a, b) << "\n";
                break;
            }
            case 7: { 
                int a = getPositiveInteger("Enter first number: ");
                int b = getPositiveInteger("Enter second number: ");
                cout << "Result: " << Calculator::lcm(a, b) << "\n";
                break;
            }
            case 8: { 
                int min = static_cast<int>(getNumber("Enter minimum value: "));
                int max = static_cast<int>(getNumber("Enter maximum value: "));
                if (min > max) {
                    swap(min, max);
                    cout << "Note: Swapped min and max values.\n";
                }
                cout << "Random number: " << Calculator::random(min, max) << "\n";
                break;
            }
            case 0: 
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
    } while (choice != 0);
    
    return 0;
}