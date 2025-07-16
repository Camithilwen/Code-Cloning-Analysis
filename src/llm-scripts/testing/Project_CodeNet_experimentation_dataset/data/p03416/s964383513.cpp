// https://atcoder.jp/contests/abc152/tasks/abc152_c

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long a, b;
    cin >> a >> b;
    long ans = 0;
    for (int x = a; x <= b; x++)
    {
        string s, t;
        s = to_string(x);
        t = s;
        reverse(t.begin(), t.end());
        if (s == t)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
