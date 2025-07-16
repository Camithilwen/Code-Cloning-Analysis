#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{
    ll t;
    t = 1;
    //cin t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        int i = 1;
        int j = n;
        if (n % 2 != 0)
        {
            while (m--)
                cout << i++ << " " << j-- << endl;
        }
        else
        {
            int count[n + 1] = {0};
            int current = 1;
            int x = n / 2;
            int s = 1;
            int s1 = x + 1;
            for (int i = x - 1; i >= 1; i--)
            {
                if (m == 0)
                    break;
                if (i % 2 == 0)
                {
                    cout << s << " " << s + i << endl;
                    s++;
                }
                else
                {
                    cout << s1 << " " << s1 + i << endl;
                    s1++;
                }

                m--;
            }
            // cout << i << " " << --j << endl;
        }
    }
}
