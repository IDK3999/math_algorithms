#include <iostream>
#include <algorithm> // for the __gcd function
using namespace std;

int main(){
    int n; // number of elements in the set
    cin >> n;

    int a[n]; // array of elements in the set
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int cmmdc = a[0]; // initialize gcd with the first element
    for(int i = 1; i < n; i++)
        cmmdc = __gcd(cmmdc, a[i]); // compute gcd using __gcd
    cout << cmmdc << endl; // print the gcd
}
