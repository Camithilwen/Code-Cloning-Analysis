#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

//N点連結グラフの二部グラフ判定
//Gはグラフの隣接リスト表現
//colorは大きさNの配列。二部グラフだったとき、独立集合がここに返ってくる
//vは探索を始める点。cは探索を始める点に塗る色
//vと同じ独立集合に含まれる点はcに塗られ、そうでない点は-cに塗られる
//colorは先に0で埋めておく
bool is_bipartite_graph (vector<vector<int>> &G, vector<int> &color, int v, int c){
    color[v] = c;
    for (int next_v : G[v]){
        if(color[next_v] == c){
            return false;
        }
        if(color[next_v] == 0 && !is_bipartite_graph(G, color, next_v, -c)){
            return false;
        }
    }
    return true;
}


int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y; x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<int> color(N, 0);
    if(is_bipartite_graph(G, color, 0, 1)){
        ll a, b;
        a = 0; b = 0;
        for (int i = 0; i < N; i++) {
            if(color[i] == 1){
                a++;
            }
            else{
                b++;
            }
        }
        printf("%lld\n", a*b - M);
    }
    else{
        printf("%lld\n", (N-1)*N/2 - M);
    }




}