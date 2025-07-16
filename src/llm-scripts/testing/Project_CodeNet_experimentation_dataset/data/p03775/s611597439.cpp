#include<bits/stdc++.h>

using namespace std;

#define ll long long

int cntD(ll i){
	int cnt = 0;
	if( i == 0) return 1;
	while(i>0){
		i /= 10;
		++cnt;
	}
	return cnt;
}

ll f (ll i, ll j){
	return max(cntD(i), cntD(j));
}

int main(){
	ll n; 
	cin >> n;
	ll d = cntD(n);
	for(ll a = 1; a*a<=n; ++a){
		if(n%a != 0) continue;
		ll b = n/a;
		d = min(d, f(a,b));
	}
	cout << d;
	return 0;
}
