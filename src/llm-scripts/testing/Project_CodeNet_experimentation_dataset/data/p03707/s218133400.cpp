#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

string S[2002];
int P[2002][2002], A[2002][2002], B[2002][2002];

int main() {
    if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);

    int N, M, Q; cin >> N >> M >> Q;
    for (int i = 0; i < N; ++i) cin >> S[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            P[i+1][j+1] = P[i+1][j]+P[i][j+1]-P[i][j]+(S[i][j]=='1');
            if (i) A[i+1][j+1] = A[i+1][j]+A[i][j+1]-A[i][j]+(S[i][j]=='1'&&S[i-1][j]=='1');
            if (j) B[i+1][j+1] = B[i+1][j]+B[i][j+1]-B[i][j]+(S[i][j]=='1'&&S[i][j-1]=='1');
        }
    }
    
    while (Q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << P[x2][y2]-P[x1-1][y2]-P[x2][y1-1]+P[x1-1][y1-1]
               -A[x2][y2]+A[x1  ][y2]+A[x2][y1-1]-A[x1  ][y1-1]
               -B[x2][y2]+B[x1-1][y2]+B[x2][y1  ]-B[x1-1][y1  ] << '\n';
    }
}