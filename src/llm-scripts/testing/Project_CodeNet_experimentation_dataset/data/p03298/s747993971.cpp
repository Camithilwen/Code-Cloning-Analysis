#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<char> sL(n), sR(n);
	for (int i = 0; i < n; i++) {
		cin >> sL[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> sR[i];
	}

	map<pair<string, string>, int> mpL;
	for (int bit = 0; bit < 1<<n; bit++) {
		string reds = "", blues = "";
		for (int i = 0; i < n; i++) {
			if (bit & 1<<i) {
				reds.push_back(sL[i]);
			}
			else {
				blues.push_back(sL[i]);
			}
		}
		mpL[make_pair(reds, blues)]++;
	}

	long long ans = 0;
	for (int bit = 0; bit < 1<<n; bit++) {
		string reds = "", blues = "";
		for (int i = 0; i < n; i++) {
			if (bit & 1<<i) {
				reds.push_back(sR[i]);
			}
			else {
				blues.push_back(sR[i]);
			}
		}
		reverse(reds.begin(), reds.end());
		reverse(blues.begin(), blues.end());
		ans += mpL[make_pair(blues, reds)];
	}
	
	cout << ans << endl;
	return 0;
}
