#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int total = 0;
	if (A >= B) {
		total += A;
		A -= 1;
	}
	else {
		total += B;
		B -= 1;
	}
	if (A >= B) {
		total += A;
		A -= 1;
	}
	else {
		total += B;
		B -= 1;
	}

	cout << total << endl;

}



