#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
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

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int n;
llong m;

int main(){
	while(1){
		scanf("%d%lld", &n, &m);
		if(n==0 && m==0) return 0;
		n++;
		vector<llong> p(n);
		p[0]=0;
		FOR(i, 1, n) scanf("%lld", &p[i]);
		VSORT(p);
		int size=0;
		vector<llong> v;
		REP(i, n){
			REP(j, n){
				v.push_back(p[i]+p[j]);
			}
		}
		VSORT(v);
		llong ans=0;
		REP(i, v.size()){
			int rem=m-v[i];
			if(rem < 0) continue;
			int l=0, r=v.size();

			while(l<r){
				int mid=(l+r)/2;
				if(rem>v[mid]){
					l=mid+1;
				}
				else if(rem<v[mid]){
					r=mid;
				}
				else {
					break;
				}
			}

			ans = max(ans, v[i]+v[r-1]);
		}

		printf("%d\n",ans);
	}
}