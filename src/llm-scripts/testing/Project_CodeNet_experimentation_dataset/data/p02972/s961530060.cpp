#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	int N; cin >> N;
	vector<int> a(N + 1);
	for(int i = 1; i <= N; i++) cin >> a[i];
	set<int> b;
	for(int i = N; i > 0; i--) {
		int sum = 0;
		for(int j = i + i; j <= N; j += i) {
			if(b.count(j)) sum++;
		}
		if(sum % 2 != a[i]) b.insert(i);
	}
	int M = b.size();
	int cnt = 0;
	cout << M << endl;
	for(auto p: b) {
		cnt++;
		if(cnt == b.size()) {
			cout << p << endl;
			return 0;
		}
		cout << p << " ";
	}
}