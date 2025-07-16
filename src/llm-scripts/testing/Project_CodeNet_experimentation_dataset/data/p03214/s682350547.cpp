#include <bits/stdc++.h>
using namespace std;

int abs(int x) {

    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum = sum + a.at(i);
    }

    int ans = 100000;
    int memo;
    for (int i = 0; i < N; i++) {
        if (ans > abs(a.at(i)*N-sum)) {
            ans = abs(a.at(i)*N-sum);
            memo = i;
        }
    }
    cout << memo << endl;
}
