#include <iostream>
#include <algorithm>
#define INF (2 << 28)
using namespace std;

int main(){
    
    int n, m, cost[101][101];
    
    while(cin >> n >> m, n||m){
        fill_n(*cost, 101*101, INF);
        for(int i = 1; i <= n; i++) cost[i][i] = 0;
        while(m--){
            int k; cin >> k;
            if(k == 0){
                int a, b; cin >> a >> b;
                cout << (cost[a][b] == INF ? -1 : cost[a][b]) << endl;
            } else {
                int a, b, c; cin >> a >> b >> c;
                cost[a][b] = cost[b][a] = min(cost[a][b], c);
                for(int i = 1; i <= n; i++){
                    for(int j = 1; j <= n; j++){
                        cost[i][j] = min(cost[i][j], cost[i][a] + cost[a][b] + cost[b][j]);
                        cost[i][j] = min(cost[i][j], cost[i][b] + cost[b][a] + cost[a][j]);
                    }
                }
            }
        }
    }
}