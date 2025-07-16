#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int a, b;
    cin >> a >> b;
    int count = 0;
    int ans = 1;
    for (int i = 0; b > ans; i++)
    {
        ans += (a - 1);
        count++;
    }
    cout << count << endl;
    return 0;
}