#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
	int n,m;
	while(cin>>n>>m,n){
		vector<int> c(n+1);
		REP(i,n)cin>>c[i+1];
		vector<int> a;
		REP(i,n+1)REP(j,n+1)a.push_back(c[i]+c[j]);
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(),a.end()), a.end());
		int ans = 0;
		REP(i,a.size()){
			if(a[i] <= m){
				int t = m - a[i];
				vector<int>::iterator it = upper_bound(a.begin(), a.end(), t);
				it--;
				ans = max(ans, a[i] + *it);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}