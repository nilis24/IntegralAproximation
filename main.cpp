#include <iostream>
#include <cmath>

using namespace std;

const double TWO = 2.0;
const double THREE = 3.0;

double f(double x) {
    // Pre: real number x
    // Post: mathematical function f(x)
    return sin(x) * x;
}

double simpsonIntegral(double a, double b, int n) {
    // Pre: limits a, b and real number n (the number of parts that divide the interval [a, b])
    // Post: approximation of the integral of function f(x) in the interval [a, b] with the Simpson method

    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i <= n - 1; i++) {
        double x = a + i * h;
        result += (i % 2 == 0) ? TWO * f(x) : THREE * f(x);
    }

    return (h / THREE) * result;
}

double trapezoidIntegral(double a, double b, int n) {
    // Pre: limits a, b and real number n (the number of parts that divide the interval [a, b])
    // Post: approximation of the integral of function f(x) in the interval [a, b] with the Trapezoid method

    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i <= n - 1; i++) {
        double x = a + i * h;
        result += TWO * f(x);
    }

    return (h / TWO) * result;
}

int main() {
    int choice;
    double a, b;
    int n;

    cout << "Enter the limits of integration [a, b]: ";
    cin >> a >> b;

    cout << "Enter the number of subintervals (n): ";
    cin >> n;

    cout << "Select the integration method:" << endl;
    cout << "1. Simpson's Method" << endl;
    cout << "2. Trapezoid Method" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    double result;

    switch (choice) {
        case 1:
            result = simpsonIntegral(a, b, n);
            cout << "Simpson Integral: " << result << endl;
            break;
        case 2:
            result = trapezoidIntegral(a, b, n);
            cout << "Trapezoid Integral: " << result << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            return 1; // Return an error code
    }

    return 0;
}
