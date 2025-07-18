//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int h, w, k;
    cin >> h >> w >> k;

    vector<ll> dp(w + 2);
    dp[1] = 1;

    for(int i = 1; i <= h; i++){

        vector<ll> dp2(w + 2);
        for(int j = 1; j <= w; j++){

            for(int t = 0; t < (1 << (w - 1)); t++){
//                cerr << "test " << t << "\n";
                t <<= 1;
                bool tmp = true;
                for(int l = 1; l < w; l++){
                    if((t & (1 << l)) && (t & (1 << (l + 1)))) tmp = false;
                }
//                cerr << "test " << t << " " << tmp << "\n";
                if(tmp){
//                cerr << t << "\n";
                    if(!(t & (1 << j)) && !(t & (1 << (j - 1)))) dp2[j] += dp[j];
                    if(t & (1 << (j - 1))) dp2[j] += dp[j - 1];
                    if(t & (1 << j)) dp2[j] += dp[j + 1];
                    dp2[j] %= MOD;
                }
                t >>= 1;
            }
        }
        dp = dp2;
//        printv(dp, cerr);
    }

    cout << dp[k] << "\n";

    return 0;
}