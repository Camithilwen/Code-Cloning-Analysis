#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n, m;
unordered_map<string, int> mp;

int main(void){
	cin >> n;
	rep(i, n){
		string s;
		cin >> s;
		mp[s]++;
	}
	cin >> m;
	rep(i, m){
		string t;
		cin >> t;
		mp[t]--;
	}
	int ans = -INT_MAX;
	for(auto i : mp){
		ans = max(ans, i.second);
	}
	cout << max(ans, 0) << endl;
	return 0;
}
