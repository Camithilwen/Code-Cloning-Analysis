#include <bits/stdc++.h>

using namespace std;

const long long Mod = 1000000007;

int n;
string str;
int a[200005], xd[200005];
long long p[200005];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = (p[i - 1] * i) % Mod;
    }
    n *= 2;
    cin >> str;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'B')
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 0;
        }
        if (a[i] == s)
        {
            xd[i] = -1;
        }
        else
        {
            xd[i] = 1;
        }
        s ^= 1;
    }
    int s1 = 0, s2 = 0;
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        if (xd[i] == 1)
        {
            s1++;
        }
        else
        {
            if (s1 > s2)
            {
                res = (res * (s1 - s2)) % Mod;
            }
            else
            {
                res = 0;
            } 
            if (res == 0)
            {
                break;
            }
            s2++;
        }
    }
    if (s1 != s2)
    {
        res = 0;
    }
    cout << (res * p[n / 2]) % Mod;
    return 0;
}