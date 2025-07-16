#include<bits/stdc++.h>
using namespace std;

int n, p, ans;
long long sum[100005], top, d, m, v, a[100005];

bool cmp(int a, int b) { return a > b; }

int main() {
	cin>>n>>m>>v>>p;
	v = n - v;
	top = v*m;
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	    sum[i] = sum[i - 1] + a[i];
	ans = p;
	for(int i = p + 1; i <= n; i++) {
		d =  sum[i - 1] - sum[p - 1] - a[i]*(long long)(i - p);
		if(d > top) continue;
		if(a[p] - a[i] > m) continue;
		ans++;
	}
	cout<<ans<<endl;
} 

