#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int A, B;
	string S;
	int check = 1;
	cin >> A >> B >> S;
	for (int i = 0; i < A; i++) {
		if (S[i] < 48) check = 0;
	}
	if (S[A] != '-') check = 0;
	for (int i = A + 1; i < B + A + 1; i++) {
		if (S[i] < 48) check = 0;
	}
	if (check == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}