#include "bits/stdc++.h"
#define ll long long
#define lld long double
#define MOD 998244353
#define inf 1000000000000000000ll
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll power(ll x,ll y, ll md=MOD){ll res = 1;x%=md;while(y){if(y&1)res = (res*x)%md;x *= x; if(x>=md) x %= md; y >>= 1;}return res;}
 
using namespace std;

#define endl '\n'
#define int ll


int lcm(int a, int b) {
	int g = __gcd(a,b);
	int ans = a/g;
	ans *= b;
	return ans;
}

string s;
int k;

int dp[305][305][305];
int pre[305][305][305];
int pre1[305][305][305];
vector<int> v;

// int solve(int index, int out, int total) {
// 	if(out<0 || out>3) return 0;

// 	if(index==v.size()) {
// 		if(out==0) return 1;
// 		else return 0;
// 	}

// 	if(dp[index][out]!=-1) return dp[index][out];
// 	int ans = 0;

// 	// Consumer
// 	for(int i=0;i<=300;i++) {
// 		ans += solve(index+1,out+i, total);
// 		ans %= MOD;
// 	}

// 	// Producer
// 	for(int i=1;i<=v[index];i++) {
// 		ans += solve(index+1,out-i, total+i);
// 		ans %= MOD;
// 	}

// 	cout<<index<<" "<<out<<" -- "<<ans<<endl;
// 	return dp[index][out] = ans;
// }

signed main() {
	fast;

	cin>>s;
	cin>>k;

	int cur = 0;
	int n = s.size();
	k = min(k, n);

	for(int i=0;i<n;i++) {
		if(s[i]=='0') {v.pb(cur);cur=0;}
		else cur++;
	}
	v.pb(cur);

	for(int i=0;i<=300;i++) pre[v.size()][0][i] = 1, pre1[v.size()][0][0] = 1;

	int ff = 0;

	for(int i=(int)v.size()-1;i>=0;i--) {
		for(int tot=k;tot>=0;tot--) {

			for(int out=0;out<=300;out++) {
				int ans = 0;

				int sum = pre[i+1][tot][300] - ((out==0)?0:pre[i+1][tot][out-1]);
				// if(i==2 && tot==0 && out==0) cout<<"$$"<<sum<<endl;

				ans += sum;
				ans %= MOD;

				if(tot>=out) sum = ((out-(v[i]) < 0) ? pre1[i+1][tot-out][0]: pre1[i+1][tot-v[i]][out-v[i]]) - pre1[i+1][tot][out];
				else sum = ((tot-(v[i]) < 0) ? pre1[i+1][0][out-tot]: pre1[i+1][tot-v[i]][out-v[i]]) - pre1[i+1][tot][out];
				// if(i==2 && tot==0 && out==0) cout<<"$$"<<sum<<" "<<v[i]<<endl;

				ans += sum;
				ans %= MOD;

				if(out!=0) {
					pre[i][tot][out] = (ans + pre[i][tot][out-1])%MOD;
				}
				else {
					pre[i][tot][out] = ans;
				}

				if(out!=300) {
					pre1[i][tot][out] = (ans + pre1[i][tot+1][out+1])%MOD;
				}
				else {
					pre1[i][tot][out] = ans;
				}

				// cout<<"#"<<i<<" "<<tot<<" "<<out<<" -- "<<ans<<endl;

				if(i==0&&tot<=k&&out==0) ff += ans;
				ff %= MOD;
			}
		}
	}

	ff += MOD;
	ff %= MOD;
	cout<<ff;

}