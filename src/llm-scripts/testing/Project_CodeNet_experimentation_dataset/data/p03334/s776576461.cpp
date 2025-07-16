#include <bits/stdc++.h>
using namespace std;

const int N = 610;

int n, col[N][N], cnt[3];
vector<pair<int,int>> diff;

void dfs(int x, int y, int c) {
    if (x >= 0 && x < 2*n && y >= 0 && y < 2*n && col[x][y] == 0) {
        col[x][y] = c;
        cnt[c]++;
        for (auto d : diff) dfs(x+d.first, y+d.second, 3-c);
    }
}

int main() {
    cin >> n;

    int iter = 2; while (iter--) {
        // calcular arcos
        int d; cin >> d;
        diff.clear();
        for (int dx = 0; dx < 2*n; dx++) 
            for (int dy = 0; dy < 2*n; dy++) 
                if (dx*dx + dy*dy == d) {
                    diff.emplace_back(dx,dy);
                    diff.emplace_back(-dx,dy);
                    diff.emplace_back(dx,-dy);
                    diff.emplace_back(-dx,-dy);
                }

        // partir bipartito
        for (int i = 0; i < 2*n; i++) 
            for (int j = 0; j < 2*n; j++) if (col[i][j] == 0) 
                dfs(i,j,1);

        // quedarse con particion mayor
        int best = (cnt[1] > cnt[2] ? 1 : 2);
        for (int i = 0; i < 2*n; i++) 
            for (int j = 0; j < 2*n; j++) 
                col[i][j] = (col[i][j] == best ? 0 : 3);
    }

    int need = n*n;
    for (int i = 0; i < 2*n; i++) 
        for (int j = 0; j < 2*n; j++) if (col[i][j] == 0) {
            cout << i << ' ' << j << endl;
            if (--need == 0) return 0;
        }

    return 0;
}
