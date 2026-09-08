#include <iostream>

using namespace std;

int main(){
    long long int a, b;

    cout << "Enter the top number: ";
    cin >> a;
    cout << "Enter the bottom number: ";
    cin >> b;
    cout << endl;
    
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
