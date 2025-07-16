#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<char> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        if (n != 1)
        {
            if (a[i] == 1)
            {
                if (b[i] == '0')
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }

        a[i]--;
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (a[i] == a[j])
            {
                if (b[i] != b[j])
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    int nx = pow(10, n);

    for (int i = 0; i < nx; i++)
    {
        string str = to_string(i);
        if (str.size() != n) continue;

        int flg = 1;
        for (int j = 0; j < m; j++)
        {
            if (str[a[j]] != b[j]) flg = 0;
        }
        if (flg)
        {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}