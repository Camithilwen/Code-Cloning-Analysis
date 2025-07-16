#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define l first
#define r second
#define int long long

int n;
long long a[500000];
vector<long long> multi;

int upper_bit(long long c)
{
    for (int i = 60; i >= 0; i--)
    {
        if (c & (1LL << i)) return i;
    }
    return -1;
}

signed main()
{
    cin >> n;
    long long x = 0;
    for (int i = 0; i < n; i++) cin >> a[i], x ^= a[i];
    for (int i = 0; i < n; i++) a[i] -= a[i] & x;
    for (int i = 0; i < n; i++)
    {
        int kek = 0;
        for (int j = 0; j < multi.size(); j++)
        {
            if (upper_bit(multi[j]) == upper_bit(a[i])) kek = 1;
        }
        if (kek)
        {
            long long cur = a[i];
            for (int i = 0; i < multi.size(); i++)
            {
                if (upper_bit(cur) == upper_bit(multi[i]))
                {
                    cur ^= multi[i];
                    if (cur == 0) break;
                }
            }
            if (cur != 0)
            {
                multi.push_back(cur);
                sort(multi.begin(), multi.end());
                reverse(multi.begin(), multi.end());
            }
        }
        else
        {
            multi.push_back(a[i]);
            sort(multi.begin(), multi.end());
            reverse(multi.begin(), multi.end());
        }
    }
    sort(multi.begin(), multi.end());
    reverse(multi.begin(), multi.end());
    long long res = 0;
    long long b = (1LL << 61);
    for (int i = 0; i < multi.size(); i++)
    {
        //cout << multi[i] << "\n";
        while (b > multi[i]) b /= 2;
        if ((res & b) == 0) res ^= multi[i];
    }
    cout << x + 2 * res;
}
