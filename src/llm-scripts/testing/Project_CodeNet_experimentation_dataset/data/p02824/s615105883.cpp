#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

//using Graph = vector<vector<edge>>;
using dou =long double;
string yes="yes";
string Yes="Yes";
string YES="YES";
string no="no";
string No="No";
string NO="NO";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define query int qq;std::cin >> qq;rep(qqq,qq)
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum(a) accumulate(all(a),0ll)
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
#define case std::cout <<"Case #" <<qqq+1<<": "
#define RES(a,i,j) a.resize(i);rep(ii,i)a[ii].resize(j); 
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout<<a<<" "<<b<<" "<<c<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define ssum(a) accumulate(a,0ll) 
#define gre(n) greater<n>()

typedef long long ll;
//
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
//typedef long long T;
const int INF = 1000000000;
const double dINF = 1000000000;
const ll INF64 = 922337203685477580ll;
const ll MOD = 998244353ll;
//const ll MOD = 67280421310721ll;
const dou pi=3.141592653589793;
//メモ
//二次元配列のresizeのしかた
//vv.resize(n);
//for(size_t i=0; i<n; i++){
// vv[i].resize(n);
//}

//メモ
//負の辺を持つ最短経路問題では到達不可経路でも初期化値より小さくなりうるので注意しよう
int main(){
    int n,m,v,p;
    std::cin >> n>>m>>v>>p;
    VEC(ll,a,n);
    std::vector<ll> sa(n+1);
    
    sort(all(a),gre(ll));
    rep(i,n){
        sa[i+1]=sa[i]+a[i];
    }
    int ans=p;
    int dd=a[p-1];
    rrep(i,p,n){
        ll can=a[i]+m;
        ll need=max(0ll,ll(i-(p-1))-(n-v))*m;
        bool b=0;
      //  ll d=0;
        ll dd=(i-p+1)*can-(sa[i]-sa[p-1]);
       // pppri(i,p-1,sa[i]-sa[p-1]);
        if(can<a[p-1])break;
        if(dd>=need)ans++;
        /*
        rrep(j,p-1,i){
          //  std::cout << j << std::endl;
            if(can<a[j]){
                b=1;
                break;
            }
            d+=can-a[j];
            //if(d>=need)ans++;
        }
        */
        if(b)break;
        //ppri(d,dd);
        
        
    }
    std::cout << ans << std::endl;
}