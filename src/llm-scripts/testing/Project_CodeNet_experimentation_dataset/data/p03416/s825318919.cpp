#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int cnt = 0;

    for (int i = a; i <= b; i++) {
        if (i%10==i/10000 && i/10%10==i/1000%10) {
            cnt += 1;
        }
    }
    cout << cnt << endl;
}