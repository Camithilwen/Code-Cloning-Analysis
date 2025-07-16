#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

const ll INF = 100100100100100100;
const ll MAX_V = 1000;
const ll MAX_E = 1000;
vector<vector<ll>> cost(MAX_V,vector<ll>(MAX_E,INF));

struct edge{
    // Dijkstraでは隣接リストを用いるのでfromはいらない
    // int from;
    int to;
    int c;

    public:
    edge(ll to, ll c){
        this->to = to;
        this->c = c;
    }
};

// 集合Xからの辺の最小コスト
vector<ll> mincost(MAX_V);

ll prim(const ll &V, const vector<vector<edge>> &ed){
    // V:頂点数

    ll res = 0;
    vector<bool> used(V+5,false);
    priority_queue<P, vector<P>, greater<P>> pq; // first:その頂点を接続するのに必要なコスト ,second:頂点番号
    P ps;
    ps.first = 0;
    ps.second = 0;
    pq.push(ps);
    // pq.push(P(0,0)):

    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        if(used[p.second]) continue; // もう集合Xに入っていたら無視
        used[p.second] = true;
        res += p.first; // priorityQueueを用いていることで必ず最適な辺を取得することができる．
        for(edge e : ed[p.second]){
            if(!used[e.to]) pq.push({e.c,e.to});
        }
    }

    return res;
}

int main(){
    ll V;
    cin >> V;

    vector<vector<edge>> ed(V);
    vector<P> X;
    vector<P> Y;
    rep(i,V){
        ll x,y; cin >> x >> y;
        X.push_back(P(x,i));
        Y.push_back(P(y,i));
    }
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    rep(i,V-1){
        ll z1, z2 ,c, from, to;
        z1 = X[i].first; 
        z2 = X[i+1].first;
        c = abs(z1-z2);
        from = X[i].second; 
        to = X[i+1].second;
        edge e(from,c);
        edge re(to,c);
        ed[to].push_back(e);
        ed[from].push_back(re);
    }
    rep(i,V-1){
        ll z1, z2 ,c, from, to;
        z1 = Y[i].first; 
        z2 = Y[i+1].first;
        c = abs(z1-z2);
        from = Y[i].second; 
        to = Y[i+1].second;
        edge e(from,c);
        edge re(to,c);
        ed[to].push_back(e);
        ed[from].push_back(re);
    }

    // rep(i,V){
    //     cout << i << " :" << endl;
    //     rep(j,ed[i].size()){
    //         cout << ed[i][j].to << " " << ed[i][j].c << endl;
    //     }
    // }

    cout << prim(V, ed) << endl;
    return 0;
}