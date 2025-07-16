#include<cstdio>
#include<iostream>
#include <memory>
#include<vector>
#include<algorithm>
using namespace std;

int calc(int a, int b, int ope) {
	if (ope == 0) return a + b;
	else return a - b;
}

int main(void) {
	string S;
	cin >> S;
	char ope[] = {'+', '-'};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				int ans = calc(S[0] - '0', S[1] - '0', i);
				ans = calc(ans, S[2] - '0', j);
				ans = calc(ans, S[3] - '0', k);
				if (ans == 7) {
					cout << S[0] << ope[i] << S[1] << ope[j] << S[2] << ope[k] << S[3] << "=7\n";
					return 0;
				}
			}
		}
	}
	return 0;
}
