#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define endl "\n"
typedef long long ll;

const int BIG_NUM = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && b != c) {
        cout << "Yes";
    } else if(b == c && c != a) {
        cout << "Yes";
    } else if(c == a && a != b) {
        cout << "Yes"; 
    } else {
        cout << "No";
    }
    return 0;
}

