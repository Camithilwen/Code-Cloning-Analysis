#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#define itrout(x) for(int i=0;i<x.size();i++) {cout << x[i] << (i==x.size()-1 ? "\n" : " ");}
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

void solve(long long N, std::vector<long long> X, std::vector<long long> Y, std::vector<int> U){
    const int MAX_LEN = 2e5;
    const int OFFSET = 2e5;
    int answer = INT_MAX;
    rep(u,0,4) {
        vector<set<int>> lineL(MAX_LEN+1);  // lineL[y when x is 0] = all x whose direction is u+2
        vector<set<int>> lineD(2*MAX_LEN+1); // lineD[y when x is 0] = all x whose direction is u+1
        rep(i,0,N) {
            if (U[i] == (u+2) % 4) {
                lineL[Y[i]].insert(X[i]);
            } else if (U[i] == (u+1) % 4) {
                lineD[OFFSET + Y[i]-X[i]].insert(X[i]);
            }
        }
        rep(i,0,N) {
            if (U[i] != u) continue;
            // lineL
            auto itr = lineL[Y[i]].lower_bound(X[i]);
            if (itr != lineL[Y[i]].end()) {
                answer = min<int>(answer, (*itr - X[i]) * 5);
            }
            // lineD
            itr = lineD[OFFSET + Y[i]-X[i]].lower_bound(X[i]);
            if (itr != lineD[OFFSET + Y[i]-X[i]].end()) {
                answer = min<int>(answer, (*itr - X[i]) * 10);
            }
        }
        // rotate to left
        rep(i,0,N) {
            ll x = MAX_LEN - Y[i], y = X[i];
            X[i] = x;
            Y[i] = y;
        }
    }
    cout << (answer == INT_MAX ? "SAFE" : to_string(answer)) << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    std::vector<long long> X(N);
    std::vector<long long> Y(N);
    std::vector<int> U(N);
    unordered_map<char, int> direction = {{'R', 0}, {'D', 1}, {'L', 2}, {'U', 3}};
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&X[i]);
        scanf("%lld",&Y[i]);
        char c;
        std::cin >> c;
        U[i] = direction[c];
    }
    solve(N, std::move(X), std::move(Y), std::move(U));
    return 0;
}
