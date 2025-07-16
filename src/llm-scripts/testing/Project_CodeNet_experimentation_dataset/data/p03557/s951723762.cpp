#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<vector<int>> part(3, vector<int>(N));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> part[i][j];
        }

        sort(part[i].begin(),part[i].end());
    }
    
    ll cases = 0;
    for (int mid = 0; mid < N; mid++)
    {
        ll as = lower_bound(part[0].begin(), part[0].end(), part[1][mid]) - part[0].begin();
        ll cs = N - (upper_bound(part[2].begin(), part[2].end(), part[1][mid]) - part[2].begin());

        cases += (as * cs);
    }
    
    cout << cases << endl;
    return 0;
}
