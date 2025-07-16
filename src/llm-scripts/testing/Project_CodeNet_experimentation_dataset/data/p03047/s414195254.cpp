#include <iostream>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    int ans = 0;
    for (int i = 1; i <= N; i++) if (i + (K - 1) <= N) ans++;
    printf("%d\n", ans);
}