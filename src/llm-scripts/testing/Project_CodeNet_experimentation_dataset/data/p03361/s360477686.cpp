#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll h,w; cin>>h>>w;
    char s[h][w];
    rep(i,h)rep(j,w) cin>>s[i][j];

    ll di[]={1,0,-1,0},dj[]={0,1,0,-1};
    bool ok=true;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='.') continue;
            bool ok2=false;
            rep(k,4){
                ll ni=i+di[k],nj=j+dj[k];
                if(ni<0||h<=ni||nj<0||w<=nj) continue;
                if(s[i][j]=='#' && s[ni][nj]=='#') ok2=true;
            }
            if(!ok2){
                ok=false;
                break;
            }
        }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}