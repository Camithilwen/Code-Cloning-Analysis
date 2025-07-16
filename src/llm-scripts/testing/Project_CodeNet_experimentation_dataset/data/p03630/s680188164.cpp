#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pa;
typedef unsigned int uint;
typedef unsigned long long ull;
#define w1 first
#define ls (x<<1)
#define w2 second
#define ins insert
#define rs (x<<1|1) 
#define mp make_pair
#define pb push_back
#define mid ((l+r)>>1)
#define sqr(x) ((x)*(x))
#define cle(x) ((x).clear())
#define lowbit(x) ((x)&(-x))
#define SZ(x) (int((x).size()))
#define ms(x,y) memset(x,y,sizeof (x))
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep2(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define per(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define Rep(p,x) for(int (p)=head[(x)];(p);(p)=nxt[(p)]) 
#define Rep2(p,x) for(int (p)=cur[(x)];(p);(p)=nxt[(p)])
template<class T>inline void read(T&num){
	num=0;T f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	num*=f;
}
inline int getgcd(int x,int y){if(!x)return y;return getgcd(y%x,x);}
inline int power(int x,int k,int p){int res=1;for(;k;k>>=1,x=(ll)x*x%p)if(k&1)res=(ll)res*x%p;return res;}
const double pi=acos(-1);	
inline void judge(){
	freopen("input.txt","r",stdin);
} 
//********************************head*************************************
const int maxn=2e3+5;
int n,m,top,ans;
char str[maxn][maxn];
int a[maxn][maxn],h[maxn][maxn],L[maxn],R[maxn];
pa st[maxn];
int main(){
	read(n);read(m);
	rep(i,1,n)scanf("%s",str[i]+1);
	rep(i,1,n-1)rep(j,1,m-1){
		int cnt=0;
		cnt+=(str[i][j]=='.');
		cnt+=(str[i+1][j]=='.');
		cnt+=(str[i][j+1]=='.');
		cnt+=(str[i+1][j+1]=='.');
		a[i][j]=!(cnt&1);
	}
	rep(i,1,n-1)rep(j,1,m-1){
		if(a[i][j])h[i][j]=h[i-1][j]+1;
		else h[i][j]=0;
	}
	ans=max(n,m);
	rep(i,1,n-1){
		st[top=1]=mp(0,-1);
		rep(j,1,m-1){
			while(top&&st[top].w2>=h[i][j])top--;
			L[j]=st[top].w1+1;
			st[++top]=mp(j,h[i][j]);
		}
		st[top=1]=mp(m,-1);
		per(j,m-1,1){
			while(top&&st[top].w2>=h[i][j])top--;
			R[j]=st[top].w1-1;
			st[++top]=mp(j,h[i][j]);
		}
		rep(j,1,m-1)ans=max(ans,(h[i][j]+1)*(R[j]-L[j]+2));
	}
	printf("%d\n",ans);
	return 0;
}