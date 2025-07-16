#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
int dp[3010][3010];

int main(){
	int n, time; scanf("%d %d", &n, &time);
	vector<P> a(n);
	for(int i = 0; i < n; i++) scanf("%d %d", &a[i].first, &a[i].second);
	sort(a.begin(), a.end());
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= time; j++){
			dp[i + 1][j] = dp[i][j];
			if(j - a[i].first >= 0) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - a[i].first] + a[i].second);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) ans = max(ans, dp[i][time - 1] + a[i].second);
	printf("%d\n", ans);
}