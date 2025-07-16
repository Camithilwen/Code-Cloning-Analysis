#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
#define drep(i,n) for(int i=n;i>=0;i--)
#define INF 100000005
#define MAX 100000001
#define dmp make_pair
#define dpb push_back
#define fi first
#define se second
using namespace std;
//__gcd(a,b), __builtin_popcount(a);

int n, m, a[10], ans;
map<int,int> mp;

int solve(int tmp[4], int k, int sum, int p){
	int t, u[4];
	rep(i,4)u[i] = tmp[i];
	u[k++] = p;
	if(a[p] >= 10)sum = sum*100+a[p];
	else sum = sum*10+a[p];
	
	if(m == k){
		if(mp[sum]==0)ans++;
		mp[sum] = 1;
		return 0;
	}
	
	for(int i = 0;i < n;i++){
		t = 1;
		rep(j,k)if(u[j] == i)t = 0;
		if(t)solve(u, k, sum, i);
	}
	return 0;
}

int main(){
	int u[4] = {0,0,0,0};
	while(1){
		ans = 0;
		mp.clear();
		scanf("%d%d", &n, &m);
		if(!n)break;
		rep(i,n)scanf("%d", &a[i]);
		for(int i = 0;i < n;i++){
			solve(u, 0, 0, i);
		}
		printf("%d\n", ans);
	}
	return 0;
}