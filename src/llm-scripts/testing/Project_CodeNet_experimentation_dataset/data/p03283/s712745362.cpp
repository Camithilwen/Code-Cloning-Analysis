#include <iostream>
using namespace std;
int main()
{
    int n, m, q, x, y;
    cin >> n >> m >> q;
    int count[501][501] = {0};
    for(int i  = 0; i < m; i++)
    {
        cin >> x >> y;
        count[x][y]++;
    }
    for(int i  =0; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            count[i][j] += count[i][j - 1];
        }
    }
    for(int i  = 0; i <= n; i++)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            count[j][i] += count[j + 1][i];
        }
    }
    for(int i = 0; i < q; i++)
    {
        cin >> x >> y;
        cout << count[x][y] << endl;
    }

    return 0;
}
