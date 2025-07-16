#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;

struct UnionFind {
    //各要素が属する集合の代表(根)を管理する
    //もし、要素xが根であればdata[x]は負の値を取り、-data[x]はxが属する集合の大きさに等しい
    vector<int> data;

    UnionFind(int sz) : data(sz, -1) {}

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        bool is_union = (x != y);
        if (is_union) {
            if (data[x] > data[y]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return is_union;
    }

    int find(int x) {
        if (data[x] < 0) { //要素xが根である
            return x;
        } else {
            data[x] = find(data[x]); //data[x]がxの属する集合の根でない場合、根になるよう更新される
            return data[x];
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -data[find(x)];
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, K, L;
    cin >> n >> K >> L;
    UnionFind uf1(n), uf2(n);
    for (int i = 0; i < K; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        uf1.unite(p, q);
    }
    for (int i = 0; i < L; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        uf2.unite(p, q);
    }

    map<P, int> memo;
    vector<P> v;
    for (int i = 0; i < n; i++) {
        P tar(uf1.find(i), uf2.find(i));
        v.push_back(tar);
        memo[tar]++;
    }

    for (int i = 0; i < n; i++) {
        cout << memo[v[i]] << " \n"[i + 1 == n];
    }
    return 0;
}