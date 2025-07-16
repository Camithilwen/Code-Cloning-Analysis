//ヘッダー
#include<bits/stdc++.h>
using namespace std;

//型定義
typedef long long ll;

//定数
const int INF=1e+9;
const int MOD=1e+9+7;

//REPマクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define REP2(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define REPD2(i,a,b) for(ll i=a;i>(ll)(b);i--)

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

//vectorの扱い
#define ALL(x) (x).begin(),(x).end() //sortなどの引数省略
#define SIZE(x) ((ll)(x).size()) //size
#define MAX(x) *max_element(ALL(x)) //最大値
#define MIN(x) *min_element(ALL(x)) //最小値

using Graph=vector<vector<int>>;
// グラフ、頂点の入次数、頂点数を受け取り、そのトポロジカルソートを記録した配列を返す関数
vector<int> topological_sort(Graph &G, vector<int> &indegree, int V) {
    // トポロジカルソートを記録する配列
    vector<int> sorted_vertices;

    // 入次数が0の頂点を発見したら、処理待ち頂点としてキューに追加する
    queue<int> que;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            que.push(i);
        }
    }

    // キューが空になるまで、操作1~3を繰り返す
    while (que.empty() == false) {
        // キューの先頭の頂点を取り出す
        int v = que.front();
        que.pop();

        // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            indegree[u] -= 1;
            if (indegree[u] == 0) que.push(u);
        }
        // 頂点vを配列の末尾に追加する 
        sorted_vertices.push_back(v);
    }

    // トポロジカルソートを返す
    return sorted_vertices;
}


int main(){
    int N,M;
    cin>>N>>M;
    Graph G(N),oya(N);
    vector<int> indegree(N,0);
    
    REP(i,N-1+M){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        oya[b].push_back(a);
        indegree[b]++;
    }
    vector<int> topo=topological_sort(G,indegree,N);
    vector<int> ans(N);
    vector<int> rev(N+1);
    REP(i,N) rev[topo[i]]=i;
    rev[N]=-1;

    REP(i,N){
        if(oya[i].size()==0) ans[i]=0;
        else{
            int idx=N;
            REP(j,oya[i].size()){
                int v=oya[i][j];
                if(rev[v]>rev[idx]&&rev[v]<rev[i]){
                    idx=v;
                }
            }
            ans[i]=idx+1;
        }

    }
    REP(i,N) cout<<ans[i]<<endl;

    


}