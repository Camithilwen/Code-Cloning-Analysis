#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include <functional>
#include<time.h>
#include <stack>
#include<iomanip>
#include<unordered_map>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define ll long long
#define llint long long int
#define sort(s) sort(s.begin(),s.end())
#define reverse(v)  reverse(v.begin(), v.end());
#define Yes(ans) if(ans)cout<<"Yes"<<endl; else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
#define hei(a) vector<a>
#define whei(a) vector<vector<a>>
#define UF  UnionFind
#define rt (a); return (a); 
#define Pint pair<int,int>
#define Pll pair<ll,ll>
#define keta(a)  fixed << setprecision(a)
constexpr auto INF = 1000000000;
constexpr auto mod = 1000000007;
ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	if (b == 0)return a;
	return gcd(b, a % b);
}
int n,q;
hei(ll) seg, lazy;

void aaa(int k) {
	if (lazy[k] == 0)return ;
	if (k < n - 1) {
		lazy[k * 2 + 1] += lazy[k];
		lazy[k * 2 + 2] += lazy[k];
	}
	seg[k] += lazy[k];
	lazy[k] = 0;
}

void update(int a, int b, ll x,int k,int l,int r) {
	aaa(k);
	if (a<=l && b>=r) {
		lazy[k] += x;
		aaa(k);
	}
	else if(a<r&&l<b){
		update(a, b, x, k * 2 + 1, l, (l + r) / 2);
		update(a, b, x, k * 2 + 2, (l + r) / 2, r);
		seg[k] = seg[k * 2 + 1]+seg[k * 2 + 2];
	}
}

ll query(int a,int b,int k,int l,int r){
	aaa(k);
	if (l >= b || r <= a)return 0;
	if (a <=l  && b >= r) {
		return seg[k];
	}
	ll v1 = query(a, b, k*2+1, l, (l + r) / 2);
	ll v2 = query(a, b, k*2+2, (l + r) / 2, r);
	return v1 + v2;
}

int main() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	int x = 0;
	rep(i, 1, n + 1) {
		if (s.substr(n - i, i) == t.substr(0, i))x = i;
	}
	int ans = (2 * n) - x;
	cout << ans << endl;
	return 0;
}