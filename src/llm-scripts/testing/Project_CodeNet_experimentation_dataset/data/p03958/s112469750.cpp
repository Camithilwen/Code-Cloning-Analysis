#include <bits/stdc++.h>
using namespace std;

#define all(a)  (a).begin(),(a).end()

int main()
{
    int k,t;
    cin >> k >> t;
    vector<int> a(t);
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
    }

    sort(all(a));
    reverse(all(a));

    int ans = max(a[0] - 1 - (k - a[0]) ,0);

    cout << ans << endl;
}