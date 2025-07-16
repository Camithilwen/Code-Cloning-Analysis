#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    int f = 1.0;
    while(true) {
        double M = sqrt(N), x = 0.0, y = 0.0;
        x = modf(M, &y);
        if (x == 0) {
            printf("%d\n", N);
            return 0;
        }
        else N--;
    }
}
