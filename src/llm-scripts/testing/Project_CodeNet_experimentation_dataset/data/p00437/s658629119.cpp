#include <bits/stdc++.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int n,a,b,c;
	while(1){
		cin>>a>>b>>c;
		n=a+b+c;
		if(n==0) break;
		int m;
		cin>>m;
		vi d(n+1,2),x(m),y(m),z(m),f(m);
		rep(i,0,m){
			cin>>x[i]>>y[i]>>z[i]>>f[i];
			if(f[i]==1){
				d[x[i]]=1;
				d[y[i]]=1;
				d[z[i]]=1;
			}
		}
		rep(i,0,m){
			if(f[i]==0){
				if(d[x[i]]==1 && d[y[i]]==1) d[z[i]]=0;
				else if(d[z[i]]==1 && d[y[i]]==1) d[x[i]]=0;
				else if(d[x[i]]==1 && d[z[i]]==1) d[y[i]]=0;
			}
		}
		rep(i,1,n+1){
			o(d[i]);
		}
	}
}