#include<bits/stdc++.h>
using namespace std;
bool col[1000005];
bool row[1000005];
long long mod=1e9+7;
int main(){
	int n,m,a,b;
	long long ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	cin>>a;
	if(row[a])
	{
		cout<<0;
		return 0;
	}
	row[a]=1;
	}
	for(int i=1;i<=m;i++)
	{
	cin>>b;	
	if(col[b])
	{
		cout<<0;
		return 0;
	}
	col[b]=1;
	}
	long long c=0,r=0;
	for(int i=n*m;i>0;i--){
        long long tc=c,tr=r;
        if(col[i]) 
		{
		tc=1;
		c++;
		}
        if(row[i]) 
		{
		tr=1;
		r++;
		}
        if(col[i]||row[i]) 
		ans*=(tc*tr)%mod;
        else 
		ans*=(tc*tr-(n*m-i))%mod;
		ans%=mod;
    }
	cout<<ans%mod;
}