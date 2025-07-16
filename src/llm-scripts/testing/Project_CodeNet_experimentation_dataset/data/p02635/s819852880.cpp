#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=305,mod=998244353;
int f[N][N][N<<1],g[N][N<<1],h[N][N<<1];
int a[N],b[N],n,m=1,K;
char s[N];

void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int main(){
	scanf("%s",s+1),read(K);
	n=strlen(s+1),K=min(K,n);
	for(int i=1;i<=n+1;i++,m++){
		for(;i<=n&&s[i]!='0';i++,a[m]++);
		b[m]=b[m-1]+a[m];
	}
	m--;
	f[0][0][0]=1;
	rep(i,1,m){
		memset(g,0,sizeof g);
		memset(h,0,sizeof h);
		rep(j,b[i-1],b[m]){
			rep(k,0,K*2){
				if(f[i-1][j][k]){
					if(j+a[i]<=b[m]){
						add(g[j+a[i]][k],f[i-1][j][k]);
					}
					if(a[i]){
						int t=max(0,j+a[i]-1-b[m]);
						add(h[j+a[i]-1-t][k+1+t],f[i-1][j][k]);
						if(j) add(h[j-1][k+a[i]+1],mod-f[i-1][j][k]);
					}
				}
			}
		}
		rep(j,b[i-1],b[m]-1){
			rep(k,0,K*2){
				add(g[j+1][k+1],g[j][k]);
			}
		}
		per(j,b[m],b[i-1]+1){
			rep(k,0,K*2){
				add(h[j-1][k+1],h[j][k]);
			}
		}
		rep(j,b[i],b[m]){
			rep(k,0,K*2){
				add(f[i][j][k],g[j][k]);
				add(f[i][j][k],h[j][k]);
			}
		}
	}
	int ans=0;
	rep(i,0,K*2){
		add(ans,f[m][b[m]][i]);
	}
	cout<<ans<<endl;
	return 0;
}