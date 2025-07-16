#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; int w; cin >> s >> w;
	string ans = "";
	for (int i = 0; i < s.size(); i+=w) {
		ans += s[i];
	}
	cout << ans << endl;
    return 0;
}