#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

// Simplifies sqrt(n) into k * sqrt(m), where m is square-free.
// Returns k (the coefficient) and sets m (the radicand).
long long simplify_sqrt(long long n, long long &m) {
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

int main() {
    string input;
    cout << "n = ";
    cin >> input;

    if (!input.empty() && input[0] == '-') {
        cout << "The number must be positive." << endl;
        return 1;
    }

    // Parse input as fraction num/den (e.g. "0.25" -> 25/100)
    long long num, den = 1;
    size_t dot = input.find('.');
    if (dot == string::npos) {
        num = stoll(input);
    } else {
        string int_part = input.substr(0, dot);
        string frac_part = input.substr(dot + 1);
        long long d = frac_part.size();
        for (long long i = 0; i < d; i++) den *= 10;
        num = stoll(int_part) * den + stoll(frac_part);
    }

    if (num == 0) {
        cout << "sqrt(0) = 0" << endl;
        return 0;
    }

    // Reduce fraction num/den
    long long g = gcd(num, den);
    num /= g;
    den /= g;

    // sqrt(num/den) = sqrt(num*den) / den
    long long product = num * den;
    long long m;
    long long k = simplify_sqrt(product, m);

    // Coefficient is k/den; simplify it
    long long kg = gcd(k, den);
    long long k_num = k / kg;
    long long k_den = den / kg;

    cout << "sqrt(" << input << ") = ";
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
