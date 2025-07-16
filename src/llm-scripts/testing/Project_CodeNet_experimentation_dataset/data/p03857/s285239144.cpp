#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

class UnionFind{ //連結判定
private:
    std::vector<int> parent; //parent[i] = parent of node i
    std::vector<int> rank;
    std::vector<int> size;
public:
    //constructor
    UnionFind(int N){
        for(int i=0; i<N; i++) parent.push_back(i); //parent = [0,1,..,N-1]
        for(int i=0; i<N; i++) rank.push_back(0); //rank = [0,0,..,0]
        for(int i=0; i<N; i++) size.push_back(1);
    }
    //initialize
    void init(int N){
        parent.clear();
        rank.clear();
        size.clear();
        for(int i=0; i<N; i++) parent.push_back(i); //parent = [0,1,..,N-1]
        for(int i=0; i<N; i++) rank.push_back(0); //rank = [0,0,..,0]
        for(int i=0; i<N; i++) size.push_back(1);
    }
    int root(int a){
        if(parent[a] == a) return a;
        return parent[a] = root(parent[a]); //親が自分自身になるまで再帰を呼び出す & 経路圧縮 
    }
    void unite(int a, int b){
        int rootA = root(a);
        int rootB = root(b);
        if(rootA == rootB) return; //ノードa, bがすでに連結しているとき
        //次数の大きい方を親として連結
        if(rank[rootA] < rank[rootB]){
            size[rootB] += size[rootA];
            parent[rootA] = rootB;
        }
        else{
            size[rootA] += size[rootB];
            parent[rootB] = rootA;
            if(rank[rootA] == rank[rootB]) rank[rootA]++;
        }
    }
    bool same(int a, int b){
        return root(a) == root(b); //ノードa, bが同じ木に属するかどうか
    }
    int get_size(int a){
        return size[root(a)];
    }
};

int main()
{
    using P = std::pair<int, int>;

    int N, K, L;
    std::cin >> N >> K >> L;
    std::vector<P> route(K), rail(L);
    for(int i=0; i<K; i++){
        scanf(" %d %d", &(route[i].first), &(route[i].second));
        route[i].first--; route[i].second--;
    }
    for(int i=0; i<L; i++){
        scanf(" %d %d", &(rail[i].first), &(rail[i].second));
        rail[i].first--; rail[i].second--;
    }

    UnionFind uf_route(N), uf_rail(N);
    for(int i=0; i<K; i++){
        int u = route[i].first, v = route[i].second;
        uf_route.unite(u, v);
    }
    for(int i=0; i<L; i++){
        int u = rail[i].first, v = rail[i].second;
        uf_rail.unite(u, v);
    }

    std::vector<std::pair<P, int> > root;
    for(int i=0; i<N; i++){
        int a = uf_route.root(i), b = uf_rail.root(i);
        root.push_back(std::pair<P, int>(P(a, b), i));
    }
    std::sort(root.begin(), root.end());
    std::vector<int> tmp, count(N);
    for(int i=0; i<N; i++){
        tmp.push_back(root[i].second);
        if(i == N-1 || (i != N-1 && root[i].first != root[i+1].first)){
            int M = tmp.size();
            while(!tmp.empty()){
                count[tmp.back()] = M;
                tmp.pop_back();
            }
        }
    }
    
    for(int i=0; i<N; i++){
        printf("%d ", count[i]);
    }
    printf("\n");
}