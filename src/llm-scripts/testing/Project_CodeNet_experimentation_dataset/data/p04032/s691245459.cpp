#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    bool found = 0;
    int i, j;
    for (i = 0; i < (int)s.size() - 1; i++)
    {
        for (j = i + 1; j < (int)s.size(); j++)
        {
            if (s[i] == s[j])
            {
                if (2 > (j - i + 1) / 2)
                    found = 1;
                break;
            }
        }
        if (found)
            break;
    }
    if (found)
        cout << i + 1 << " " << j + 1 << endl;
    else
        cout << -1 << " " << -1 << endl;
}