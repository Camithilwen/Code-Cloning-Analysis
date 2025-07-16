#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> m(206, 0);
    m[0] = 300000;
    m[1] = 200000;
    m[2] = 100000;
    cout << m[x - 1] + m[y - 1] + (x == 1 && y == 1 ? 400000 : 0) << endl;
    return 0;
}