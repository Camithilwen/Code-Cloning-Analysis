#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	string S;
	int LW = 0;
	int LE = 0;
	int RW = 0;
	int RE = 0;
	cin >> N >> S;
	for (int i = 1;i<N;++i) {
		if ('E' == S[i]) {
			RE++;
		}
		else {
			RW++;
		}
	}	
	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		ans = min(ans,LW+RE);
		if ('E' == S[i]) {
			LE++;
		}
		else {
			LW++;
		}
		if (i != N-1) {
			if ('E' == S[i + 1]) {
				RE--;
			}
			else {
				RW--;
			}
		}
	}
	cout <<ans << endl;
	return 0;
}