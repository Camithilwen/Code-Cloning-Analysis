#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000+5,base=2001*3;
int f[N*3][N*6],mod;
void add(int &x,int y){
	x=(x+y)%mod;
}
signed main(){
	int n;
	cin>>n>>mod;
	n*=3;
	f[0][base]=1;
	for(int i=0;i<n;++i)
		for(int j=-i;j<=i;++j)
			if(f[i][j+base]){
				add(f[i+1][j+1+base],f[i][j+base]);
				add(f[i+2][j-1+base],1ll*f[i][j+base]*(i+1)%mod);
				add(f[i+3][j+base],1ll*f[i][j+base]*(i+1)%mod*(i+2)%mod);
			}
	int ans=0;
	for(int j=0;j<=n;++j)
		add(ans,f[n][j+base]);
	cout<<ans;
	return 0;
}