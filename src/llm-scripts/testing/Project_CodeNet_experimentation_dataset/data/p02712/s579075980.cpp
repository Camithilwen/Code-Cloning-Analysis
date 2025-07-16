#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	int n;
	cin>>n;
	ll sum = 0;
	rep(i,1,n)
	{

		if(i%3 != 0 && i%5 != 0)
			sum+=i;

	}
	cout<<sum;
}