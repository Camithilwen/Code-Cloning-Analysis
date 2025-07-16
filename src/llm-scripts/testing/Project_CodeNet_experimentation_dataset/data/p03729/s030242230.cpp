#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    if (a.at(a.size() - 1) == b.at(0) && b.at(b.size() - 1) == c.at(0))
    {
        puts("YES");
    }
    else
    {
        puts("NO");
    }
}