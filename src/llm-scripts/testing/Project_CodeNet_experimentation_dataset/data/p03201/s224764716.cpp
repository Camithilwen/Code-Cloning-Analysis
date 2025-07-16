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
const int MAX = 200005;

/* ...o(^-^)o... */

int main(){
    int n; cin >> n;
    vector<lint> vec; map<lint, int> mp;
    rep(i, n){
        lint x; cin >> x;
        vec.push_back(x); mp[x]++;
    }
    sort(all(vec));

    lint res = 0;
    repr(i, n){
        if(mp[vec[i]] == 0) continue;
        lint s = 1;
        while(s <= vec[i]) s *= 2;
        s -= vec[i];

        if(s == vec[i] && mp[s] > 1){
            mp[s] -= 2; res++;
        }
        if(s != vec[i] && mp[s] > 0){
            mp[vec[i]]--; mp[s]--; res++;
        }
    }
    out(res);
}