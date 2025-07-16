#include "bits/stdc++.h"
#define ll long long
#define lld long double
#define MOD 1000000007
#define inf 1000000000000000000ll
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll power(ll x,ll y, ll md=inf){ll res = 1;x%=md;while(y){if(y&1)res = (res*x)%md;x *= x; if(x>=md) x %= md; y >>= 1;}return res;}
 
using namespace std;


#define endl '\n'
#define int ll

signed main() {
	fast;

	int h,w;
	cin>>h>>w;

	pii v[200002];
	for(int i=0;i<h;i++) cin>>v[i].f>>v[i].s;

	map<int,int> mp;
	for(int i=1;i<=w;i++) mp[i] = 0;

	map<int,int> mini = {{0,w}};

	for(int i=0;i<h;i++) {
		int r = v[i].s;

		auto it = mp.lower_bound(v[i].f);
		int mn = inf;

		while(it!=mp.end() && it->f <= r) {
			mn = min(mn, r+1-(it->f)+(it->s));
			auto it1 = it++;
			auto it2 = mini.find(it1->s);
			if(it2->s==1) mini.erase(it2);
			else it2->s --;
			mp.erase(it1);
		}

		if(r+1<=w && mn<inf) {
			if(it!=mp.end() && it->f == r + 1) {
				if(it->s > mn) {
					auto it1 = mini.find(it->s);
					if(it1->s ==1) mini.erase(it1);
					else it1->s --;
					mini[mn]++;
					it->s = mn;
				}
			}
			else {
				mp.insert({r+1,mn});
				mini[mn]++;
			}
		}

		if(mini.size()) cout<<mini.begin()->f+i+1<<endl;
		else cout<<-1<<endl;

	}
}