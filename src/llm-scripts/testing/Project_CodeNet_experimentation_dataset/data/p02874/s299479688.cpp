#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) x.begin(),x.end()
const int maxn = 100010;
const int INF = INT_MAX/2;

int n;
vector <pi> v;
int pre[maxn],suf[maxn];

int dist(int x, int y) {
	return max(y - x + 1,0ll);
}

int32_t main() {
	FAST
	cin >> n;
	v.push_back(pi(0,0));
	for (int i =1;i<=n;i++) {
		int a,b; cin >> a >> b;
		v.push_back(pi(a,b));
	}
	sort(all(v));
	
	//CASE 1: All .f of group 1 < All .f of group 2
	//prefix[i] from 1 to i
	int maxl=0, minr=INF;
	
	for (int i = 1;i<=n;i++) {
		maxl = max(maxl,v[i].f); 
		minr = min(minr,v[i].s);
		
		pre[i] = dist(maxl,minr);
	}
	int whack = pre[n];
	
	//Suffix[i] from n to i+1
	maxl = 0; minr = INF;
	for (int i =n-1;i>=1;i--) {
		maxl = max(maxl,v[i+1].f);
		minr = min(minr,v[i+1].s);
		
		suf[i] = dist(maxl,minr);
	}
	int ans = 0;
	for (int i =1;i<n;i++) {
		ans = max(ans, pre[i] + suf[i]);
	}
	
	//CASE 2: Just take largest guy for group 1 and throw the rest into group 2.
	
	for (int i =1;i<=n;i++) {
		ans = max(ans, whack + dist(v[i].f,v[i].s));
	}
	cout << ans;
}






