#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, Q;
	string S;
	cin >> N >> S >> Q;
	for (int i = 0; i < Q; i++) {
		long long K;
		cin >> K;
		long long CurX = 0, CurY = 0, COUNT = 0, ANS = 0;
		vector<long long> MCOUNT(N, 0);
		for (int j = 0; j < N; j++) {
			if (S[j] == 'D') CurX++;
			if (S[j] == 'M') CurY++;
			if (S[j] == 'M') COUNT += CurX;
			if (j - K >= 0) {
				if (S[j - K] == 'M') CurY--;
				if (S[j - K] == 'D') COUNT -= CurY, CurX--;
			}
			if (S[j] == 'C') ANS += COUNT;
		}
		cout << ANS << endl;
	}
}