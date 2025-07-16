#include<cstdio>
#define C(x,y) (fct[x]*ifct[y]%TT*ifct[(x)-(y)]%TT)
using namespace std;
const int maxn=2005,TT=1e9+7;
int n,K,m,F[maxn][maxn];
long long fct[maxn*maxn],ifct[maxn*maxn];
inline int read(){
	int ret=0;bool f=0;char ch=getchar();
	while(ch>'9'||ch<'0') f^=ch=='-',ch=getchar();
	while(ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return f?-ret:ret;
}
inline long long pow(int x,int y){
	long long ret=1,w=x;
	while(1){
		if(y&1) ret=ret*w%TT;
		if(!(y>>=1)) return ret;
		w=w*w%TT;
	}
}
inline void add(int&x,int y){if((x+=y)>=TT) x-=TT;}
int main(){
	n=read(),K=read();m=n*K;
	if(K==1) return puts("1")&0;
	for (int i=fct[0]=1;i<=m;i++) fct[i]=fct[i-1]*i%TT;
	ifct[m]=pow(fct[m],TT-2);
	for (int i=m;i;i--) ifct[i-1]=ifct[i]*i%TT;
	F[0][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=i;j++){
		if(j<i) add(F[i][j],F[i-1][j]);
		if(j) add(F[i][j],C(m-i-(j-1)*(K-1)-1,K-2)*F[i][j-1]%TT);
	}
	printf("%lld\n",fct[n]*F[n][n]%TT);
	return 0;
}