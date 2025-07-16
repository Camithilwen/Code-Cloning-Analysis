#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 100; i > 0; i /= 10) {
        if (N / i == 7) {
            cout << "Yes" << endl;
            return 0;
        }
        N %= i;
    }
    cout << "No" << endl;
}