#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<n;++i)
#define exrep(i, a, b) for(ll i = a; i < b; i++)
#define out(x) cout << x << endl
#define EPS (1e-7)
#define gearup ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<bool> > vvb;
typedef vector<vector<double> > vvd;
typedef vector<vector<string> > vvs;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;
typedef vector<vector<vector<ll> > > vvvl;
ll MOD = 1000000007;
const long long L_INF = 1LL << 60;
const int INF = 2147483647; // 2^31-1
const double PI = acos(-1);
//cout<<fixed<<setprecision(10);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T> void debug(T v){rep(i,v.size()) cout<<v[i]<<" ";cout<<endl;}
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

signed main()
{   
    gearup;
    ll n; cin >> n;
    string s; cin >> s;
    rep(bit,4){ //４通りを考える SS,SW,WS,WW S:0, W:1
        vl a(n+1);
        rep(i,2){
            if( (bit>>i) & 1)a[i] = 1;
            else a[i] = 0;
        }
        //cout << a[0] << " " << a[1] << endl;
        for(int i=1;i<n;i++){
            if(a[i] == 0 && s[i] == 'o')a[i+1] = a[i-1];
            if(a[i] == 0 && s[i] == 'x')a[i+1] = !a[i-1];
            if(a[i] && s[i] == 'o')a[i+1] = !a[i-1];
            if(a[i] && s[i] == 'x')a[i+1] = a[i-1];
        }
        //仮定したaの並びで文字列を生成する
        string res;
        rep(i,n){
            int pre = (i- 1 + n) % n;
            int next = (i + 1) % n;
            if(a[i] == 0){
                if(a[pre] == a[next])res+='o';
                else res+='x';
            }
            else{
                if(a[pre] == a[next])res+='x';
                else res+='o';
            }
        }
        //仮定が合っていたら
        if(res == s){
            rep(i,n){
                if(a[i] == 0)cout << 'S';
                else cout << 'W';
            }
            cout << endl;
            return 0;
        }
    }
    out(-1);
}
