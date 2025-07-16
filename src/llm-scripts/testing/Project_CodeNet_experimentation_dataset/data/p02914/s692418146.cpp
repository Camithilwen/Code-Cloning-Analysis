#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin >> n;
	vector<long long> a(n), base;
	for(auto & e : a) cin >> e;
	long long all = 0;
	for(auto & e : a) all ^= e;
	for(auto & e : a) e &= ~all;
	for(auto e : a){
		for(auto b : base) e = min(e, e ^ b);
		if(e){
			base.push_back(e);
		}
	}
      sort(base.rbegin(), base.rend());
	long long up = 0;
	for(auto b : base) up = max(up, up ^ b);
	cout << all + 2 * up << endl;
	return 0;
}