#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

const int N = 100001;

int n, m, col[N];
vector <int> v[N];

int dfs(int node, int pnode){
    for(auto &i : v[node]){
        if(col[i] != -1){
            if(col[i] != (col[node] ^ 1)) return 1;
        }
        else{
            col[i] = col[node] ^ 1;
            int f = dfs(i, node);
            if(f == 1) return 1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(col, -1, sizeof col);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    col[1] = 0;
    if(dfs(1, 0)) finish(1LL * n * (n - 1) / 2 - m);
    int r = 0, b = 0;
    for(int i = 1 ; i <= n ; i++){
        if(col[i] == 0) r++;
        else b++;
    }
    cout << 1LL * r * b - m << endl;
}
