#include<bits/stdc++.h>
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pi(x) printf("%d",x)
#define pl(x) printf("%lld",x)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define re register
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define per(i,n,m) for(int i=m;i>=n;i--)
#define rrep(i,m,n) for(register int i=m;i<=n;i++)
#define rper(i,n,m) for(register int i=m;i>=n;i--)
#define ull unsigned  long long
using namespace std;
const int INF =1e9+10;
const int N = 1e3 + 10;
int n,d1,d2,cnt;
int a[N][N];
void solve(int x){
    int tmp=0;
    while(x%4==0){
        x/=4;
        tmp++;
    }
    if(x&1){
        rep(i,0,n*2-1){
            rep(j,0,n*2-1){
                if(((i>>tmp)+(j>>tmp))&1){
                    a[i][j]=1;
                }
            }
        }
    }else{
        rep(i,0,n*2-1){
            rep(j,0,n*2-1){
                if(((i>>tmp))&1){
                    a[i][j]=1;
                }
            }
        }
    }
}
signed main() {
    si(n);
    si(d1);
    si(d2);
    solve(d1);
    solve(d2);
    rep(i,0,n*2-1){
        rep(j,0,n*2-1){
            if(cnt<n*n&&!a[i][j]){
                printf("%d %d\n",i,j);
                cnt++;
            }
        }
    }
    return 0;
}
