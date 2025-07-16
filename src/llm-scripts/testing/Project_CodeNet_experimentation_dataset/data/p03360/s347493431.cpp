#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int A, B, C;
	int K;
	cin >> A >> B >> C >> K;

	int maxNum = max({ A, max({ B, C }) });
	
	if (A == maxNum) {
		for (int i = 0; i < K; i++) {
			A =  2 * A;
		}
	}
	else if (B == maxNum) {
		for (int i = 0; i < K; i++) {
			B =  2 * B;
		}
	}
	else if (C == maxNum) {
		for (int i = 0; i < K; i++) {
			C =  2 * C;
		}
	}

	cout << A + B + C << endl;
}
	
