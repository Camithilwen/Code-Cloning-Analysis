#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define INF 1.1e9
#define LINF 1.1e18
#define FOR(i,a,b) for (long long i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;

int n,m;
vector<int> v[501];
set<int> st,ss;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    while(true) {
	cin>>n>>m;
	if(n==0&m==0) break;
	REP(i,501) v[i].clear();
	st.clear();ss.clear();
	REP(i,m) {
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	st.insert(1);
	REP(i,v[1].size()) {
		st.insert(v[1][i]);
	}
	for(auto x:st) {
		REP(i,v[x].size()) {
			ss.insert(v[x][i]);
		}
	}
	for(auto x:st) {
		ss.insert(x);
	}
	cout<<ss.size()-1<<endl;
    }

	return 0;
}

