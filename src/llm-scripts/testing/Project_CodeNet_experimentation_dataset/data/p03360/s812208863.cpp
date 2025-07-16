#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B, C, K;
	cin >> A >> B >> C >> K;

	vector<int> v(3);
	v.at(0) = A;
	v.at(1) = B;
	v.at(2) = C;
	sort(v.begin(), v.end());

	int n = v.back();
	while (K) {
		n *= 2;
		K--;
	}

	cout << v.at(0) + v.at(1) + n << endl;
}