#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    vector<ll> cost(5);
    ll N;
    cin >> N;
    for (int i = 0; i < 5; i++)
    {
        cin >> cost[i];
    }
    

    ll result = (ll) ceil((double) N / *min_element(cost.begin(), cost.end())) + 4;
    cout << result << endl;

    return 0;
}
