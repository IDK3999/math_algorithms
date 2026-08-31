#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

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

// Prints sqrt(input_str) in simplified radical form,
// where input_str represents a non-negative number (possibly decimal).
void print_sqrt(const string &input) {
    long long num, den = 1;
    size_t dot = input.find('.');
    if (dot == string::npos) {
        num = stoll(input);
    } else {
        string int_part = input.substr(0, dot);
        string frac_part = input.substr(dot + 1);
        long long d = frac_part.size();
        for (long long i = 0; i < d; i++) den *= 10;
        long long int_val = int_part.empty() ? 0 : stoll(int_part);
        num = int_val * den + stoll(frac_part);
    }

    if (num == 0) {
        cout << 0 << endl;
        return;
    }

    long long g = gcd(num, den);
    num /= g;
    den /= g;

    long long product = num * den;
    long long m;
    long long k = simplify_sqrt(product, m);

    long long kg = gcd(k, den);
    long long k_num = k / kg;
    long long k_den = den / kg;

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
}

// Formats a double as a decimal string, trimming trailing zeros.
string format_double(double value) {
    ostringstream oss;
    oss.precision(9);
    oss << fixed << value;
    string s = oss.str();

    // Trim trailing zeros
    size_t dot = s.find('.');
    if (dot != string::npos) {
        size_t last = s.find_last_not_of('0');
        if (last == dot) last--; // remove trailing dot too
        s.erase(last + 1);
    }
    return s;
}

// Parses a value that can be a plain number ("4", "2.5"),
// a bare radical ("sqrt(3)"), or a coefficient times a radical ("4*sqrt(3)").
double parse_value(const string &raw) {
    // Remove whitespace
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
    string bStr, cStr, angleStr;

    cout << "b = ";
    cin >> bStr;

    cout << "c = ";
    cin >> cStr;

    cout << "angle (degrees) = ";
    cin >> angleStr;

    double b, c, angleDegrees;
    try {
        b = parse_value(bStr);
        c = parse_value(cStr);
        angleDegrees = parse_value(angleStr);
    } catch (const exception &e) {
        cout << "Invalid input: " << e.what() << endl;
        return 1;
    }

    double angleRadians = angleDegrees * M_PI / 180.0;
    double aSquared = b * b + c * c - 2 * b * c * cos(angleRadians);

    if (aSquared < 0) {
        cout << "Invalid triangle (a^2 < 0)." << endl;
        return 1;
    }

    string aSquaredStr = format_double(aSquared);

    cout << "a = ";
    print_sqrt(aSquaredStr);

    return 0;
}