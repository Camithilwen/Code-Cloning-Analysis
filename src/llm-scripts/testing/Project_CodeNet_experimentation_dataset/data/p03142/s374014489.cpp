#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
const ll INF = 1e16;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    ll N, M;
    cin >> N >> M;
    vvc<ll> E(N), R(N);
    vc<ll> inn(N); //根なら0のまま
    rep(i,N-1+M){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        E[a].eb(b);
        inn[b]++;
    }
    ll root;
    rep(i, N) if (inn[i]==0){
        root = i;
        break;
    }

    vl dep(N), ans(N), cnt(N);
    queue<ll> q;
    q.emplace(root);
    while(!q.empty()){
        ll now = q.front();
        q.pop();
        cnt[now]++;
        if (cnt[now] < inn[now]) continue; //親から辿られきられていないなら飛ばす
        for(auto to:E[now]){
            dep[to] = dep[now] + 1;
            ans[to] = now+1;
            q.emplace(to);
        }
    }
    rep(i, N) cout << ans[i] << "\n";
}