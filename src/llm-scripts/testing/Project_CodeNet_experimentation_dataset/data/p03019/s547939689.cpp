#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 233;
typedef long long ll;
int a[maxn],l[maxn],r[maxn],ord[maxn];
ll val[maxn],sum[maxn],tot = 0;
int n,x;
bool cmp(int i,int j){
	return val[i]>val[j];
}
inline ll cal(int i,int v){
	if(v<=a[i])return 1LL*v*l[i];
	return 1LL*a[i]*l[i]+1LL*(v-a[i])*r[i];
}
bool check(ll m){
	int t = (m-1)/x,v = m-t*x;
	ll maxi = 0;
	for(int i=1;i<=t;i++){
		int x = ord[i]; 
		ll tmp = sum[t+1] - val[x] + cal(x,v);
		maxi = max(maxi,tmp);
	}
	for(int i=t+1;i<=n;i++){
		ll tmp = sum[t] + cal(ord[i],v);
		maxi = max(maxi,tmp); 
	}
	if(maxi>=tot)return 1;
	return 0;
}
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&l[i],&r[i]),
		val[i] = cal(i,x),
		ord[i] = i,
		tot += cal(i,a[i]);
//	cout<<tot<<endl;
	sort(ord+1,ord+n+1,cmp);
	for(int i=1;i<=n;i++)
		sum[i] = sum[i-1]+val[ord[i]];
	ll l = 0,r = 1LL*n*x;
	while(l!=r){
		ll m = (l+r)>>1;
		if(check(m))r = m;
		else l = m+1; 
	}
	cout << l << endl;
	return 0;
} 