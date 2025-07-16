#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
#define PI 3.141592653589793
#define MOD 1000000007
//#define MOD 998244353
#define ALL(obj) (obj).begin(),(obj).end()
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const ll INF = 1LL << 60;

//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main() {
    ll n,m;
    cin >> n;
    map<string,ll> red;
    map<string,ll> blue;
    for (ll i=0;i<n;i++){
        string a;
        cin >> a;
        if (blue.count(a)){
            blue[a]++;
        }else{
            blue[a]=1;
        }
    }
    cin >> m;
    for (ll i=0;i<m;i++){
        string a;
        cin >> a;
        if (red.count(a)){
            red[a]++;
        }else{
            red[a]=1;
        }

    }
    ll ans=0;
    for (auto b: blue){
        string s=b.first;
        if (blue[s]>red[s]){
            ans=max(ans,blue[s]-red[s]);
        }
    }
    cout << ans << endl;
    return 0;
}
