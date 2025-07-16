#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int r = 0;
    for (int i = a; i <= b; i++)
    {
        int s = i % 10;
        int t = i / 10000 % 10;
        int u = i / 10 % 10;
        int v = i / 1000 % 10;
        if (s == t && u == v)
        {
            r++;
        }
    }
    cout << r << endl;
    /*
    5桁の回文数 9 * 9 * 10 = 810
    1桁 & 5桁目の取りうる範囲
    2桁 & 4桁目の取りうる範囲
    */
}