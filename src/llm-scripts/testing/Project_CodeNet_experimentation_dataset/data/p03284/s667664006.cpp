#include <iostream>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    if (N % K != 0) printf("%d\n", 1);
    else printf("%d\n", 0);
}