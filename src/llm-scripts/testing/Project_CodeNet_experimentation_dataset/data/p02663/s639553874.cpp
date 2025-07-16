#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fo(i,n) for(ll i=0;i<n;i++)
#define fo1(i,n) for(ll i=1;i<=n;i++)
#define loop(i,a,b)for(ll i=a;i<=b;i++)
#define loopr(i,a,b)for(ll i=b;i>=a;i--)
#define vll vector<ll> 
#define vvl vector<vll>
#define pii pair<ll,ll>
#define F first
#define S second

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll h1,m1,h2,m2,k;
	cin>>h1>>m1>>h2>>m2>>k;
	ll ans=h2*60+m2-h1*60-m1-k;
	if(ans<0)
	cout<<0;
	else
	cout<<ans;
	return 0;
}