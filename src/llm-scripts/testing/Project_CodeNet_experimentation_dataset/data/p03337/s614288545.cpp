#include <iostream>
using namespace std;
int main() {
    int A, B; cin >> A >> B;
    printf("%d\n", max(A + B, max(A - B, A * B)));
}