#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    LL N;cin >> N;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];

    vector<LL> num(N);
    rep(i,N){
        num[i] = i - A[i];
    }
    bool ok = true;
    if(num[0] != 0)ok = false;
    rep(i,N-1){
        if(A[i+1] - A[i] > 1)ok = false;
    }

    if(ok){
        LL ans = 0;
        rep(i,N){
            if(binary_search(all(num),i)){
                LL k = upper_bound(all(num),i) - num.begin() - 1;
                ans += (k-i);
            }
        }
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
}