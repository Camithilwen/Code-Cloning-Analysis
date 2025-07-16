#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i=a; i < n; i++)
typedef long long int lli;
typedef long double Double;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAXN (1<<16)
lli val[MAXN];
lli dp[MAXN];
int used[MAXN];
int a[17][17];
int n;

lli solve(int msk){
	if(msk == (1<<n)-1){
		return 0ll;
	}

	if(used[msk]) return dp[msk];
	used[msk] = 1;
	lli ans = -1ll;
	int ini = msk ^ ((1<<n)-1);
	for(int i=ini; i >=1; i--){
		int andi = msk & i;
		if(andi == 0){
			ans = max(ans, solve(msk | i) + val[i]);
		}
	}
	return dp[msk] = ans;
}

int main(){__
	cin >> n;
	for(int i=0; i < n; i++){
		for(int j=0; j < n; j++){
			cin >> a[i][j];
		}
	}

	for(int i=1; i < (1<<n);i++){
		int msk = i;
		lli res = 0ll;
		for(int j =0; j < n; j++){
			if(msk & (1<<j)){
				for(int k =j; k < n; k++){
					if(msk & (1<<k)){
						res+= a[j][k];
					}
				}
			}
		}
		val[i] = res;
	}
	cout << solve(0) << endl;
	return 0;
}
