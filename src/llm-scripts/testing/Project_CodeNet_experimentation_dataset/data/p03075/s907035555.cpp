#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    vector<int> a(5);
    rep(i, 5) cin >> a[i];
    sort(a.begin(), a.end());
    int mx = a[4], mn = a[0];
    int k;
    cin >> k;
    if (abs(mx - mn) <= k)
    {
        cout << "Yay!" << endl;
    }
    else
        cout << ":(" << endl;
    return 0;
}