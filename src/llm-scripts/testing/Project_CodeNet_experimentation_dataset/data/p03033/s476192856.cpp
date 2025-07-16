#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n,q;
map<int,vector<pair<int,int>>> mp;
int ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>q;
    for (int i=0; i<n; i++) {
	int s,e,x; cin>>s>>e>>x;
	mp[x].emplace_back(s,e);
    }

    for (auto& p: mp) sort(p.second.begin(), p.second.end());

    vector<int> v(q);
    for (auto& x: v) cin>>x;

    set<pair<int,int>> active;
    for (int i=0; i<q; i++) {
	active.insert({v[i],i});
    }

    for (auto p: mp) {
	int x = p.first;
	for (auto cur: p.second) {
	    int s = cur.first; int e = cur.second;
	    for (auto iter = active.lower_bound({s-x,0}); iter != active.end() && iter->first < e-x; ) {
		int id = iter->second;
		ans[id] = x;
		iter = active.erase(iter);
	    }
	}
    }

    for (auto p: active) {
	ans[p.second] = -1;
    }


    for (int i=0; i<q; i++) {
	cout<<ans[i]<<"\n";
    }

    return 0;
}
