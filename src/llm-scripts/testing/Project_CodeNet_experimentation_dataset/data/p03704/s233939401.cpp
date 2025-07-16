#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define int long long

const int INF = 1e18;

long long d;
unsigned long long ans;
unsigned long long p[50];
map<int, int> kek[2];

void check(long long d, int L, int R, unsigned long long cnt)
{
    if (L >= R)
    {
        ans += cnt * (d == 0) * (L == R ? 10 : 1);
        return;
    }
    long long c = p[R] - p[L];
    vector<long long> xs;
    for (int digit = -9; digit <= 9; digit++)
    {
        if (digit < 0 && L == 0) continue;
        long long x = d - digit * c;
        xs.push_back(x);
    }
    sort(xs.begin(), xs.end());
    for (int i = -1; i < (int)xs.size(); i++)
    {
        if ((i == -1 || xs[i] < 0) && (i + 1 == xs.size() || xs[i + 1] >= 0))
        {
            if (i > -1)
            {
                int digit = (d - xs[i]) / c;
                check(xs[i], L + 1, R - 1, cnt * kek[L == 0][digit]);
            }
            if (i + 1 < xs.size())
            {
                int digit = (d - xs[i + 1]) / c;
                check(xs[i + 1], L + 1, R - 1, cnt * kek[L == 0][digit]);
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            kek[0][i - j]++;
        }
    }
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            kek[1][i - j]++;
        }
    }
    cin >> d;
    p[0] = 1;
    for (int i = 1; i <= 19; i++) p[i] = p[i - 1] * 10;
    for (int len = 1; len <= 19; len++)
    {
        check(d, 0, len - 1, 1);
    }
    cout << ans;
}
