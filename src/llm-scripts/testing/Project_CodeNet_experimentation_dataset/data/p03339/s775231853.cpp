#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int east[n], west[n];
    rep(i, n) west[i] = 0;
    if (s[0] == 'W')
        west[0] = 1;
    else
        west[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] == 'W')
            west[i] = west[i - 1] + 1;
        else
            west[i] = west[i - 1];
    }
    if (s[n - 1] == 'E')
        east[n - 1] = 1;
    else
        east[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        if (s[i] == 'E')
            east[i] = east[i + 1] + 1;
        else
            east[i] = east[i + 1];
    }
    int cnt = n;
    rep(i, n)
    {
        if (east[i] + west[i] < cnt)
        {
            cnt = east[i] + west[i];
        }
    }
    cout << cnt - 1 << endl;
    return 0;
}