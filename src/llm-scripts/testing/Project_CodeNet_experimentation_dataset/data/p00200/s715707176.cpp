#include<iostream>
using namespace std;

int n, m, k;
int t[100][100], c[100][100];
int INF = 1<<21;

void solve(){
    for(int k = 0; k < m; k++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
}

int main(){
    while(1){
        cin >> n >> m;

        if(n + m == 0)  break;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                c[i][j] = t[i][j] = INF;
            }
        }
        
        int a, b, cost, tim;
        for(int i = 0; i < n; i++){
            cin >> a >> b >> cost >> tim;
            a--; b--;
            c[a][b] = c[b][a] = cost;
            t[a][b] = t[b][a] = tim;
        }

        solve();

        cin >> k;
        int p, q, r;
        for(int i = 0; i < k; i++){
            cin >> p >> q >> r;
            p--; q--;
            if(r == 0)          cout << c[p][q] << endl;
            else if(r == 1)     cout << t[p][q] << endl;
        }

    }
    return 0;
}
