#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> L;
    for (int i = 0; i < 2 * N; ++i)
    {
        int temp;
        cin >> temp;
        L.push_back(temp);
    }
    int ans = 0;
    sort(L.begin(), L.end());

    for (int i = 0; i < 2 * N; ++i)
    {
        ans += min(L[i], L[i + 1]);
        ++i;
    }
    cout << ans << endl;
}
