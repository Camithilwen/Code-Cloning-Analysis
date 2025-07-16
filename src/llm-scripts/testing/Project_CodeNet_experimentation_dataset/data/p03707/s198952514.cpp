#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main()
{
    int N, M, Q; cin >> N >> M >> Q;
    vector<string> S(N); for (auto &s : S) cin >> s;
    vector<vector<int>> V(N+1, vector<int>(M+1)), Ex(N, vector<int>(M+1)), Ey(N+1, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            V[i+1][j+1] = V[i][j+1] + V[i+1][j] - V[i][j] + (S[i][j] == '1');
        }
    }
    for (int i = 0; i < N-1; i++) {
        for (int j = 0; j < M; j++) {
            Ex[i+1][j+1] = Ex[i][j+1] + Ex[i+1][j] - Ex[i][j] + (S[i][j] == '1' && S[i+1][j] == '1');
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M-1; j++) {
            Ey[i+1][j+1] = Ey[i][j+1] + Ey[i+1][j] - Ey[i][j] + (S[i][j] == '1' && S[i][j+1] == '1');
        }
    }
    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        int v = V[x2][y2] - V[x2][y1] - V[x1][y2] + V[x1][y1];
        int ex = Ex[x2-1][y2] - Ex[x2-1][y1] - Ex[x1][y2] + Ex[x1][y1];
        int ey = Ey[x2][y2-1] - Ey[x2][y1] - Ey[x1][y2-1] + Ey[x1][y1];
        cout << v - ex - ey << '\n';
    }
    return 0;
}