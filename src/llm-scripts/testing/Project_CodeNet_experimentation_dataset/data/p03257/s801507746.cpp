#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
using namespace std;
const int N=505,M=10000;
int n,p[M+5],p2[M+5],mu[M+5],ps;
ll a[N][N],h[N],l[N];
bool b[M+5];
ll gcd(ll x,ll y){
	for(;y;y%=x)swap(x,y);
	return x;
}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
int main(){
	n=500;
	fo(i,2,M){
		if(!b[i])p[++ps]=i,mu[i]=1;
		for(int j=1,u;(u=i*p[j])<=M;++j){
			b[u]=1;
			if(i%p[j]==0)break;
			mu[u]=mu[i];
		}
	}
	ps=0;
	for(int i=2;i<=n+n;i+=2){
		++ps;
		fo(j,max(1,i-n),min(n,i-1)){
			int k=i-j;
			a[j][k]=p[ps];
		}
	}
	
	for(int i=n-2;i>=2-n;i-=2){
		++ps;
		fo(j,max(i+1,1),min(n,n+i)){
			int k=j-i;
			a[j][k]*=p[ps];
		}
	}
	
	fo(i,1,n)fo(j,1,n)if(i+j&1){
		a[i][j]=1;
		if(i>1)a[i][j]=lcm(a[i][j],a[i-1][j]);
		if(i<n)a[i][j]=lcm(a[i][j],a[i+1][j]);
		if(j>1)a[i][j]=lcm(a[i][j],a[i][j-1]);
		if(j<n)a[i][j]=lcm(a[i][j],a[i][j+1]);
		++a[i][j];
	}
	cin>>n;
	fo(i,1,n){
		fo(j,1,n)printf("%lld ",a[i][j]);
		printf("\n");
	}
}