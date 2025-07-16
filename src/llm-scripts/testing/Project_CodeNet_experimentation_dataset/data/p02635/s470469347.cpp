//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 998244353;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

string str;
int n, k;
ll dp[305][305][305];

int main(){
	cin >> str;
	n = str.size();
	cin >> k; chmin(k, n);
	dp[0][0][0] = 1;
	for(int i=0;i<n;i++){
		int pre = n-1-i;
		while(pre >= 0 && str[pre] == '1') pre--;
		
		rep(j, i+1){
			rep(all, k+1){
				if(dp[i][j][all] == 0) continue;
				if(str[n-1-i] == '0'){
					//0 & 0
					add(dp[i+1][j+1][all], dp[i][j][all]);
					//0 & 1
					if(i > j){
						add(dp[i][j+1][all], dp[i][j][all]);
					}
				}
				else{
					//1 & 0
					if(pre != -1 && all+n-1-i-pre <= k) add(dp[n-pre][j+1][all+n-1-i-pre], dp[i][j][all]);
					//1 & 1
					add(dp[i+1][j+1][all], dp[i][j][all]);
				}
			}
		}
	}
	//cout << dp[2][1][1] << endl;
	ll ans = 0;
	rep(j, n+1) rep(i, k+1) ans += dp[n][j][i];
	cout << (ans%mod) << endl;
}