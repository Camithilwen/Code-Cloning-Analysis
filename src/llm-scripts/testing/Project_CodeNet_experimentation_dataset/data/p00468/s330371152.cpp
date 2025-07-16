#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
#define drep(i,n) for(int i=n;i>=0;i--)
#define INF 100000005
#define MAX 100001
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
//__gcd(a,b), __builtin_popcount(a);

bool b[501];
int main(){
	int n, m, t1,t2;
	while(1){
		stack<int> s[501];
		scanf("%d%d", &n, &m);
		if(!n)break;
		fill(b, b+501, false);
		rep(i,m){
			scanf("%d%d", &t1, &t2);
			s[t1].push(t2);
			s[t2].push(t1);
		}
		while(!s[1].empty()){
			t1 = s[1].top();s[1].pop();
			b[t1] = 1;
			while(!s[t1].empty()){
				t2 = s[t1].top();s[t1].pop();
				b[t2] = true;
			}
		}
		int ans = 0;
		rrep(i,n)if(b[i]&&i!=1)ans++;
		printf("%d\n", ans);
	}
	return 0;
}