#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ll n, t; 
	cin >> n >> t;
	ll ans = n*t;
	ll last;
	cin >> last;
	for(int i = 1; i < n; ++i){
		int cur;
		cin >> cur;
		if(cur<(last+t)){
			ans += (cur-(last+t));
		}
		last = cur;
	}
	cout << ans;
	return 0;
}

