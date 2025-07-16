#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;
typedef double db;
const double pi = 3.141592654;
#define pb         push_back
#define forab(i,a,b)       for(int i=(a);i<=(b);i++)
#define CIN	ios_base::sync_with_stdio(0); cin.tie(0)
#define pcase(z,x)     printf("Case %ld: %lld\n",z,x)
#define nw	 "\n"
#define mod 1000000007

ll e[100000000];
int main(void)
{
	CIN;
	ll tc,l,k=0,sum=0,x=0,y,z=0,m=1,n=0,ans=0,cnt=0;
	map<ll,bool>mp;
	string s;
	cin>>n>>k;
	for(ll i=1;i<=k;i++){
		cin>>x>>s;
		if(s=="AC"){
			if(!mp[x])sum++,cnt+=e[x],mp[x]=1;
		}
		
		else e[x]++;

	}
	
	cout<<sum<<" "<<cnt;

}