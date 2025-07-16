#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[100][100],b[100][100];
main()
{
	while(cin>>m>>n,n)
	{
    	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
    	{
    		if(i==j)continue;
    		a[i][j]=1e9;
    		b[i][j]=1e9;
    	}
    	for(int i=0;i<m;i++)
    	{
    		int s,t,u,v;cin>>s>>t>>u>>v;
    		s--,t--;
    		a[s][t]=min(a[s][t],u);
    		a[t][s]=min(a[t][s],u);
    		b[s][t]=min(b[s][t],v);
    		b[t][s]=min(b[t][s],v);
    	}
    	for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
    	{
    		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    		b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
    	}
    	int k;cin>>k;
    	for(;k--;)
    	{
    		int p,q,r;cin>>p>>q>>r;
    		p--,q--;
    		if(r)cout<<b[p][q]<<endl;
    		else cout<<a[p][q]<<endl;
    	}
	}
}

