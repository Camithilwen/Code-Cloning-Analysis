#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long N, M;
    cin >> N >> M;
    vector<unsigned long> uf(2 * N), sz(2 * N);
    iota(uf.begin(), uf.end(), 0UL);
    fill(sz.begin(), sz.begin() + N, 1);
    const auto& find = [&uf](unsigned long i) -> unsigned long {
        while(i != uf[i])i = uf[i] = uf[uf[i]];
        return i;
    };
    const auto& unite = [&uf, &sz, &find](unsigned long i, unsigned long j) -> unsigned long {
        i = find(i);
        j = find(j);
        if(i == j)return 0;
        if(sz[i] < sz[j])swap(i, j);
        sz[i] += sz[j];
        uf[j] = i;
        return 1;
    };
    const auto& add_edge = [&N, &unite](unsigned long i, unsigned long j) -> void { unite(i, j + N); unite(i + N, j); };
    for(unsigned long i{0}, u, v; i < M; ++i){
        cin >> u >> v;
        add_edge(u - 1, v - 1);
    }
    if(find(0) == find(N))cout << N * (N - 1) / 2 - M << endl;
    else cout << sz[find(0)] * sz[find(N)] - M << endl;
    return 0;
}