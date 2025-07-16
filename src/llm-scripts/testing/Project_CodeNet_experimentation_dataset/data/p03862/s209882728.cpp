#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;


int main(){
	int n;
	ll x;cin >> n >> x;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	ll ans = 0;
	if(a[0]>x) {
		ans += a[0]-x;
		a[0] = x;
	}
	rep(i,n-1){
		//cout << " " << ans << endl;
		if(a[i]+a[i+1]>x){
			ans += a[i+1] - (x-a[i]);
			a[i+1] = x-a[i];
		}
	}
	//rep(i,n) cout << a[i] << endl;
	cout << ans << endl;
} 
