#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef vector<vector<char>> matrix;
typedef long long ll;


int N;
matrix ans;


matrix make_m(int n) {
    matrix m(n, vector<char>(n, '.'));
    if (n == 3) {
        m[0][0] = m[0][1] = 'a';
        m[1][2] = m[2][2] = 'a';
    }
    else if (n == 4) {
        m[0][0] = m[0][1] = m[2][2] = m[2][3] = 'a';
        m[0][2] = m[1][2] = m[2][0] = m[3][0] = m[3][2] = m[3][3] = 'b';
        m[0][3] = m[1][0] = m[1][1] = m[1][3] = 'c';
        m[2][1] = m[3][1] = 'd';
    }
    else if (n == 5) {
        m[0][0] = m[0][1] = m[4][3] = m[4][4] = 'a';
        m[0][2] = m[0][3] = m[1][0] = m[2][0] = m[2][4] = m[3][4] = m[4][1] = m[4][2] = 'b';
        m[0][4] = m[1][1] = m[1][2] = m[1][4] = m[2][3] = m[3][0] = m[3][3] = m[4][0] = 'c';
    }
    else if (n == 6) {
        m[0][0] = m[0][1] = m[1][2] = m[1][3] = m[2][5] = m[3][5] = m[5][1] = m[5][2] = 'a';
        m[0][2] = m[0][3] = m[1][0] = m[2][0] = m[5][3] = m[5][4] = 'b';
        m[0][4] = m[0][5] = m[1][1] = m[2][1] = m[3][0] = m[4][0] = m[4][5] = m[5][5] = 'c';
        m[3][4] = m[4][4] = 'd';
    }
    else if (n == 7) {
        m[0][0] = m[0][1] = m[1][6] = m[2][6] = m[5][3] = m[5][4] = m[6][1] = m[6][2] = 'a';
        m[0][2] = m[0][3] = m[1][0] = m[2][0] = m[3][6] = m[4][6] = m[6][3] = m[6][4] = 'b';
        m[0][4] = m[0][5] = m[1][1] = m[1][2] = m[2][5] = m[3][0] = m[3][5] = m[4][0] = m[5][6] = m[6][6] = 'c';
        m[4][5] = m[5][5] = 'd';
    }
    return m;
}


int main() {
    cin >> N;
    if (N == 2) {
        cout << -1 << endl;
        return 0;
    }
    ans = matrix(N, vector<char>(N, '.'));
    if (N < 8) ans = make_m(N);
    else if (N % 4 == 0) {
        matrix m4 = make_m(4);
        rep(k, N / 4) {
            rep(i, 4) rep(j, 4) {
                ans[k*4+i][k*4+j] = m4[i][j];
            }
        }
    }
    else {
        matrix m4 = make_m(4);
        int x = 4 + (N % 4);
        matrix mx = make_m(x);
        rep(k, (N - x) / 4) {
            rep(i, 4) rep(j, 4) {
                ans[k*4+i][k*4+j] = m4[i][j];
            }
        }
        int k = N - x;
        rep(i, x) rep(j, x) {
            ans[k+i][k+j] = mx[i][j];
        }
    }
    rep(i, N) {
        rep(j, N) cout << ans[i][j];
        cout << endl;
    }
}
