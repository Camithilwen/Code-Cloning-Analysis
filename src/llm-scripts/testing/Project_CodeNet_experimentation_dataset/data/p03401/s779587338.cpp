#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void) {
    int N;cin>>N;
    vector<int> A(N + 2);
    // departure
    A.push_back(0);
    for (int i = 1; i <= N; i++) cin>>A[i];
    // goal
    A.push_back(0);

    int SUM[N + 1];
    int sum = 0;
    for (int i = 0; i <= N; i++) {
        SUM[i] = abs(A[i + 1] - A[i]);
        sum += SUM[i];
    }
    // 結果出力
    for (int i = 1; i <= N; i++) {
        cout << sum - SUM[i - 1] - SUM[i] + abs(A[i + 1] - A[i - 1]) << endl;
    }
    return 0;
}