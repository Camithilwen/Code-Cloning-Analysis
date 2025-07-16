#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, h, w; cin >> n >> h >> w;

    int a = n - h;
    int b = n - w;
    if(a < 0 || b < 0) {
        cout << 0 << endl;
        return 0;
    }
    a++;
    b++;
    cout << a * b << endl;

     return 0;
}
