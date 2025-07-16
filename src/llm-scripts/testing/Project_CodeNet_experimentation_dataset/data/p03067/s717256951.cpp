#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a < c && c < b) || (b < c && c < a))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}