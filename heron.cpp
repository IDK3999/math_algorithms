#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

// Simplifies sqrt(n) into k * sqrt(m), where m is square-free.
long long simplify_sqrt(long long n, long long &m) {
    long long k = 1;
    m = n;
    for (long long p = 2; p * p <= m; p++) {
        while (m % (p * p) == 0) {
            m /= (p * p);
            k *= p;
        }
    }
    return k;
}

// Parses a value that can be a plain number ("4", "2.5"),
// a bare radical ("sqrt(3)"), or a coefficient times a radical ("4*sqrt(3)").
double parse_value(const string &raw) {
    string s;
    for (char ch : raw) if (!isspace((unsigned char)ch)) s += ch;

    size_t pos = s.find("sqrt(");
    if (pos == string::npos) {
        return stod(s);
    }

    double coeff = 1.0;
    string coeffStr = s.substr(0, pos);
    if (!coeffStr.empty() && coeffStr.back() == '*') coeffStr.pop_back();
    if (!coeffStr.empty()) coeff = stod(coeffStr);

    size_t start = pos + 5; // length of "sqrt("
    size_t end = s.find(')', start);
    if (end == string::npos) {
        throw invalid_argument("Malformed sqrt expression: missing ')'");
    }
    string inside = s.substr(start, end - start);
    double radicand = stod(inside);

    return coeff * sqrt(radicand);
}

int main() {
    string aStr, bStr, cStr;
    cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> aStr >> bStr >> cStr;

    double a, b, c;
    try {
        a = parse_value(aStr);
        b = parse_value(bStr);
        c = parse_value(cStr);
    } catch (const exception &e) {
        cout << "Invalid input: " << e.what() << endl;
        return 1;
    }

    if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a) {
        cout << "Invalid triangle." << endl;
        return 1;
    }

    double s = (a + b + c) / 2.0;
    double areaSquared = s * (s - a) * (s - b) * (s - c);

    // Convert areaSquared to a rational (num/den) to simplify its square root
    long long num = llround(areaSquared * 1000000);
    long long den = 1000000;
    long long g = gcd(num, den);
    num /= g;
    den /= g;

    long long product = num * den;
    long long m;
    long long k = simplify_sqrt(product, m);

    long long kg = gcd(k, den);
    long long k_num = k / kg;
    long long k_den = den / kg;

    cout << "The area of the triangle is: ";
    if (m == 1) {
        if (k_den == 1)
            cout << k_num << endl;
        else
            cout << (double)k_num / k_den << endl;
    } else {
        if (k_num == 1 && k_den == 1)
            cout << "sqrt(" << m << ")" << endl;
        else if (k_den == 1)
            cout << k_num << " * sqrt(" << m << ")" << endl;
        else if (k_num == 1)
            cout << "sqrt(" << m << ") / " << k_den << endl;
        else
            cout << k_num << " * sqrt(" << m << ") / " << k_den << endl;
    }

    return 0;
}
