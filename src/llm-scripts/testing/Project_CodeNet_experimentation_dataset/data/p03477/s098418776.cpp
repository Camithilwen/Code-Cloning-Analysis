
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c, d;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d;
    if (a + b > c + d) {
        cout << "Left" << endl;
    } else if (a + b < c + d) {
        cout << "Right" << endl;
    } else {
        cout << "Balanced" << endl;
    }

    return 0;
}

