#include <bits/stdc++.h>
using namespace std;
struct rev_vector {
	const int magic = 123456;
	vector<int> pk;
	int l, r;
	rev_vector(){
		pk.resize(3 * magic);
		l = magic;
		r = l;
	}
	void shift_right(){
		l--;
		pk[l] = 0;
	}
	int& operator [](int pos){
		while(pos + l <= r) pk[r++] = 0;
		return pk[pos + l];
	}
	void clear(){
		l = magic;
		r = l;
	}
};
const int maxn = 100100;
int ans, k, vis[maxn];
vector<int> e[maxn];
int dfs(int u){
	int dep = 0;
	for(int v : e[u]) {
		int mv = dfs(v);
		if(mv == k - 1 && u){
			ans++;
		} else {
			dep = max(dep, mv + 1);
		}
	}
	return dep;
}
int main(){
	int n; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
	if(a[0] != 0){
		a[0] = 0;
		ans++;
	}
	for(int i = 0; i < n; i++){
		if(i != a[i]){
			e[a[i]].push_back(i);
		}
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}
