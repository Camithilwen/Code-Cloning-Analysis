#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	set<pair<int, int> > a, b;
	for(int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		a.insert({x, y});
	}
	for(int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		b.insert({x, y});
	}
	int ans = 0;
	for(auto pp : b){
		int x = -1, y = -1;
		for(auto qq : a){
			if(qq.first < pp.first && qq.second < pp.second){
				if(y < qq.second){
					x = qq.first;
					y = qq.second;
				}
			}
		}
		if(x != -1){
			a.erase({x, y});
			ans++;
		}
	}
	cout<<ans<<endl;

	return 0;
}