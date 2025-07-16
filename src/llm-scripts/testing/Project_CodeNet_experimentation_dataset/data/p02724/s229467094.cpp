//https://atcoder.jp/contests/abc160/tasks/abc160_b
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x;
	cin>>x;
	ll a;
	a=x/500;
	ll fin1;
	fin1=a*1000;
	ll b;
	b=x%500;
	ll c;
	c=b/5;
	ll fin2;
	fin2=c*5;
	ll sum=0;
	sum=fin1+fin2;
	cout<<sum<<"\n";
	return 0;
}