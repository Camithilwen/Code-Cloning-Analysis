#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
typedef pair<int,int> pii;
typedef pair <long long,long long> pll;
typedef long long ll; 
typedef long double ld; 
const ll mod = 1e9+7;

ll dp[10001][101][2];
ll solve( string & k, int& D, int pos , int d , bool tight)
{	if(dp[pos][d][tight] != -1)
		return dp[pos][d][tight];
		
	int ub = (tight) ? (k[pos]-'0') : 9 ;
	if(pos == k.length() - 1){
		ll ans = 0;
		for(int x = 0; x <= ub ; x++)
			if(x%D == d)
				ans++;
		return ans;
	}
	else{
	ll ans = 0;
	for(int x = 0; x <= ub; x++)
		ans = (ans + solve( k , D, pos+1, (D + d - x%D)%D , tight&&(x == ub)))%mod;
	return dp[pos][d][tight] = ans;
	}
} 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int d;
	string k;
	cin >> k >> d;
	memset(dp, -1, sizeof(dp));
	cout << (mod+solve(k, d, 0, 0, 1)-1)%mod;
	return 0;
}
