#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	ll n,x,ans=0,diff=0;
	cin>>n>>x;
	ll arr[n];
	for(ll i=0;i<n;i++)
		cin>>arr[i];
	for(ll i=1;i<n;i++)
		if(arr[i]+arr[i-1]>x)
		{
			diff=arr[i-1]+arr[i]-x;
			ans+=diff;
			if(arr[i]-diff>=0)
			arr[i]-=diff;
			else
			{
			diff-=arr[i];
			arr[i]=0;
			if(arr[i-1]-diff>=0)
			arr[i-1]-=diff;
			else
			arr[i-1]=0;
			}
		}
	cout<<ans;
	return 0;
}

