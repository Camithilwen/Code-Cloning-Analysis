#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x); REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
string strReplace(string s,string target, string replacement){
    if (!target.empty()) {
      std::string::size_type pos = 0;
      while ((pos = s.find(target, pos)) != std::string::npos) {
        s.replace(pos, target.length(), replacement);
        pos += replacement.length();
      }
    }
    return s;
}
const ll MOD = 998244353;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair

struct UnionFind{
    vector<ll> par,s,b,w;
    UnionFind(ll N) : par(N),s(N),b(N),w(N){
        REP(i,N){
            par[i] = i;
            b[i] = 0;
            w[i] = 0;
            s[i] = 0;
        }
    }
    int root(int x){
        if(par[x]==x){ return x; }
        else{ 
          par[x]= root(par[x]);
          return par[x];
        }
    }
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if( rx!=ry ){
            par[rx] = ry;
            s[ry] += s[rx];
            w[ry] += w[rx];
            b[ry] += b[rx];
        }
    }

    void coloring(int x,char c){
        int rx = root(x);
        if(c=='.'){
            w[rx] += 1;
        }else{
            b[rx] += 1;
        }
    }
    ll solve(int rx){
        return w[rx]*b[rx];
    }
};

int main(){
    int H,W; cin>>H>>W;
    string board[H]; CINA(board,H);
    UnionFind uf(H*W);
    REP(i,H){
        REP(j,W){
            uf.coloring(i*W+j,board[i][j]);
        }
    }
    REP(i,H){
        REP(j,W){
            if(i+1<H){
                if(board[i][j]!=board[i+1][j]){
                    uf.unite(i*W+j,(i+1)*W+j);
                }
            }
            if(j+1<W){
                if(board[i][j]!=board[i][j+1]){
                    uf.unite(i*W+j,i*W+j+1);
                }
                
            }
        }
    }
    ll ans = 0;
    map<int,int> mp;
    REP(x,H*W){
        int rx = uf.root(x);
        if(mp[rx]==0){
            ++mp[rx];
            ans += uf.solve(rx);
        }
        
    }
    cout << ans << "\n";
    
    
}