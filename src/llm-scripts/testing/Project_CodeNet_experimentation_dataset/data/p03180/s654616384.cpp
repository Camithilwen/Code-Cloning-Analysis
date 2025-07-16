#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<deque>
#include<map>
#include<unordered_map>
#include<set>
#include<cmath>
#include<climits>
#include<random>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
const double eps = 1e-6;
 
/////////////////////////////////////////////
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
////////////////////////////////
 
#define int long long

void solve(){

	int n;
	cin>>n;
	int a[n][n];


	for(int i = 0 ; i < n ; ++i){

		for(int j = 0 ; j < n ; ++j)
			cin>>a[i][j];
	}

	int nn = (1<<n);
	int dp[nn];
	memset(dp , 0 , sizeof dp);
	for(int i = 1 ; i <= nn ; ++i){

		vector<int> tmp;
		for(int j = 0 ; j < n ; ++j){

			if((1<<j)&i)
				tmp.pb(j);
		}

		for(int k = 0 ; k < tmp.size() ; ++k)
			for(int j = k + 1 ; j < tmp.size() ; ++j){

				dp[i] += a[tmp[k]][tmp[j]];
			}
	}

	for(int mask = 1 ; mask < nn ; ++mask){

		for(int i = mask ; i > 0 ; i= mask&(i-1)){

			dp[mask] = max(dp[mask] , dp[i] + dp[i^mask]);
		}
	}

	cout<<dp[nn-1]<<endl;
}

signed main(){
 
    fast;
    int t = 1;
    //cin>>t;
   	for(int i = 1 ; i <= t ; ++i){

   		solve();
   	}
}
