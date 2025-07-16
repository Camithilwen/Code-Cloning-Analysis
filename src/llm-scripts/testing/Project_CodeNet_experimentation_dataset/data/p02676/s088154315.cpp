#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int k;cin>>k;
	string s;cin>>s;
	int n=s.length();
	if(n<=k) cout<<s<<"\n";
	else
	{
		string s1="";
		for(int i=0;i<k;i++)
		s1=s1+s[i];
		s1=s1+"...";
		cout<<s1<<"\n";
	}
	return 0;
}