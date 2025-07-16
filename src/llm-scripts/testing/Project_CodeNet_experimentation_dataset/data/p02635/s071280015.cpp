#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int mod=998244353;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
void ckmax(int &x,int y){
	if (x<y)
		x=y;
}
void ckmin(int &x,int y){
	if (x>y)
		x=y;
}
const int N=305;
int n,k;
char s[N];
int dp[N][N][N];
int a[N],b[N];
int c0=0,c1=0;
int main(){
	cin>>(s+1);
	n=strlen(s+1);
	k=read();
//	n=300;
//	For(i,1,n)
//		s[i]=rand()%2?'1':'0';
//	k=300;
	For(i,1,n)
		if (s[i]=='1')
			c0++;
		else
			a[++c1]=c0,b[c1]=a[c1]-a[c1-1];
	k=min(k,c0);
	dp[0][0][0]=1;
//	outval(c0),outval(c1);
//	outarr(a,0,c1);
	For(i,1,c1)
		For(j,0,c0)
			For(t,0,k){
//				outval(i);
				int v=dp[i-1][j][t];
				if (!v||j<a[i-1])
					continue;
//				printf("dp[%d][%d][%d] = %d\n",i-1,j,t,v);
				int ub=min(c0-j,k-t+b[i]);
				For(now,0,ub){
					if (now<=b[i])
						Add(dp[i][j+now][t],v);
					else
						Add(dp[i][j+now][t+now-b[i]],v);
				}
			}
	int ans=0;
	For(j,a[c1],c0)
		For(t,0,k){
//			if (dp[c1][j][t])
//				printf("dp[%d][%d][%d] = %d\n",c1,j,t,dp[c1][j][t]);
			Add(ans,dp[c1][j][t]);
		}
	cout<<ans<<endl;
	return 0;
}