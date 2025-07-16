#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define MOD 1000000007
#define vec(a) vector<int>a
using namespace std;

bool isPrime(ll n)
{
	if(n==1||n==2||n==3||n==5||n==7)
		return 1;
	else
	{
		ll i,j,k,l,m;
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
				return 0;
		}
		return 1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	ll arr[3];
	cin>>arr[0]>>arr[1]>>arr[2];
	sort(arr,arr+3);
	cout<<arr[0]+arr[1];
	return 0;
}
	