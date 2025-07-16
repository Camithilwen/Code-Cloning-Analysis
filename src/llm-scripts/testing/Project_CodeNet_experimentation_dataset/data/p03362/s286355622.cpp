#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	vector<bool> v(55555 + 1);
	for (int i = 2; i < v.size(); i++) {
		if (!v.at(i)) {
			for (int j = i * 2; j < v.size(); j += i) {
				v.at(j) = true;
			}
		}
	}

	vector<int> a;
	for (int i = 2; i < v.size(); i++) {
		if (!v.at(i)) {
			if (i % 5 == 1) a.push_back(i);
		}
	}

	for (int i = 0; i < N; i++) {
		if (i) cout << ' ';
		cout << a.at(i);
	}
	cout << endl;
}