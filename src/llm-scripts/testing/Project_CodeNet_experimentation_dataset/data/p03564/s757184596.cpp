#include<iostream>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    int ans = 1000;
    for (int i = 0; i <= N; i++) {
        int num = 1;
        for (int k = 0; k < i; k++) {
            num *= 2;
        }
        for (int k = 0; k < N - i; k++) {
            num += K;
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
}

