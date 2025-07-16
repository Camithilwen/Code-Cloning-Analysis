#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;


int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c > min(a, b) && c < max(a, b))
        cout << "Yes";
    else
        cout << "No";
}
