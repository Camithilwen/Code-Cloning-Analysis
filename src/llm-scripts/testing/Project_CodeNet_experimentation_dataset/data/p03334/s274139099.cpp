#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int MAXN = 100010;
const int INF = 2147483600;

int N,D1,D2;
bool Vis[710][710];

inline void solve(int P){
	int K=0; while(P%4==0) P>>=2,K++;
	if(P%4==3) return ;
	if(P%4==1) {
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				Vis[i][j]&=((((i>>K)^(j>>K))&1)^1);
	} else{
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++) 
				Vis[i][j]&=(((i>>K)&1)^1);
	} return ;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),D1=read(),D2=read();
	int cnt=N*N;
	N<<=1; memset(Vis,1,sizeof(Vis));
	solve(D1); solve(D2); 
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Vis[i][j]){
				printf("%d %d\n",i,j); --cnt;
				if(!cnt) return 0;
			}
		}
	}
	return 0;
}


