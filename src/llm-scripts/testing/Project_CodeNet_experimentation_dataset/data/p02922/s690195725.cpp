#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int A, B;
    cin >> A >> B;

    if (B == 1) {
        cout << 0 << endl;
        return 0;
    }

    int output = 1;
    int socket = A;
    while (1) {
        if (socket >= B) break;
        socket--;
        socket += A;
        output++;
    }

    cout << output << endl;

    return 0;
}
