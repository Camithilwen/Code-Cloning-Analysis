#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    string res;

    cin >> a >> b >> c;
    if(a == b && c != a)
        res = "Yes";
    else if(a == c && b != a)
        res = "Yes";
    else if(b == c && a != b)
        res = "Yes";
    else res = "No";

    cout << res << "\n";
    return 0;
}
