#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N;
ll A[200010];

signed main(){
    cin >> N;
    REP(i, N) cin >> A[i];
    REP(i, N){
        if(i < A[i] || A[i] + 1 < A[i + 1]){
            PRINT("-1");
            return 0;
        }
    }
    ll ans = 0;
    for(int i = N - 1; i > 0; i--){
        if(A[i - 1] < A[i]){
            ans++;
        }else{
            ans += A[i];
        }
    }
    PRINT(ans);
    return 0;
}