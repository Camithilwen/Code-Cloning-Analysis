#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 100005;

/* ...o(^-^)o... */
int main(){
    int n; cin >> n;
    string s; cin >> s;
    int o[] = {0, 3, 1, 2};
    int x[] = {1, 2, 0, 3};
    string sr[] = {"SS", "SW", "WS", "WW"};
    rep(t, 4){
        int u = t; vector<int> v;
        rep(i, n){
            v.push_back(u);
            if(s[i] == 'o') u = o[u];
            else u = x[u];
        }
        if(u != t) continue;
        string ans = "";
        rep(i, n){
            if(v[i] % 2) ans += "W";
            else ans += "S";
        }
        out(ans); return 0;
    }
    out(-1);
}
