#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;

int main() {fio;
	string s;
	cin >> s;
	vector <int> cnt(26, 0);
	ll sm = 0, ans = 0;
	for(int i = 0; i < 26; i++) {
		cnt[i] = count(all(s), 'a' + i);
		ans += sm * cnt[i];
		sm += cnt[i];
	}
	cout << ans + 1 << endl;
    return 0;
}