#include<bits/stdc++.h>
using namespace std;
template<class T> void chmax(T&x, T y){if(x < y) x = y;} 
int N, K;
vector<int> G[100010];
int ans;

int dfs(int v, int p){
    int mx = 0;
    for(auto u : G[v]){
        chmax(mx, dfs(u, v));
    }
    if(mx == K - 1 && p > 1) mx = -1, ans++;
    return mx + 1;
}

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        int p;
        cin >> p;
        if(i == 1) ans += (p == 1 ? 0 : 1);
        else G[p].push_back(i);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}