#include <iostream>

using namespace std;

int main(){
	unsigned long long int n;
	cin >> n;
	cout << endl << 1 << " ";
	unsigned int counter = 2;
	for(unsigned long long int i = 2; i < n; i ++){
		if(n % i == 0){
			cout << i << " ";
			counter ++;
		}
	}
	cout << n << endl;
	cout << "There are " << counter << " dividers." << endl;
	return 0;
}
