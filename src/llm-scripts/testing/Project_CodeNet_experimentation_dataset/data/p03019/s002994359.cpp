#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, X;
vector <ll> b, l, r;

ll calc(int day, int a){
	return (a <= b[day] ? l[day] : r[day]) * (a - b[day]);
}
ll sum(int day, int len){
	if(len <= b[day]) return len * l[day];
	return b[day] * l[day] + (len - b[day]) * r[day];
}
ll calc(ll h){
	int q = h / X;
	int r = h % X;
	vector <pair <ll, int> > c;
	for(int i = 0 ; i < n ; i++){
		c.emplace_back(sum(i, X), i);
	}
	sort(c.rbegin(), c.rend());
	ll s = 0;
	for(int i = 0 ; i < q ; i++){
		s += c[i].first;
	}
	if(r == 0) return s;
	ll ret = 0;
	for(int i = 0 ; i < q ; i++){
		ret = max(ret, s - sum(c[i].second, X) + sum(c[i].second, r) + sum(c[q].second, X));
	}
	for(int i = q ; i < n ; i++){
		ret = max(ret, s + sum(c[i].second, r));
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> X;
	b.resize(n);
	l.resize(n);
	r.resize(n);
	for(int i = 0 ; i < n ; i++){
		cin >> b[i] >> l[i] >> r[i];
	}
	ll D = 0;
	for(int i = 0 ; i < n ; i++){
		D += calc(i, 0);
	}
	ll l = 0, r = 1LL * n * X;
	while(l <= r){
		ll mid = (l + r) / 2;
		if(D + calc(mid) >= 0) r = mid - 1;
		else l = mid + 1;
	}
	cout << l << endl;
}
