#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e6+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=5001;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound

ll k1=0;
void solve(string s,string r)
{
   int z[maxn]={};
   string t=r;
   t+'#';
   t+=s;
   //for(i=0;i)
   z[0]=0;
   int left=0;
   int right=0;
   int i,j,k,l,n;
   n=t.size();
   for(int k=1;k<n;k++)
   {
   	if(k>right)
   	{
   		right=k;
   		left=k;
   		while(k<n&&t[right-left]==t[right])
   			right++;
   		z[k]=right-left;
   		right--;

   	}
   	else
   	{
   		int k1=k-left;
   		if(z[k1]<right-k+1)
   			z[k]=z[k1];
   		else
   		{
   			left=k;
   			while(k<n&&t[right-left]==t[right])
   			right++;
   		     z[k]=right-left;
   		   right--;

   		}
   	}
   }
   k=r.size();
   k1=k;
   for(i=r.size();i<=t.size()-r.size();i++)
   {
   	k1=min((int)k1,k-z[i]);
   }
}
int main()
{
	fastio;
	int t;
	ll i,j,k,l,n;
	cin>>n;
	ll a[n+1]={},b[n+1]={};
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]%mod;
		b[i]=b[i-1]+a[i];
		b[i]=b[i]%mod;

	}
	l=0;
	for(i=1;i<n;i++)
	{
		l=(l+((b[n]-b[i]+mod)*a[i]%mod))%mod;
	}
	cout<<l;
	

}
//Lordvishnu@almighty