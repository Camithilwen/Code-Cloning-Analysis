#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    string a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int count = 0;
    rep(i, n) {
        if(a[i] != b[i]) {
            if(a[i] == c[i]) count++;
            else if(b[i] == c[i]) count++;
            else count += 2;
        }
        else {
            if(a[i] != c[i]) count++;
        }
    }
    cout << count << endl;
    return 0;
}