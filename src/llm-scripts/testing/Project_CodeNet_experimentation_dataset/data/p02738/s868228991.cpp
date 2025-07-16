#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define mem(a,k) memset(a,k,sizeof(a))
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

#ifdef CURIOUSCAT
#define Pr(f,...) fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)
#else
#define Pr(f,...)
#endif

typedef long long ll;

template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

const int N=1e6+50;

int P;
int mul(int a,int b){ return 1ll*a*b%P; }
int add(int a,int b){ a+=b; return a>=P?a-P:a; }
void upd(int &a,int b) { a=a+b>=P?a+b-P:a+b; }
int sub(int a,int b){ a-=b; return a<0?a+P:a; }
int gcd(int a,int b){ return !b?a:gcd(b,a%b); }

int C(int n,int m) { 
	if(m<0||m>n)return 0;
	if(m==0)return 1;
	if(m==1)return n;
	if(m==2)return n&1?mul(n,(n-1)/2):mul(n/2,n-1);
}

int n,dp[6005][2005],ans;
int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
#endif
	read(n); read(P); 
	dp[0][0]=1;
	rep(i,0,n*3)rep(j,0,n){
		upd(dp[i+1][j],dp[i][j]); 
		upd(dp[i+2][j+1],mul(dp[i][j],C(i+1,1))); 
		upd(dp[i+3][j+1],mul(dp[i][j],mul(C(i+2,2),2))); 
	}
	rep(j,0,n)ans=add(ans,dp[n*3][j]); 
	cout<<ans<<endl;
	return 0; 
}
