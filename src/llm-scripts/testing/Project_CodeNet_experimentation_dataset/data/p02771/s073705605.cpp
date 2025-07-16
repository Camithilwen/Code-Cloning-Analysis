#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
#endif

	int a,b,c;
	cin>>a>>b>>c;
	if(a==b && b==c)
	{
		cout<<"No"<<endl;
	}
	else if((a==b && b!=c) || (a==c && c!=b) || (b==c && c!=a))
	{
		cout<<"Yes"<<endl;
	}
	else
		cout<<"No"<<endl;

	return 0;
}