#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false),cin.tie(0);
#define ll long long
#define inf 0x3f3f3f3f
const int N=105;
//set<string>b;
//set<string>::iterator it;

int main()
{
	IO;
	double d,t,s,x;
	cin>>d>>t>>s;
	x=1.0*d/s;
	if(x>t) cout<<"No\n";
	else cout<<"Yes\n";
    return 0;
}