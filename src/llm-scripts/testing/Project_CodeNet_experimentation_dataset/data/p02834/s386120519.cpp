#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005],c[100005];
vector<int>d[100006];
 
void dfs(int v,int s) {
	a[v]=a[s]+1;
	b[v]=1;
	c[v]=s;
	for(auto x:d[v]) {
		if(x==s) continue;
		dfs(x,v);
		b[v]=max(b[v],b[x]+1);
	}
	
}
int main(){
    int n,u,v;
    cin>>n>>u>>v;
	for(int i=1;i<n;i++) {
		int x,y;
		cin>>x>>y;
		d[x].push_back(y);
		d[y].push_back(x);
	}
	dfs(v,0);
	int ans=-1;
	int dis=a[u]-a[v];
	
	dis=(dis-1)/2;
//	cout<<dis<<endl;
	while(dis--){ 
	    u=c[u];
	}
	if(d[u].size()==1) 
	     ans=a[u]-2;
	else 
	    ans=b[u]+a[u]-3;
	    
	cout<<ans<<endl;
	

}
