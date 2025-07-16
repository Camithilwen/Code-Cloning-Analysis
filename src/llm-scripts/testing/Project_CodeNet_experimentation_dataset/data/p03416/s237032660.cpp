#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int ans = 0;
    
    for (int i = A; i <= B; i++)
    {
        int c = i % 10, d = i / 10000 % 10;
        int e = i / 10 % 10, f = i / 1000 % 10;
        if (c == d && e == f)ans++;
    }
    cout << ans << endl;
}