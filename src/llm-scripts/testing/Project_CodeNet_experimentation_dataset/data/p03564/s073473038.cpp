#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, x;
    cin >> N;
    cin >> K;
    x = 1;
    for (int i = 0; i < N; ++i)
    {
        if (x * 2 < x + K)
        {
            x = x * 2;
        }
        else
        {
            x = x + K;
        }
    }
    cout << x << endl;
}