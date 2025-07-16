#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()
#define mp(a, b) make_pair(a, b)

const int MOD = 1e9+7;
const int INF = 1001001001;
const ll llINF = 1e18+9;
vector<pii> edge[100010];


int main(){
    int N;
    cin >> N;
    rep(i, 0, N-1){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a-1].push_back(mp(b-1, c));
        edge[b-1].push_back(mp(a-1, c));
    }
    int Q, K;
    cin >> Q >> K;
    K--;
    vector<ll> dist(N, llINF);
    dist[K] = 0;
    queue<pair<int, ll>> q;
    q.push(mp(K, 0));
    while (!q.empty()){
        int now = q.front().first;
        ll nowd = q.front().second;
        q.pop();
        for (auto x:edge[now]){
            int fol = x.first;
            ll d = x.second;
            ll nextd = nowd+d;
            if (dist[fol] < nextd) continue;
            dist[fol] = nextd;
            q.push({fol, nextd});
        }
    }
    rep(i ,0 , Q){
        int x, y;
        cin >> x >> y;
        --x, --y;
        ll ans = dist[x] + dist[y];
        cout << ans << endl;
    }
}