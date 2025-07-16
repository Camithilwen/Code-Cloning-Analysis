#include<set>    
#include<map>    
#include<stack>    
#include<ctime>    
#include<cstdio>    
#include<queue>    
#include<cmath>    
#include<vector>    
#include<cstring>   
#include<climits>    
#include<iostream>   
#include<algorithm>
using namespace std;
#define LL long long
int read(){
    int f=1,x=0;char c=getchar();
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
    return f*x;
}
#define MAXN 12000
#define INF 0x3f3f3f3f
int Mod;
int Pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1) ret=1ll*ret*x%Mod;
		x=1ll*x*x%Mod,y>>=1;
	}
	return ret;
}
int f[MAXN+5][MAXN+5],inv[MAXN+5];
int main(){
	int n=read(),O=3*n;
	Mod=read();
	for(int i=1;i<=3*n;i++)
		inv[i]=Pow(i,Mod-2);
	f[0][O]=1;
	for(int i=1;i<=3*n;i++)
		for(int j=0;j<=6*n;j++){
			f[i][j]+=f[i-1][j-1];
			if(f[i][j]>=Mod) f[i][j]-=Mod;
			if(i>=2)
				f[i][j]+=f[i-2][j+1];
			if(f[i][j]>=Mod) f[i][j]-=Mod;
			if(i>=3)
				f[i][j]+=f[i-3][j];
			if(f[i][j]>=Mod) f[i][j]-=Mod;
			f[i][j]=1ll*f[i][j]*inv[i]%Mod;
		}
	int ans=0,n3=1;
	for(int i=1;i<=3*n;i++)
		n3=1ll*n3*i%Mod;
	for(int i=O;i<=6*n;i++)
		ans=(ans+1ll*n3*f[3*n][i]%Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}
