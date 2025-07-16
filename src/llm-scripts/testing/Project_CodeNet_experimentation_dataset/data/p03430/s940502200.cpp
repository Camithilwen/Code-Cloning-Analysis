#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 303;
char s[N];
int n,k,f[N][N][N];
inline void umax(int &a, int b) {a=a>b?a:b;}
int main() {
	scanf("%s",s+1); read(k); n=strlen(s+1);
	rep(i,1,n) f[i][i][0]=1; int ans=0;
	rep(l,-1,n-1) rep(i,1,n) {
		int j=i+l; if (j>n) break;
		rep(K,0,k) {
			int v=f[i][j][K]; umax(ans,v);
			umax(f[i][j+1][K],v); umax(f[i-1][j][K],v);
			umax(f[i-1][j+1][K+(s[i-1]!=s[j+1])],v+2);
		}
	}
	printf("%d",ans);
	return 0;
}
