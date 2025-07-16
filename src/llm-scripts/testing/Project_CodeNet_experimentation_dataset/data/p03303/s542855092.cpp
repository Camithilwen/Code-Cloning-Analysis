#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string S;
	int w;
	cin >> S >> w;
	rep(i, S.size()) {
		if (i % w == 0) {
			cout << S.at(i);
		}
	}
	cout << endl;
	return 0;
}