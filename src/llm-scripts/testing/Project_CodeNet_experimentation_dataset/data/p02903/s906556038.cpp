#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n, m, a, b;
int grid[N][N];

void solve() {
    cin >> n >> m >> a >> b;
    memset(grid, 0, sizeof(grid));
    for(int i = 1; i <= b; i++) {
        for(int j = 1; j <= a; j++) {
            grid[i][j] = 1;
        }
    }
    for(int i = b + 1; i <= n; i++) {
        for(int j = a + 1; j <= m; j++) {
            grid[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
}