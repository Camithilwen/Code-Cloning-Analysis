#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=300005,P=1e9+7;
int n,f[N][3][3];
char s[N];
void addx(int&k1,int k2){
	(k1+=k2)>=P&&(k1-=P);
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n==1){
		puts(s[1]=='0'?"0":"1");
		return 0;
	}
	f[0][0][0]=1;
	rep(i,1,n){
		if(s[i]!='1'){
			rep(j,0,2)rep(k,0,2)addx(f[i][j][k?3-k:1],f[i-1][j][k]);
		}
		if(s[i]!='0'){
			rep(j,0,2)rep(k,0,2)addx(f[i][min(2,j+(k==0))][max(k-1,0)],f[i-1][j][k]);
		}
	}
	int ans=0;
	rep(i,0,2)rep(j,0,2)if(i>=2||j==0)addx(ans,f[n][i][j]);
	printf("%d\n",ans);
	return 0;
}