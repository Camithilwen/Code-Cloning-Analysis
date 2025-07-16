#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"---------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
						For(_x,L,R)cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> vi;
typedef long double LD;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=300005,mod=1e9+7;
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
int n;
char s[N];
int dp[N][2][3][3];
//dp[i][a][b][c]: first i char, there's a 1s, stage b, last c 0s
int main(){
	cin>>s+1;
	n=strlen(s+1);
	s[n+1]='1';
	dp[0][0][0][0]=1;
	For(i,1,n+1) For(a,0,1) For(b,0,2) For(c,0,2){
		int v=dp[i-1][a][b][c],lb,ub;
		if (!v)
			continue;
		if (s[i]=='0')
			lb=ub=0;
		else if (s[i]=='1')
			lb=ub=1;
		else
			lb=0,ub=1;
		For(now,lb,ub){
			if (now==0){
				int C=c+1;
				if (C>2)
					C-=2;
				Add(dp[i][a][b][C],v);
			}
			else if (now==1){
				if (c==1)
					Add(dp[i][a][b][0],v);
				else if (a==0&&b<2&&c==0)
					Add(dp[i][0][b+1][0],v);
				else
					Add(dp[i][a^1][b][0],v);
			}
		}
	}
	int ans=0;
	For(a,0,1) For(b,2,2) For(c,0,2)
		Add(ans,dp[n+1][a][b][c]);
	cout<<ans<<endl;
	return 0;
}