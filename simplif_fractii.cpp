#include <iostream>

using namespace std;

int main(){
    long long int a, b;
    cin >> a >> b;
    int i = 1;
    while(i <= a && i <= b){
	i ++;
        if(a % i == 0 && b % i == 0){
            a /= i;
            b /= i;
            cout << "Simplifying by " << i << " gives " << a << "/" << b << endl;
            i = 1;
        }
    }
    cout << "Final fraction: " << a << "/" << b << endl;
    return 0;
}
