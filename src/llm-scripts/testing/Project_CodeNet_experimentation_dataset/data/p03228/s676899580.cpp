#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll A, B, K;
    cin >> A >> B >> K;
    for (int i = 0; i < K; ++i)
    {
        if (A % 2 == 1)
        {
            --A;
        }
        B += A / 2;
        A = A / 2;
        ++i;
        if (i >= K)
        {
            break;
        }
        if (B % 2 == 1)
        {
            --B;
        }
        A += B / 2;
        B = B / 2;
    }
    cout << A << " " << B << endl;
}
