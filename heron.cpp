#include <iostream>
#include <cmath>
using namespace std;

long long simplify_sqrt(double n, long long &m) {
    long long k = 1;
    m = n;
    // Extract square factors by trial division
    for (long long p = 2; p * p <= m; p++) {
        while (m % (p * p) == 0) {
            m /= (p * p);
            k *= p;
        }
    }
    return k;
}

int main(){
    double a, b, c;
    cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> a >> b >> c;
    double s = (a + b + c) / 2.0;
    double area = s * (s - a) * (s - b) * (s - c);

    long long exponent = 0;

    area = simplify_sqrt(area, exponent);
    if(exponent != 1)
    	cout << "The area of the triangle is: " << area << " * sqrt(" << exponent << ")" << endl;
    else
	cout << "The area of the triangle is: " << area << endl;
    return 0;
}
