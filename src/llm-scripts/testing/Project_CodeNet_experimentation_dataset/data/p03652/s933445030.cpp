#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N, M;
    cin >> N >> M;
    int A[N][M];
    rep(i, N) rep(j, M) {cin >> A[i][j]; A[i][j]--;}
    //(l,r]
    int l = 0, r = N;
    while(r-l > 1){
        int n = (l+r)/2;
        vector<int> cnt(M, 0), now(N, 0);
        vector<bool> used(M, false);
        bool able = true;
        while(true){
            rep(i, N){
                while(now[i] < M && used[A[i][now[i]]]) now[i]++;
                if(now[i] == M) able = false;
                else cnt[A[i][now[i]]]++;
            }
            bool update = false;
            rep(i, M){
                if(cnt[i] > n) update = true, used[i] = true;
            }
            fill(all(cnt), 0);
            if(!update) break;
        }
        if(able) r = n;
        else l = n;
    }
    cout << r << endl;
}