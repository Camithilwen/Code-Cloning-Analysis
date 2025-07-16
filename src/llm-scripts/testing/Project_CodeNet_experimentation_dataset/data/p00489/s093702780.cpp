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

pair<int,int> a[101];
int b[101];
bool comp(pair<int,int> x, pair<int,int> y){
	return x.fi > y.fi;
}

int main(){
	int n, m, t[4], p, s = INF;
	scanf("%d", &n);
	m = (n*(n-1))/2;
	rrep(i,n)a[i].se = i;
	rep(i,m){
		rep(j,4)scanf("%d", &t[j]);
		if(t[2] > t[3])a[t[0]].fi += 3;
		if(t[2] < t[3])a[t[1]].fi += 3;
		if(t[2] == t[3])a[t[0]].fi++, a[t[1]].fi++;
	}
	sort(a+1, a+n+1, comp);
	for(int i = 1;i <= n;i++){
		if(s > a[i].fi){
			s = a[i].fi;
			p = i;
		}
		a[i].fi = p;
		b[a[i].se] = i;
	}
	rrep(i,n)printf("%d\n", a[b[i]].fi);
	return 0;
}