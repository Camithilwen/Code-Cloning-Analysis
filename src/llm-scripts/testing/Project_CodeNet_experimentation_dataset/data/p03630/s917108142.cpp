#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fore(b,c) for(int val0=b;val0<c;val0++)
#define forr(k,c,s) for(int k=c;k<s;k++)
#define pb push_back
#define mmp make_pair
#define oset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<vii> al;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1LL<<61;
int g[2020][2020],h[2020][2020];
ii dp[2020][2020];
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			char c;
			cin >> c;
			g[i][j] = (c == '#');
		}
	}
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<m-1;j++) {
			h[i][j] = 1-((g[i][j] + g[i+1][j] + g[i][j+1] + g[i+1][j+1])%2);
		}
	}
	int ma = max(n,m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m-1;j++) {
			if(h[i][j]) {
				if(i > 0) {
					h[i][j] = max(h[i-1][j]+1,2);
				} else {
					h[i][j] = 2;
				}
			}
		}
		stack<int> st;
		int v,mc = 0;
		int id = 0;
		while(id < m-1) {
			if(st.empty() || h[i][st.top()] <= h[i][id]) {
				st.push(id++);
			} else {
				v = h[i][st.top()];
				st.pop();
				mc = v*(id+1);
				if(!st.empty()) {
					mc = v*(id-st.top());
				}
				ma = max(ma,mc);
			}
		}
		while(!st.empty()) {
			v = h[i][st.top()];st.pop();
			mc = v*(id+1);
			if(!st.empty()) {
				mc = v*(id-st.top());
			}
			ma = max(ma,mc);
		}
	}
	cout << ma << '\n';
}