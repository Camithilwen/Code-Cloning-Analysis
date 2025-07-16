#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007LL
#define eps 1e-8

using namespace std;

string a3[3]={"aa.","..b","..b"};
string a4[4]={"aabc","ddbc","efgg","efhh"};
string a5[5]={"aabbc","dde.c","ffegg","..hij","..hij"};
string a6[6]={"aabbcc","ddeeff","ghi...","ghi...","...jkl","...jkl"};
string a7[7]={"aabbcc.","ddeef..","gg..fhh","..ij..k","..ij..k","....lmn","....lmn"};
string *ap[8]={NULL,NULL,NULL,a3,a4,a5,a6,a7};
string a[1005];

int main()
{
	cin.tie(0),ios::sync_with_stdio(0);
	int n;
	cin>>n;
	if(n<3) cout<<"-1\n";
	else if(n==3){
		for(int i=0;i<3;i++)
			cout<<a3[i]<<"\n";
		cout<<"\n";
	}
	else{
		fill(a,a+n,string(n,'.'));
		while(n>=8){
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++)
					a[i+n-4][j+n-4]=a4[i][j];
			}
			n-=4;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				a[i][j]=ap[n][i][j];
		}
		n=a[0].size();
		for(int i=0;i<n;i++)
			cout<<a[i]<<"\n";
	}
	return 0;
}