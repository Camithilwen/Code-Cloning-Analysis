#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e18+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=40000;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
int main()
{
	int i,j,k,l,m,n;
	string s;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	l=0;
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(a[i]==a[j]||a[i]==a[k]||a[j]==a[k])
					continue;
				if(a[i]+a[j]>a[k])
					l++;
			}
		}
	}
	cout<<l;
}