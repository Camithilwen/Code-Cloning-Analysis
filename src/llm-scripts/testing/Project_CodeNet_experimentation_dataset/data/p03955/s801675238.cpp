#include<bits/stdc++.h>
using namespace std;
void gofail(){
	cout<<"No\n";
	exit(0);
}
const int N=100100;
int a[N],b[N],c[N],sum[3*N],sum1,sum2,n;
void add(int x){for(;x;x-=x&-x)sum[x]^=1;}
int qry(int x){int ans=0;for(;x<=3*n;x+=x&-x)ans^=sum[x];return ans;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<=n;++i){
		if(a[i]<b[i]){
			if(a[i]+1!=b[i])gofail();
			if(b[i]+1!=c[i])gofail();
			if(c[i]%3)gofail();
			a[i]=a[i]/3+1;b[i]=0;
		}else{
			if(a[i]-1!=b[i])gofail();
			if(b[i]-1!=c[i])gofail();
			if(a[i]%3)gofail();
			a[i]=a[i]/3;b[i]=1;
		}
		if((a[i]^i)&1)gofail();
		if(i&1)sum2^=b[i];
		else sum1^=b[i];
	}
	for(int i=1;i<=n;i+=2){
		sum1^=qry(a[i]);
		add(a[i]);
	}
	memset(sum,0,sizeof sum);
	for(int i=2;i<=n;i+=2){
		sum2^=qry(a[i]);
		add(a[i]);
	}
	if(sum1||sum2)gofail();
	cout<<"Yes\n";
	return 0;
}
