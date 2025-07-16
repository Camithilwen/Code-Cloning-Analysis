#include<bits/stdc++.h>
using namespace std;

const int N=100100;
int a[N],n,f[N][30],L,Q;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	cin>>L>>Q;
	for(int i=1;i<=n;++i)f[i][0]=upper_bound(a+1,a+n+1,a[i]+L)-a-1;
	for(int i=1;i<=20;++i)
		for(int j=1;j<=n;++j)f[j][i]=f[f[j][i-1]][i-1];
	for(;Q --> 0;){
		int l,r;cin>>l>>r;
		if(l>r)swap(l,r);
		int ans=1;
		for(int i=20;~i;--i)
			if(f[l][i]<r)l=f[l][i],ans+=1<<i;
		cout<<ans<<'\n';
	}
	return 0;
}
