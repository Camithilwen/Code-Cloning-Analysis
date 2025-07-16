#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b&&b==c) cout<<"No";
	else if(a!=b&&a!=c&&b!=c) cout<<"No";
	else cout<<"Yes";
	return 0;
}