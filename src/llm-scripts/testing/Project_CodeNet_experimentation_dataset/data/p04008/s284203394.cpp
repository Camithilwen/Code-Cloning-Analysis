#include <bits/stdc++.h>
using namespace std;
vector<int> adjlist[100005];
int mx[100005];
int ans = 0;
int n,k;
void dfs(int u){
    mx[u] = 0;
    for (auto v : adjlist[u]){
        dfs(v);
        if (mx[v] == k && u != 1){
            ans++;
        }
        else{
            mx[u] = max(mx[u],mx[v]);
        }
    }
    mx[u]++;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1,x; i <= n; i++){
        scanf("%d",&x);
        if (i == 1){
            if (x != 1){
                ans++;
            }
        }
        else adjlist[x].push_back(i);
    }
    dfs(1);
    printf("%d",ans);
}
