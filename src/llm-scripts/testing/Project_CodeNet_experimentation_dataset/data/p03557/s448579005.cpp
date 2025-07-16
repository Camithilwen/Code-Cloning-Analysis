#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> A(n), B(n), C(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> C[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	long long b[n]; fill(b, b+n, 0);
	long long c[n]; fill(c, c+n, 0);
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && A[j] < B[i]) j++;
		b[i] = j;
	}
	for (int i = 1; i < n; i++) {
		b[i] += b[i-1];
	}
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && B[j] < C[i]) j++;
		if (j == 0) {c[i] = 0; continue;}
		c[i] = b[j-1];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) ans += c[i];
	cout << ans << endl;
	return 0;
}