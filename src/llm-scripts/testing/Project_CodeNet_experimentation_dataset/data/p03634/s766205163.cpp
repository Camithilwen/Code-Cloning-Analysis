#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
typedef pair<int, int> P;

const ll INF = 1ll<<60;
typedef struct{int to, cost;} edge;
int N, Q, K;
vector<edge> G[100100];
vll d(100100, INF);

void nya(int s){
    priority_queue<P, vector<P>, greater<P> >que;
    d[s] = 0ll;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        rep(i, G[v].size()){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return;
}

int main(){
    cin >> N;
    rep(i, N)if(i){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edge tmp;
        tmp.to = b;
        tmp.cost = c;
        G[a].push_back(tmp);
        tmp.to = a;
        G[b].push_back(tmp);
    }
    cin >> Q >> K;
    nya(K - 1);
    while(Q--){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << d[x] + d[y] << endl;
    }
    return 0;
}