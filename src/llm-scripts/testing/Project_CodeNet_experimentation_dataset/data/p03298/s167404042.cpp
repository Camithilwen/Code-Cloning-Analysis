#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<string, string> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int m = 2*n;
	string s1 = "", s2 = "";
	rep(i,n) s1 += s[i];
	rep(i,n) s2 += s[i+n];
	ll ans = 0;
	map<P, ll> mp;
	rep(i,1<<n){
		string sw = "", sv = "";
		rep(j,n){
			if(i>>j & 1) sw += s1[j];
			else sv += s1[j];
		}
		reverse(sv.begin(), sv.end());
		++mp[P(sw, sv)];
	}
	rep(i,1<<n){
		string su = "", st = "";
		rep(j,n){
			if(i>>j & 1) su += s2[j];
			else st += s2[j];
		}
		reverse(st.begin(), st.end());
		ans += mp[P(st, su)];
	}
	cout << ans << endl;
	return 0;
}
