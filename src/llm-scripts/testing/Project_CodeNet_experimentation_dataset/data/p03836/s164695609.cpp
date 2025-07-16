#include <bits/stdc++.h>
using namespace std;

int main() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	string res = "";
	for (int i = sy; i < ty; i++) {
		res += 'U';
	}
	for (int i = sx; i < tx; i++) {
		res += 'R';
	}
	for (int i = sy; i < ty; i++) {
		res += 'D';
	}
	for (int i = sx; i < tx; i++) {
		res += 'L';
	}
	res += 'L';
	for (int i = sy; i < ty + 1; i++) {
		res += 'U';
	}
	for (int i = sx; i < tx + 1; i++) {
		res += 'R';
	}
	res += 'D';
	res += 'R';
	for (int i = sy; i < ty + 1; i++) {
		res += 'D';
	}
	for (int i = sx; i < tx + 1; i++) {
		res += 'L';
	}
	res += 'U';
	cout << res;
	return 0;
}