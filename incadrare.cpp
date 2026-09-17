#include <iostream>
#include <string.h>

using namespace std;

void pozitiv(int produs, int i){

	if(i * i == produs)
		cout << endl << "The number is natural.\n";

	else
		cout << i - 1 << " < [INSERTED NUMBER] < " << i << "\n";
}

void negativ(int produs, int i){

	if(i * i == -produs)
		cout << endl << "The number is the negative of a natural number.\n";

	else
		cout << -(i - 1) << " > [INSERTED NUMBER] > " << -i << "\n";
}

int main(){
	int n, produs = 1;
	cout << "Insert factors on the same line, then any letter to continue: ";
	while(cin >> n)
		produs *= n;

	int i = 1;
	while(i * i <= produs)
		i ++;

	if(produs > 0)
		pozitiv(produs, i);

	else if(produs < 0)
		negativ(produs, i);

	else
		cout << "The number is zero.\n";

	return 0;
}
