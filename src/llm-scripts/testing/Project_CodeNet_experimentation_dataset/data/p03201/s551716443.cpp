#include <bits/stdc++.h>
using namespace std;

#define REP(i,m,n) for(int i=(m); i<(int)(n); i++)
#define RREP(i,m,n) for(int i=(int)((n)-1); i>=m; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define fi first
#define se second
#define debug(...) {cerr<<"[L"<<__LINE__<<"] "; _debug(__VA_ARGS__);}

template<typename T>
string join(const vector<T>&v, string del=", "){ stringstream s;
    for(auto x : v) s << del << x; return s.str().substr(del.size());
}
template<typename T>
ostream& operator<<(ostream& o, const vector<T>&v){
    if(v.size()) o << "[" << join(v) << "]"; return o;
}
template<typename T>
ostream& operator<<(ostream& o, const vector<vector<T> >&vv){
    int l = vv.size();
    if(l){ o<<endl; rep(i,l) o << (i==0 ? "[ " : ",\n  " ) << vv[i] << (i==l-1 ? " ]" : ""); }
    return o;
}
template<typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p){
    return o << "(" << p.first << ", " << p.second << ")";
}
inline void _debug(){cerr<<endl;}
template<class First, class... Rest>
void _debug(const First& first, const Rest&... rest){cerr<<first<<" ";_debug(rest...);}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

const double PI = (1*acos(0.0));
const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const ll mod = 1e9 + 7;

inline void finput(string filename) {
    freopen(filename.c_str(), "r", stdin);
}

int main(){
    ios_base::sync_with_stdio(0);
    // finput("./input");
    int n; cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));

    map<int,vi> mp;
    rep(i,n) mp[a[i]].push_back(i);
    vi used(n,0);
    int ans = 0;
    rrep(i,n){
        if(used[i]) continue;
        int lsb = __builtin_ffsll(a[i]) - 1;
        int msb = (31 - __builtin_clz(a[i]));
        int x = 1 << lsb;
        REP(j,lsb,msb){
            if((a[i]&(1<<j)) == 0) x |= 1<<j;
        }
        if(mp.count(x)){
            if(mp[x].size() == 0) continue;
            if(mp[x].back() == i){
                mp[x].pop_back();
                if(mp[x].size() == 0) continue;
            }
            int idx = mp[x].back();
            used[idx] = 1;
            mp[x].pop_back();
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}