//https://atcoder.jp/contests/abc162/tasks/abc162_b
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	ll sum1=0;
	sum1=(n*(n+1))/2;
	ll n3;
	n3=(n)/3;
	ll n5;
	n5=(n)/5;
	ll n15;
	n15=(n)/15;
	ll a3;
	a3=3+(n3-1)*3;
	ll a5;
	a5=5+(n5-1)*5;
	ll a15;
	a15=15+(n15-1)*15;
	ll sum3=0;
	sum3=((n3)*(3+a3))/2;
	ll sum5=0;
	sum5=((n5)*(5+a5))/2;
	ll sum15=0;
	sum15=((n15)*(15+a15))/2;
	ll sumfin=0;
	sumfin=sum3+sum5-sum15;
	ll ans=0;
	ans=sum1-sumfin;
	cout<<ans<<"\n";
	
	
	return 0;
}