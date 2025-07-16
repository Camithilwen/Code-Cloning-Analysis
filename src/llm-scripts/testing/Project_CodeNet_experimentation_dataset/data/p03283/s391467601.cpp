#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        table[l][r]++;
    }
    rep(i, n) rep(j, n) table[i + 1][j + 1] += table[i + 1][j] + table[i][j + 1] - table[i][j];

    while (q--)
    {
        int s, t;
        cin >> s >> t;

        cout << table[t][t] - table[s - 1][t] - table[t][s - 1] + table[s - 1][s - 1] << endl;
    }
}