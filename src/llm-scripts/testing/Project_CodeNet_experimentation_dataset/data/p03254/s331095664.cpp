#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, x;
    cin >> N >> x;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());

    int cnt = 0;
    if (x < v.at(0))
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < N && x >= v.at(i); i++)
        {
            cnt++;
            x -= v.at(i);
        }

        if (cnt == N && x > 0)
            cnt--;

        cout << cnt;
    }
}
