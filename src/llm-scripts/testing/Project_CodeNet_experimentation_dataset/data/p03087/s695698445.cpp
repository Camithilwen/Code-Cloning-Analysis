#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
int32_t main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> index;
    int c = 0;
    index.push_back(c);
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'A')
        {
            if (s[i + 1] == 'C')
            {
                index.push_back(++c);
            }
            else
            {
                index.push_back(c);
            }
        }
        else
        {
            index.push_back(c);
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout<< index[--r]-index[--l]<<endl;
    }
    return 0;
}