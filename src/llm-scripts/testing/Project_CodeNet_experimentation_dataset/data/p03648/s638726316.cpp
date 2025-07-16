#include <bits/stdc++.h>
using namespace std;
long long K;

int main()
{
    cin >> K;
    cout << 50 << endl;
    for (int i=0; i<=50; i++)
    {
        if (50-i != K%50) cout << K/50 + i << " ";
    }
}