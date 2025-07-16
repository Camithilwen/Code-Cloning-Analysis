#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
int h[10] = { 6,2,5,5,4,5,6,3,7,6 };
bool b[10] = { false };
int dp[10100][10];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		b[a] = true;
	}
	for (int i = 0; i < n + 10; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 0;
	}
	for (int i = 0; i <= n; i++) {
		if (dp[i][0] == -1) {
			continue;
		}
		for (int j = 1; j < 10; j++) {
			if (!b[j]) {
				continue;
			}
			if (dp[i + h[j]][0] == -1) {
				for (int k = 0; k < 10; k++) {
					dp[i + h[j]][k] = dp[i][k];
					if (j == k) {
						dp[i + h[j]][k]++;
					}
				}
			}
			else {
				int kari[10];
				int sl = 0, sr = 0;
				for (int k = 0; k < 10; k++) {
					kari[k] = dp[i][k];
					if (j == k) {
						kari[k]++;
					}
					sl += dp[i + h[j]][k];
					sr += kari[k];
				}
				bool bo = true;
				if (sl != sr) {
					if (sl > sr) {
						bo = false;
					}
				}
				else {
					int l = 9, r = 9;
					while (1) {
						if (l == 0 && r == 0) {
							bo = false;
							break;
						}
						if (dp[i + h[j]][l] == 0) {
							l--;
							continue;
						}
						if (kari[r] == 0) {
							r--;
							continue;
						}
						if (l == r && dp[i + h[j]][l] == kari[r]) {
							l--;
							r--;
							continue;
						}
						else if (l < r) {
							break;
						}
						else if (l > r) {
							bo = false;
							break;
						}
						else if (dp[i + h[j]][l] < kari[r]) {
							break;
						}
						else if (dp[i + h[j]][l] > kari[r]) {
							bo = false;
							break;
						}
					}
				}
				if (bo) {
					for (int k = 0; k < 10; k++) {
						dp[i + h[j]][k] = kari[k];
					}
				}
			}
		}
	}
	for (int i = 9; i > 0; i--) {
		for (int j = 0; j < dp[n][i]; j++) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
