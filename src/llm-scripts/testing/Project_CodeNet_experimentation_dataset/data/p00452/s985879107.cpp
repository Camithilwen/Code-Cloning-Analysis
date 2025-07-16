#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
	while(1){
		llong n, m;
		scanf("%lld%lld", &n, &m);
		if(n==0) return 0;

		vector<llong> v(n);
		REP(i, n){
			scanf("%lld", &v[i]);
		}
		v.push_back(0);
		n++;

		vector<llong> a;
		REP(i, n){
			REP(j, n){
				a.push_back(v[i]+v[j]);
			}
		}
		VSORT(a);

		llong ans=0;
		REP(i, n){
			REP(j, n){
				llong tmp=v[i]+v[j];
				llong k=upper_bound(a.begin(), a.end(), m-tmp)-a.begin();
				if(k==a.size()) continue;
				k--;

				if(k>=0) ans=max(ans, tmp+a[k]);
			}
		}

		printf("%lld\n", ans);
	}
}