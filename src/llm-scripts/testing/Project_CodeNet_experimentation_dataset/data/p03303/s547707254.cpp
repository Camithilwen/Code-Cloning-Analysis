#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string S;
	int w;
	cin >> S >> w;

	for (int i = 0; i < S.size(); i+=w) {
		cout << S.at(i);
	}
	cout << endl;
}