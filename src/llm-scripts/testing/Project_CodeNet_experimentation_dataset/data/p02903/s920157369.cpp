#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	/*

	A
	001111B
	001111
	110000
	110000
	110000

	*/
	int H, W, A, B;
	scanf("%d %d %d %d", &H, &W, &A, &B);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if ((i < B) ^ (j < A)) {
				cout << 1;
			} else {
				cout << 0;
			}
		}
		cout << "\n";
	}
	return 0;
}