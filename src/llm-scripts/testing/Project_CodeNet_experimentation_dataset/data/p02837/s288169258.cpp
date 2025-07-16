#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a[15], x[15][15], y[15][15];

int cnt(int i)
{
    if (!i) return 0;
    return (i & 1) + cnt(i >> 1);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < a[i]; j++)
        {
            cin >> x[i][j] >> y[i][j];
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        int ok = 1;
        for (int i = 0; i < n; i++)
        {
            if ((bit >> i) & 1)
            {
                for (int j = 0; j < a[i]; j++)
                {
                    if (((bit >> (x[i][j] - 1)) & 1) ^ y[i][j]) ok = 0; 
                }
            }
        }
        if (ok) ans = max(ans, cnt(bit));
    }
    cout << ans << "\n";
}