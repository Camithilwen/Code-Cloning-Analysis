#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define debug(x) cout << #x << '=' << x << '\n'
const long long MOD=1e9+7;
//const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    cout << '(' << p.first << ',' << p.second << ')';
    return os;
}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}

vector<ll> po(19,1);

ll calc(int i,int j,ll e){
    if (j>i-1-j) return (e==0?1:0);
    ll res=0;
    int diff=(j==i-1-j?0:e/(po[i-1-j]-po[j]));
    for (ll d=diff-1;d<=diff+1;++d){
        if (j==i-1-j&&d!=0) continue;
        ll ne=e-(po[i-1-j]-po[j])*d;
        if (ne<-(po[i-1-j]-po[j])||po[i-1-j]-po[j]<ne) continue;
        for (int k=(!j?1:0),cnt=0;k<10;++k){
            if (k+d>=0&&k+d<10) ++cnt;
            if (k==9) res+=calc(i,j+1,ne)*cnt;
        }
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    for (int i=0;i<18;++i) po[i+1]=po[i]*10;
    ll D; cin >> D;
    ll ans=0;
    for (int i=2;i<=19;++i){
        ans+=calc(i,0,D);
    }
    cout << ans << '\n';
}