#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define N 4005
int n,k,c[N][N],pw[N];
const int mod=998244353;
inline void reduce(int&x){x-=mod,x+=x>>31&mod;}
inline int upd(int x){return reduce(x),x;}
inline void init(int n=4000){
	pw[0]=c[0][0]=1;
	rep(i,1,n){
		c[i][0]=c[i][i]=1;
		rep(j,1,i-1) c[i][j]=upd(c[i-1][j]+c[i-1][j-1]);
	}
	rep(i,1,n) pw[i]=upd(pw[i-1]<<1);
}
inline int solve(int A,int B,int C,int ret=0){
	if(B<0) return 0;
	rep(i,std::max(0,1-B),std::min(A,C))
		(ret+=1ll*c[A][i]*pw[i]%mod*c[B+C-1][B+i-1]%mod)%=mod;
	return ret;
}
int main(){
	std::cin>>k>>n;
	init();
	rep(i,2,k<<1){
		int l=std::max(i-k,1),r=std::min(i-1,k);
		int now=r-l+1,ret=0;
		if(now<0) now=0;
		if(i&1) ret=solve(now>>1,k-now,n);
		else
			ret=upd(solve(now-1>>1,k-now,n)+solve(now-1>>1,k-now,n-1));
		std::cout<<ret<<'\n';
	}
	return 0;
}