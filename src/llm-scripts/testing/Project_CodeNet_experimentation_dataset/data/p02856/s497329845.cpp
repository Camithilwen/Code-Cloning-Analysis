#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int m;
    cin >> m;
    ll total = 0;
    ll cnt = 0;
    for (int i = 0; i < m; i++)
    {
        ll d, c;
        cin >> d >> c;
        total += d * c;
        if (total >= 10)
        {
            cnt += total / 9;
            total %= 9;
            if (total == 0)
            {
                --cnt;
                total = 9;
            }
        }
        cnt += c;
    }
    cout << cnt - 1 << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}