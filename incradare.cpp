#include <iostream>
#include <string.h>

using namespace std;

int main(){
	int n, produs = 1;
	cout << "Insert factors on the same line, then any letter to continue: ";
	while(cin >> n)
		produs *= n;

	int i = 1;
	while(i * i <= produs)
		i ++;

	if(i * i == produs)
		cout << endl << "The number is natural.\n";

	else
		cout << i - 1 << " < [INSERTED NUMBER] < " << i << "\n";

	return 0;
}
