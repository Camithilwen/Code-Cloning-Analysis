#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
int f[301000][3][3],n;
char s[301000];
void upd(int&a,int b){a+=b;if(a>=mod) a-=mod;}
int main(){
	ios::sync_with_stdio(0);
	cin>>s+1;
	int n=strlen(s+1);
	f[1][0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2;j++)
			for(int k=0;k<=2;k++){
				if(s[i]!='0') upd(f[i+1][k?j:min(2,j+1)][max(0,k-1)],f[i][j][k]);
				if(s[i]!='1') upd(f[i+1][j][k+1>2?1:k+1],f[i][j][k]);
			}
	cout<<(0ll+f[n+1][1][0]+f[n+1][2][1]+f[n+1][2][2]+f[n+1][2][0])%mod<<'\n';
	return 0;
}
