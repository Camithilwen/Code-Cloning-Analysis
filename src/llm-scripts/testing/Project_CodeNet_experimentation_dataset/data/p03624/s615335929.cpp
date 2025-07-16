#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
int main(){
	fast;
	string s;
	cin>>s;
	int fre[26]={0};
	for(int i=0;i<s.length();i++)
		fre[s[i]-97]++;
	for(int i=0;i<26;i++)
	{
		if(fre[i]==0)
		{
			cout<<(char)(i+97);
			return 0;
		}
	}
	cout<<"None";
	return 0;
}

