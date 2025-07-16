#include<bits/stdc++.h>
#define ll long long
#define re register
#define ull unsigned ll
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*t;
}
const int N=41;
const int M=(1<<17)+5;
const int P=1e9+7;
int n,A,B,C,D,U,tr[M][11],f[N][M];
int Mod(int x){return x>=P?x-P:x;}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(),A=read(),B=A+read(),C=B+read(),U=(1<<C);
	for(int S=1;S<=U;S++)
	for(int i=1;i<=10;i++){
		tr[S][i]=1;
		for(int j=0;j<=C;j++)if(S>>j&1){
			if(j<A&&j+i>A)continue;
			if(j<B&&j+i>B)continue;
			if(j+i<=C)tr[S][i]|=1<<(j+i);
		}if((S==U)||(tr[S][i]>=U))tr[S][i]=U;
	}f[0][1]=1;
	for(int i=1;i<=n;i++)
	for(int S=1;S<=U;S++)
	for(int j=1;j<=10;j++)f[i][tr[S][j]]=Mod(f[i][tr[S][j]]+f[i-1][S]);
	printf("%d",f[n][U]);
	return 0;
}
