#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, M, Q;
    scanf("%d %d %d\n", &N, &M, &Q);
    vector<string> grid(N+1, "0");
    grid[0].resize(M);
    for (int i = 1; i <= N; i++) {
        char s[M];
        scanf("%s\n", s);
        grid[i] += s;
    }
    vector<vector<int>> psum(N+1, vector<int>(M+1, 0));
    vector<vector<int>> horsum(N+1, vector<int>(M+1, 0));
    vector<vector<int>> versum(N+1, vector<int>(M+1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (grid[i][j] == '1') {
                psum[i][j]++;
                if (grid[i][j-1] == '1') horsum[i][j]++;
                if (grid[i-1][j] == '1') versum[i][j]++;
            }
            psum[i][j] += psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1];
            horsum[i][j] += horsum[i][j-1] + horsum[i-1][j] - horsum[i-1][j-1];
            versum[i][j] += versum[i][j-1] + versum[i-1][j] - versum[i-1][j-1];
        }
    }
    
    for (int z = 0; z < Q; z++) {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int ps = psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
        int hors = horsum[x2][y2] - horsum[x1-1][y2] - horsum[x2][y1] + horsum[x1-1][y1];
        int vers = versum[x2][y2] - versum[x1][y2] - versum[x2][y1-1] + versum[x1][y1-1];
        printf("%d\n", ps - hors - vers);
    }
    
    return 0;
}
