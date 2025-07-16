#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K, T;
    cin >> K >> T;

    priority_queue<pair<int, int>> q;
    int ai;
    for (int i = 0; i < T; i++)
    {
        cin >> ai;
        q.push(make_pair(ai, i + 1));
    }

    int res = 0;
    int prev = 0;
    for (int i = 0; i < K; i++)
    {
        pair<int, int> p0 = q.top();
        q.pop();

        if (p0.second == prev)
        {
            if (q.empty())
            {
                res += p0.first;
                break;
            }
            else
            {
                pair<int, int> p1 = q.top();
                q.pop();
                p1.first--;
                prev = p1.second;
                if (p1.first > 0)
                {
                    q.push(p1);
                }
            }
        }
        else
        {
            p0.first--;
            prev = p0.second;
        }

        if (p0.first > 0)
        {
            q.push(p0);
        }
    }
    cout << res << endl;
}