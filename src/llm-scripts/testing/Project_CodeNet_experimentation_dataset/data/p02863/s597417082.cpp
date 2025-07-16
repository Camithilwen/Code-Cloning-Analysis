#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N  = 3009;
int N, T;
int A[MAX_N], B[MAX_N];
int dp[MAX_N][MAX_N];

void solve()
{
	vector<pair<int,int>> v;
	for(int i=0;i<N;++i) v.emplace_back(A[i],B[i]);
	sort(v.begin(),v.end());
	for(int i=0;i<N;++i){
		int ti = v[i].first, de = v[i].second;
		for(int t=0;t<=T;++t){
		    dp[i+1][t]=max(dp[i+1][t],dp[i][t]);
			if(t<T)dp[i+1][min(T,t+ti)]=max(dp[i+1][min(T,t+ti)], de+dp[i][t]);
		}
	}
	int ans = dp[N][T];
	cout<<ans;
}

int main()
{
	cin >> N >> T;
	for(int i=0;i<N;++i) cin >> A[i] >> B[i];
	solve();
	return 0;
}