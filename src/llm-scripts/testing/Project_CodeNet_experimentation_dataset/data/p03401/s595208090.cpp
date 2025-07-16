#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;

int ans = 100000000;

int main(){
    int N; cin >> N;
    vector<int> A(N,0);
    rep(i,N) cin >> A[i];

    vector<int> A2(N+2,0);
    rep(i,N) A2[i+1] = A[i];
    A2[N+1] = 0;

    ll total = 0;
    rep(i,N+1){
        total += abs(A2[i] - A2[i+1]);
    }
    
    ll ans;
    rep(i,N){
        ans = total - abs(A2[i]-A2[i+1]) - abs(A2[i+1]-A2[i+2]) + abs(A2[i]-A2[i+2]);
        cout << ans << endl;
    }    
}
