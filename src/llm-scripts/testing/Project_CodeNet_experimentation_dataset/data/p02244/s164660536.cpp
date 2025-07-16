#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
string s[8];
int ng[8][8];
bool flg;
void dfs(int r){
    if(r==8){
        flg=1;
        return;
    }
    for(int c=0;c<8;c++){
        if(s[r][c]=='Q'){
            dfs(r+1);
            return;
        }
    }
    for(int c=0;c<8;c++){
        if(ng[r][c])continue;
        s[r][c]='Q';
        for(int j=0;j<8;j++){
            if(r+j<8)ng[r+j][c]++;
            if(r-j>=0)ng[r-j][c]++;
            if(c+j<8)ng[r][c+j]++;
            if(c-j>=0)ng[r][c-j]++;
            if(r+j<8&&c+j<8)ng[r+j][c+j]++;
            if(r+j<8&&c-j>=0)ng[r+j][c-j]++;
            if(r-j>=0&&c+j<8)ng[r-j][c+j]++;
            if(r-j>=0&&c-j>=0)ng[r-j][c-j]++;
        }
        dfs(r+1);
        if(flg)return;
        s[r][c]='.';
        for(int j=0;j<8;j++){
            if(r+j<8)ng[r+j][c]--;
            if(r-j>=0)ng[r-j][c]--;
            if(c+j<8)ng[r][c+j]--;
            if(c-j>=0)ng[r][c-j]--;
            if(r+j<8&&c+j<8)ng[r+j][c+j]--;
            if(r+j<8&&c-j>=0)ng[r+j][c-j]--;
            if(r-j>=0&&c+j<8)ng[r-j][c+j]--;
            if(r-j>=0&&c-j>=0)ng[r-j][c-j]--;
        }
    }
}
int main(){
    rep(i,8)s[i]=string(8,'.');
    int n;cin>>n;
    memset(ng,0,sizeof(ng));
    for(int i=0;i<n;i++){
        int r,c;cin>>r>>c;
        s[r][c]='Q';
        for(int j=0;j<8;j++){
            if(r+j<8)ng[r+j][c]++;
            if(r-j>=0)ng[r-j][c]++;
            if(c+j<8)ng[r][c+j]++;
            if(c-j>=0)ng[r][c-j]++;
            if(r+j<8&&c+j<8)ng[r+j][c+j]++;
            if(r+j<8&&c-j>=0)ng[r+j][c-j]++;
            if(r-j>=0&&c+j<8)ng[r-j][c+j]++;
            if(r-j>=0&&c-j>=0)ng[r-j][c-j]++;
        }
    }
    flg=0;
    dfs(0);
    rep(i,8)cout<<s[i]<<endl;
    return 0;
}
