//bayemirov                                       
#include <bits/stdc++.h>
 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
 
#define pb push_back
 
const int MOD = 1e9 + 7;
const int N = 1e5;
 
int dp[N][100];
 
void add(int& x, int y) {
	x += y;
	if (x > MOD) x -= MOD;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string a;
	cin >> a;
	int b;
	cin >> b;
	int k = a.size();
	dp[0][0] = 1;
	for (int i = 1; i < k; i++) 
		for (int j = 0; j < b; j++) 
			for(int x = 0; x < 10; ++x)
				add(dp[i][j], dp[i - 1][((j - x) % b + b) % b]);
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < (a[i] - '0'); j++)
			add(ans, dp[k - i - 1][((b - sum - j) % b + b) % b]);
		sum += (a[i] - '0');
		sum %= b;
	}
	if(sum == 0)
		ans++;
	cout << ans - 1;
	return 0;
}                    
// ez