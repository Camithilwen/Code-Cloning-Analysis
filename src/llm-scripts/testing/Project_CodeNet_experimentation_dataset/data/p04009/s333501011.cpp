#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

int n, m;
int x, y;

int a[110][110];

char buf[110];
void in(){
	read(n, m);
	for(int i=1; i<=n; ++i){
		scanf("%s", buf+1);
		for(int j=1; j<=m; ++j){
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			if(buf[j] == 'o'){
				++a[i][j];
			} else if(buf[j] == 'E'){
				x=i; y=j;
			}
		}
	}
}

int dp[102][102][102][102];

int rect(int L1, int R1, int D1, int U1, int L2, int R2, int D2, int U2){
	int L=max(L1, L2);
	int R=min(R1, R2);
	int D=max(D1, D2);
	int U=min(U1, U2);
	if(L>R || D>U) return 0;
	if(0) printf("%d %d %d %d\n", L, R, D, U);
	return a[R][U]-a[L-1][U]-a[R][D-1]+a[L-1][D-1];
}

int main()
{
	in();
	for(int w=1; w<=n; ++w){
		for(int h=1; h<=m; ++h){
			for(int l=1; l+w-1<=n; ++l){
				int r=l+w-1;
				if(x<l || r<x) continue;
				for(int d=1; d+h-1<=m; ++d){
					int u=d+h-1;
					if(y<d || u<y) continue;
					int me=dp[l][r][d][u];
					auto f = [&](int A, int B, int C, int D){
						int I=l+A;
						int J=r+B;
						int K=d+C;
						int L=u+D;
						int nv = rect(1+(r-x), n-(x-l), 1+(u-y), m-(y-d),
							(A||B)?(A?I:J):(I),
							(A||B)?(A?I:J):(J),
							(C||D)?(C?K:L):(K),
							(C||D)?(C?K:L):(L)
						);
						int& T=dp[I][J][K][L];
						if(T < me+nv){
							if(0) printf("upd from %d-%d, %d-%d to df %d %d %d %d : %d+%d = %d\n",
								l,r,d,u, A,B,C,D, me, nv, me+nv);
						}
						T=max(T, me+nv);
					};
					if(1 < l) f(-1, 0, 0, 0);
					if(r < n) f(0, 1, 0, 0);
					if(1 < d) f(0, 0, -1, 0);
					if(u < m) f(0, 0, 0, 1);
				}
			}
		}
	}
	printf("%d\n", dp[1][n][1][m]);
	return 0;
}
