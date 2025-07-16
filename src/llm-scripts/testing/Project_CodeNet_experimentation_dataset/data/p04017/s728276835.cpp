#include <bits/stdc++.h>

using namespace std;

int A[100050];
int n,l,q;
int dp[100050][20];
int main(){
	//freopen("input.in","r",stdin);
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> A[i];
	cin >> l;
	for(int i=1; i<=n; ++i) dp[i][0] = upper_bound(A+1,A+n+1,A[i]+l)-A-1;
	for(int k=1; k<=18; ++k){
		for(int i=1; i<=n; ++i){
			dp[i][k] = dp[dp[i][k-1]][k-1];
		}
	}
//	for(int k=0; k<=3; ++k){ for(int i=1; i<=n; ++i) printf("%d ", dp[i][k]); printf("\n"); }
	cin >> q;
	while(q--){
		int a, b; cin >> a >> b;
		if(a > b) swap(a,b);
		int ans = 0;
		while(a < b){
			int s=0,e=19,m;
			for(int k=0; k<=18; ++k) if(dp[a][k] < b) s=k;
			ans += (1<<s);
			a = dp[a][s];
		}
		cout << ans << "\n";
	}
}
