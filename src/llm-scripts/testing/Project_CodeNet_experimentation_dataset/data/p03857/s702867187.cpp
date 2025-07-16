#include <stdio.h>
#include <vector>
#include <tuple>
#include <map>

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)

using lli = long long int;
using pii = std::pair<int, int>;

// UnionFind 木 ; 頂点 = 0, 1, 2, ...,  n-1
class UnionFindTree{
private:
    using Vint = std::vector<int>;
    const int n; // 集合の大きさ
    Vint Parent; // 親のインデックスを指し示す
    Vint SetSize; // 各集合の大きさ(要素数)を保持する関数
public:
    // コンストラクタ
    UnionFindTree(int nn): n(nn){
        SetSize.resize(n, 1);
        Parent.resize(n);
        // 初めは, 全ての頂点は根である
        for(int i = 0; i < n; ++i) Parent[i] = i;
    }
    // デコンストラクタ
    ~UnionFindTree(void){}
    // 頂点 x の属する集合の根を返す関数
    int rootOf(int x){
        // x が 根であるなら終了
        if(Parent[x] == x) return x;
        // そうでないなら, 親を属する集合の根に付け替える
        return Parent[x] = rootOf(Parent[x]);
    }
    // 頂点 x, y を併合する
    void unite(int x, int y){
        int root_x = rootOf(x);
        int root_y = rootOf(y);
        // 異なる集合に属する場合
        if(root_x == root_y) return;
        if(SetSize[root_x] < SetSize[root_y]) std::swap(root_x, root_y);
        Parent[root_y] = root_x;
        SetSize[root_x] += SetSize[root_y];
    }
    // 頂点 x, y が 同じ集合に属しているかを判定する
    bool sameSet(int x, int y){
        return rootOf(x) == rootOf(y);
    }
    // 頂点 x の属する集合の要素数
    int sizeOf(int x){
        return SetSize[rootOf(x)];
    }
};


int main(void){
    int n, k, l; scanf("%d%d%d", &n, &k, &l);
    UnionFindTree A(n), B(n);
    REP(i, k){
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        A.unite(a, b);
    }
    REP(i, l){
        int a, b; scanf("%d%d", &a, &b); a--; b--;
        B.unite(a, b);
    }
    std::map<pii, int> C;
    REP(i, n) C[pii(A.rootOf(i), B.rootOf(i))]++;
    REP(i, n){
        printf("%d", C[pii(A.rootOf(i), B.rootOf(i))]);
        putchar(i == n - 1 ? '\n' : ' ');
    }
    return 0;
}