#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

template<int row,int col>
struct BinaryMatrix{
    bitset<col> dat[row];
    int r,c;
    BinaryMatrix(size_t r,size_t c):r(r),c(c){}
    bitset<col> &operator[](int i){return dat[i];}
    const bitset<col> &operator[](int i) const{return dat[i];}
    void Gauss_Jordan(int extended=0){
        vector<int> used(r,0);
        for (int j=0;j<c;++j){
            if (extended&&j==c-1) break;
            int p=-1;
            for (int i=0;i<r;++i){
                if (!used[i]&&dat[i][j]){p=i; break;}
            }
            if (p==-1) continue;
            for (int i=0;i<r;++i){
                if (i!=p&&dat[i][j]) dat[i]^=dat[p];
            }
            used[p]=1;
        }
    }
};

const int MAX_N=1e5+10,MAX_B=61;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    vector<int> cnt(MAX_B,0),can(MAX_B,0);
    ll ans=0;
    BinaryMatrix<MAX_B,MAX_N+1> BM(MAX_B,N+1);
    for (int i=MAX_B-1;i>=0;--i){
        rep(j,N) if (A[j]&(1LL<<i)) ++cnt[i];
        if (cnt[i]&1) ans+=1LL<<i;
        else if (cnt[i]>0){
            can[i]=1;
            rep(j,N) if (A[j]&(1LL<<i)) BM[MAX_B-1-i][j]=1;
            BM[MAX_B-1-i][N]=1;
        }
    }
    BM.Gauss_Jordan(1);
    rep(i,MAX_B){
        if (!can[MAX_B-1-i]) continue;
        int ok=0;
        rep(j,N) if (BM[i][j]==1) ok=1;
        if (BM[i][N]==0) ok=1;;
        if (ok) ans+=(2LL<<(MAX_B-1-i));
    }
    cout << ans << endl;
}