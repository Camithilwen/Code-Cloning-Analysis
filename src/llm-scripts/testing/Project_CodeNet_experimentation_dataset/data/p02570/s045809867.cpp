#include<iostream>
using namespace std;

int main() {
	int D, T, S;
	cin >> D >> T >> S;
	int A = S * T;
	
	if (A >= D) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	return 0;
}