#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(){
	T f=0,x=0;char c=getchar();
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return f?-x:x;
}
namespace run{
	const int N=6009;int mod;
	inline int add(int x,int y){return x+y>=mod?x-mod+y:x+y;}
	int f[N][(N<<1)+3],n;
	int main(){
		n=read<int>()*3,mod=read<int>();
		f[0][N]=1;
		for(int i=0;i<n;i++)
			for(int j=-i;j<=i;j++){
				f[i+1][j+1+N]=add(f[i+1][j+1+N],f[i][j+N]);
				f[i+2][j-1+N]=add(f[i+2][j-1+N],1LL*f[i][j+N]*(i+1)%mod);
				f[i+3][j+N]=add(f[i+3][j+N],1LL*f[i][j+N]*(i+1)%mod*(i+2)%mod);
			}

		int ans=0;
		for(int j=0;j<=n;j++) ans=add(ans,f[n][j+N]);
		printf("%d\n",ans);
		return 0;
	}
}
int main(){
#ifdef my
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	return run::main();
}