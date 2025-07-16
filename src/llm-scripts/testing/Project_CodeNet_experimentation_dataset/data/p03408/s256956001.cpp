#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, point = 0, max = 0;
    cin >> N;
    vector<string> blue(N);
    set<string> ch;
    for (int i = 0; i < N; ++i)
    {
        cin >> blue.at(i);
        ch.insert(blue.at(i));
    }
    cin >> M;
    vector<string> red(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> red.at(i);
        ch.insert(red.at(i));
    }

    for (auto x : ch)
    {
        point = 0; //重要
        for (int i = 0; i < N; ++i)
        {
            if (blue.at(i) == x)
            {
                ++point;
            }
        }
        for (int i = 0; i < M; ++i)
        {
            if (red.at(i) == x)
            {
                --point;
            }
        }
        max = max < point ? point : max;
    }
    cout << max << endl;
}