#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    /*
        Pre: real number x
        Post: mathematical function f(x)
    */
    return sin(x)*x;
}

double simpsonIntegral(double a, double b, int n) {
    /*
        Pre: limits a,b and real number n (the number of parts that is divided the interval [a,b])
        Post: aproximation of the integral of function f(x) in interval [a,b] with the Simpson method
    */

    double Part = a, E = f(a) + f(b), S = 0, P = 0, h = (b-a)/n;

    for(int i = 1; i <= n-1; i++) {
        Part += h;
        if(i % 2 != 0) {
            S += f(Part);
        } else {
            P += f(Part);
        }
    }

    return (h/3)*(E + 4*S + 2*P);

}

double trapezoidIntegral(double a, double b, int n) {
    /*
        Pre: limits a,b and real number n (the number of parts that is divided the interval [a,b])
        Post: aproximation of the integral of function f(x) in interval [a,b] with the Trapezoid method
    */

    double Part = a, E = f(a) + f(b), P = 0, h = (b-a)/n;

    for(int i = 1; i <= n-1; i++) {
        Part += h;
        P += f(Part);
    }

    return (h/2)*(E + 2*P);

}

int main() {
    // examples of use
    double resultSimpson = simpsonIntegral(0,2,10);
    double resultTrapezoid = trapezoidIntegral(0,2,10);
    cout << resultSimpson << endl << resultTrapezoid;
    return 0;
}