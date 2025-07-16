#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    int N; string A, B, C; cin >> N >> A >> B >> C;
    string str = "";

    vector<int> count(10e3, 0);
    for (int i = 0; i < N; ++i) {
        int x, y, z; x = y = z = 0;
        if (A[i] == B[i]) x++;
        if (B[i] == C[i]) y++;
        if (A[i] == C[i]) z++;
        if (x >= y && x >= z) str += A[i];
        else if (y >= x && y >= z) str += B[i];
        else if (z >= y && z >= x) str += C[i];
    }
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] != str[i]) cnt++;
        if (B[i] != str[i]) cnt++;
        if (C[i] != str[i]) cnt++;
    }
    printf("%d\n", cnt);
}
