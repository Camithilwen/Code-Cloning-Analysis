#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> odd(100100, make_pair(0, 0)), even(100100, make_pair(0, 0));
    rep (i, n)
    {
        int v;
        cin >> v;
        if (i % 2)
        {
            odd[v].first++;
            odd[v].second = v;
        }
        else
        {
            even[v].first++;
            even[v].second = v;
        }
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    if (odd[0].second != even[0].second)
        cout << (n / 2 - odd[0].first) + (n / 2 - even[0].first) << endl;
    else
        cout << min((n / 2 - odd[0].first) + (n / 2 - even[1].first), (n / 2 - odd[1].first) + (n / 2 - even[0].first)) << endl;
}