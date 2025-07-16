#include <bits/stdc++.h>
using namespace std;

int D;
int d[22];
long long ans;

bool analyze(int ndig) {
	int tmp = D;
	for (int i = ndig; i >= 1; --i) {
		d[i] = tmp % 10; tmp /= 10;
	}
	return tmp == 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> D;
	for (int ndig = 2; ndig <= 20; ++ndig) {
		bool odd = ndig % 2;
		if (!analyze(ndig)) continue;
			
		long long cur = 1; // current answer
		// d[1], d[2], ..., d[ndig]
		bool lef = 0 /* -> */, rig = 0 /* <- */;
		for (int dig = 1; dig <= ndig / 2; ++dig) {
			bool nlef = 0, nrig = 0;
			bool LEF = 0, RIG = 0;
			// opposite: ndig + 1 - dig
			int npair = 0;
			for (int i = 0; i <= 9; ++i) {
				for (int j = 0; j <= 9; ++j) {
					// check for validity
					if (dig == 1) {
						if (j == 0) continue;
						if (i < j) continue;
					}

					// I - J ~ [d[dig] + 1, d[dig]]
					// J - I = d[n + 1 - dig] || 10 + J - I = d[n + 1 - dig]
					int I = i, J = j;
					if (lef) I += 10; if (rig) --J;
					
					if (I - j == d[dig]) nlef = 0;
					else if (I - j == d[dig] + 1) nlef = 1;
					else continue;
					
					if (J - i == d[ndig + 1 - dig]) nrig = 0;
					else if (10 + J - i == d[ndig + 1 - dig]) nrig = 1;
					else continue;

					// now valid
					++npair;
					LEF = nlef;
					RIG = nrig;
				}
			}
			cur *= npair;
			lef = LEF;
			rig = RIG;
		}
		if (!odd && lef != rig) continue;
		else if (odd) {
			int cnt = 0;
			for (int i = 0; i <= 9; ++i) {
				int I = i;
				if (lef) I += 10;
				if (rig) I--;
				if (I - i == d[(ndig + 1) / 2]) ++cnt;
			}
			cur *= cnt;
		}
		ans += cur;
	}

	cout << ans << endl;
}