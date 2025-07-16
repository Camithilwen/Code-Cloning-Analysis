#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define N 200010
int n,a[N],b[N],c[N],d[N];
int main(){
    cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n+1)c[i]=d[i]=0;
    rep(i,n)c[a[i]]++,d[b[i]]++;
    rep(i,n+1){
	if(c[i]+d[i]>n){
	    cout<<"No\n";
	    return 0;
	}
    }
    for(int i=1;i<=n;i++){
	c[i]+=c[i-1];
	d[i]+=d[i-1];
    }
    int x=0;
    for(int i=1;i<=n;i++)x=max(x,c[i]-d[i-1]);
    cout<<"Yes\n";
    rep(i,n){
	if(i)cout<<" ";
	cout<<b[(i+n-x)%n];
    }
    cout<<"\n";
}
