#include <bits/stdc++.h>
using namespace std;

// D - Dice in Line
int main() {
    int N, K;
    cin >> N >> K;

    long double p[N];
    int tmpP;
    for (int i = 0; i < N; i++) {
        cin >> tmpP;
        p[i] = ((tmpP + 1.0) / 2.0);
    }

    /*
    // debug
    for (int i = 0; i < N; i++) {
        cout << p[i] << endl;
    }
    */

    long double nowSum = 0, maxSum = 0;
    for (int i = 0; i < K; i++) {
        nowSum = nowSum + p[i];
    }   
    // cout << "nowSum:" << nowSum << endl; // debug
    maxSum = nowSum;
    for (int i = K; i < N; i++) {
        nowSum = nowSum - p[i - K] + p[i];
        maxSum = max(nowSum, maxSum);
    }
    // cout << maxSum;
    printf("%Lf", maxSum);
}
