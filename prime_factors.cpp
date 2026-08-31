#include <iostream>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;

    for (unsigned long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int exp = 0;
            while (n % p == 0) {
                n /= p;
                exp++;
            }
            cout << p << "^" << exp << endl;
        }
    }
    if (n > 1)
        cout << n << "^1" << endl;

    return 0;
}
