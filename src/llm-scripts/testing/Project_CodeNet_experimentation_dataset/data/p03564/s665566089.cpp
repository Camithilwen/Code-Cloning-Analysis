#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N, K, A = 1;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        if (A * 2 < A + K) A *= 2;
        else {
            for (; i < N; i++) A += K;
            break;
        }
    }

    cout << A << endl;
}