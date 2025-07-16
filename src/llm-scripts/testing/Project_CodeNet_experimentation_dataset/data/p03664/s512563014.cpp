#include<cstdio>
const int inf=1<<29;
int N,M;
int G[15][15],g[1<<15],f[1<<13][15];
void cmax(int&a,int b){b>a?a=b:1;}
int main(){
	scanf("%d%d",&N,&M);
	while(M--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a,--b;
		G[a][b]=G[b][a]=c;
	}
	for(int S=1;S<1<<N;S++){
		int i=N;while(!(S>>i&1))i--;
		g[S]=g[S-(1<<i)];
		for(int j=i;j--;)if(S>>j&1)g[S]+=G[i][j];
	}
	int ans=-inf;
	for(int S=0;S<1<<N-2;S++){
		for(int i=1;i<N;i++)if(S>>i-1&1){
			int F=-inf;
			for(int T=S;T;T=T-1&S)
				if(T>>i-1&1)cmax(F,f[S-T][i]+g[T<<1]);
			f[S][i]=F;
			if(G[0][i])cmax(ans,F+g[(1<<N-1)-1-S*2]+G[0][i]);
		}
		for(int i=1;i<N;i++)if(!(S>>i-1&1)){
			int F=-inf;
			for(int j=1;j<N;j++)if((S>>j-1&1)&&G[i][j])cmax(F,f[S][j]+G[i][j]);
			if(G[i][N-1])cmax(F,g[S<<1|1<<N-1]+G[i][N-1]);
			f[S][i]=F;
		}
		if(G[0][N-1])cmax(ans,g[S<<1|1<<N-1]+g[(1<<N-1)-1-S*2]+G[0][N-1]);
	}
	printf("%d\n",g[(1<<N)-1]-ans);
}