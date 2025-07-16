#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define qwq(x) cout<<"# "<<#x<<" = "<<x<<endl;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define f(x,y) g[(x)][(y)+52]
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1005;
int f[N][N],n,d1,d2,cnt;

void doit(int d){
	int k=1;
	while(d%4==0)d>>=2,k<<=1;
	REP(i,n*2)REP(j,n*2)
		f[i][j]+=(d&1)&&(i/k+j/k)%2==0||!(d&1)&&i/k%2==0;
}

int main(){
	read(n),read(d1),read(d2);
	doit(d1),doit(d2);
	REP(i,n*2)REP(j,n*2)
		if(f[i][j]==2&&cnt<n*n)
			printf("%d %d\n",i,j),++cnt;
	return 0;
}