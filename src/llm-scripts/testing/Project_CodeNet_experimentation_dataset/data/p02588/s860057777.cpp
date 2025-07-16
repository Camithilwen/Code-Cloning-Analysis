#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5+5;

int n;
LL a[90][40];
LL ans;

int main()
{
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		LL y=0;
		int u=s.size();
		for(int i=0;i<s.size();i++)
			if(s[i]=='.') u=i;
		if(u==s.size()) s+=".";
		for(int i=s.size()-u;i<=9;i++) s+="0";
		for(int i=0;i<s.size();i++)
			if(s[i]!='.') y=y*10+s[i]-'0';
		int z1=0,z2=0;
		while(y%2==0) y/=2,z1++;
		while(y%5==0) y/=5,z2++;
		a[z1+36][z2+11]++;
	}
	for(int i=0;i<90;i++)
	for(int j=0;j<40;j++)
	for(int k=90-i;k<90;k++)
	for(int l=40-j;l<40;l++)
		ans+=a[i][j]*a[k][l];
	for(int i=45;i<90;i++)
	for(int j=20;j<40;j++)
		ans-=a[i][j];
	cout<<ans/2<<'\n';
	
	return 0;
}