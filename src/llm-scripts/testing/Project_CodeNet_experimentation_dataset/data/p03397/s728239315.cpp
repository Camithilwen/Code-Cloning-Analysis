#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int f[2][7],a[7][2]={
	{1,3},
	{2,0},
	{1,1},
	{4,5},
	{6,3},
	{5,5},
	{4,4}
};
int main(){
	string s;cin>>s;
	int*p=f[0],*q=f[1];
	p[0]=1;
	for(char c:s){
		memset(q,0,sizeof(f[0]));
		for(int i=0;i<7;i++)
			for(int j=0;j<2;j++)
				if(c=='0'+j||c=='?')
					(q[a[i][j]]+=p[i])%=mod;
		swap(p,q);
	}
	cout<<(p[3]+p[5])%mod<<"\n";
	return 0;
}