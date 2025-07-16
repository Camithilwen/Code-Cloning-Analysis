#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main()
{
	fast;
	ll arr[5],k;
	for(int i=0;i<5;i++)
		cin>>arr[i];
	cin>>k;
	if(arr[4]-arr[0]>k)
	{
		cout<<":(";
		return 0;
	}
	else
	{
		for(int i=0;i<5;i++)
			for(int j=i+1;j<5;j++)
				if(arr[j]-arr[i]>k)
				{
					cout<<":(";
					return 0;
				}
	}
	cout<<"Yay!";
	return 0;
}
