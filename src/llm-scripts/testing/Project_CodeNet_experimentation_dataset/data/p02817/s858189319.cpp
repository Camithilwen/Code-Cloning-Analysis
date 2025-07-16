#include<bits/stdc++.h>
using namespace std;

long long int n,i,x,a;
string s,t;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s>>t;
	n=s.size();
	for (i=0;i<n;i++) t.push_back(s[i]);
	cout<<t;
}