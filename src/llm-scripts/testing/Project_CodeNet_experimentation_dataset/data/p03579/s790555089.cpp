//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

vi color;
vvi G;


bool dfs(int v, int c) {
    if(color[v]  != -1) {
        if(c%2 == color[v]) {
            return true;
        } else {
            return false;
        }
    }
    color[v] = c%2;
    for(int next:G[v]){
       if(!dfs(next, c+1)) {
           return false;
       }
    }
    return true;
}

int main() {
    ll N, M;
    scanf("%lld%lld", &N, &M);
    G.resize(N);
    rep(i, M) {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    color.assign(N, -1);
    if(!dfs(0, 0)) {
        cout << N*(N-1)/2-M << '\n';
        return 0;
    }
    int cc=0;
    rep(i, N) {
        if(color[i]) {
            ++cc;
        }
    }
    cout << (N-cc)*cc-M << '\n';
}