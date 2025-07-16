#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> l(n);

    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    sort(l.begin(),l.end());
    reverse(l.begin(),l.end());
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        x += l.at(i);
    }
    cout << x << endl;
    return 0;
}