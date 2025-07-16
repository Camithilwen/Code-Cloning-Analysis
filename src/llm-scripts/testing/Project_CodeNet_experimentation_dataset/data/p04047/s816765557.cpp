#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int N;
int sum = 0;
int main()
{
    cin >> N;
    vector<int> L(2 * N);

    for (int i = 0; i < 2 * N; i++)
    {
        cin >> L[i];
    }
    sort(L.begin(), L.end());
    for (int i = 0; i < 2 * N; i += 2)
    {
        sum += L[i];
    }
    cout << sum << endl;
    return 0;
}
