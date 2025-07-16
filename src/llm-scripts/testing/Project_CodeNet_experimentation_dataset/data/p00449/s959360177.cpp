#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> plli;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const ll mod = 1e9 + 7;
const ll INF = 1<<30;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

int n, k;

struct edge{int to, cost;};

vector<ll> dijkstra(int s, int n, vector<vector<edge>>& g){
    priority_queue<plli, vector<plli>, greater<plli>> que;
    vector<ll> d(n, LLONG_MAX/10); d[s] = 0;
    que.push(plli(0, s));

    while (!que.empty()){
        plli p = que.top();que.pop();
        int fr = p.second;
        if (d[fr] < p.first) continue;
        for (edge e: g[fr]){
            if (d[e.to] > d[fr] + e.cost){
                d[e.to] = d[fr] + e.cost;
                que.push(plli(d[e.to], e.to));
            }
        }
    }
    return d;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (true) {
        cin >> n >> k;
        if (n == 0) break;
        vector<vector<edge>> g(100 + 5);
        rep(i, k) {
            int  a, b, c, d, e, com;
            cin >> com;
            if (com == 0) {
                cin >> a >> b;
                a--; b--;
                vector<ll> dist = dijkstra(a, n, g);
                if (dist[b] == LLONG_MAX / 10) cout << -1 << endl;
                else cout << dist[b] << endl;
            }
            else {
                cin >> c >> d >> e;
                c--; d--;
                g[c].push_back(edge{d, e});
                g[d].push_back(edge{c, e});
            }
        }
    }
}