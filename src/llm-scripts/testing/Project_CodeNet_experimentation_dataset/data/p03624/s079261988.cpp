#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	string s;
	cin>>s;
	map<char,int> m;
	for(char c : s)
	{
		m[c]++;
	}
	for(char c='a';c<(char)('a'+26);c=(char)(c+1))
	{
		if(m[c]==0)
		{
			cout<<c<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
	return 0;
}
