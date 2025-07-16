#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 1e18
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin>>N>>S;

    string mae,ushi;
    mae = S.substr(0,N);
    ushi = S.substr(N,N);

    map<pair<string,string>,ll> mp;
    //後ろ半分の文字列(反転させる)
    for(int i=0;i<(1<<N);i++){
        string a="",b="";
        for(int j=0;j<N;j++){
            if(i>>j & 1) a += ushi[j];
            else b += ushi[j];
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        auto p = make_pair(a,b);
        ++mp[p];
    }

    ll res = 0;
    for(int i=0;i<(1<<N);i++){
        string a="",b="";
        for(int j=0;j<N;j++){
            if(i>>j & 1) a += mae[j];
            else b += mae[j];
        }
        auto p = make_pair(a,b);
        res += mp[p];
    }
    cout<<res<<endl;
}
