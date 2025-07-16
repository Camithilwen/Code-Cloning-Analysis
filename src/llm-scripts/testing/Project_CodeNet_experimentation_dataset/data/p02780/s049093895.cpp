#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    int K; 
    cin >> K;
    vector<int> A(N + 1,0);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i + 1);
    }
    for(int i = 1; i < N; i++) {
        A.at(i + 1) += A.at(i);
    }
    int ans = 0;
    for(int i = 0; i < N - K + 1; i++) {
        ans = max(ans, A.at(i + K) - A.at(i));
    }
    cout << fixed << setprecision(15) << (double)(ans + K)/2 << endl;
    


    return 0;
}