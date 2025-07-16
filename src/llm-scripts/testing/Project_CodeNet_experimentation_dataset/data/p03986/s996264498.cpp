#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	string x;
	cin >> x;
	int n = x.size();

	stack<char> s;
	int cnt = 0;
	rep(i,n) {
		if (x[i] == 'S') s.push(x[i]);
		if (x[i] == 'T' && s.empty()) s.push(x[i]);
		if (x[i] == 'T' && s.top() == 'S') {
			s.pop();
			cnt += 2;
		}
	} 
	cout << n-cnt << endl;
	return 0;
}