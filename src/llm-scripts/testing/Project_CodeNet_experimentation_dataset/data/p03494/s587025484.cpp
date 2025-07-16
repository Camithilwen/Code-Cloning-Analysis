#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int kai(int a) {
	int n = 0;
	while (1) {
		if (a % 2 == 0) {
			a = a / 2;
			n++;
		}
		else break;
	}
	return n;
}
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	int count = 100000;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		count = min(kai(A[i]), count);
	}
	cout << count << endl;
	return 0;
}