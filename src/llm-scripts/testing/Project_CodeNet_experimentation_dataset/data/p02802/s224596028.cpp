#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	ll ansAC = 0;
	ll ansWA = 0;
	vector<bool> usedAC(n, false);
	vector<int> cntWA(n, 0);
	for (int i = 0; i < m; i++) {
		int p; string s; cin >> p >> s;
		--p;
		if (s == "AC") {
			if (usedAC[p]) {}
			else {
				usedAC[p] = true;
				ansAC++;
			}
		}
		else { // s == "WA" 
			if (usedAC[p]) {}
			else {
				cntWA[p]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (usedAC[i]) ansWA += cntWA[i];
	}
	cout << ansAC << " " << ansWA << endl;
	return 0;
}