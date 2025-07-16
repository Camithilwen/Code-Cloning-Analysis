#include <iostream>
#include <vector>
using namespace std;

int main() {
    uint N; cin >> N;
    vector<int> A(N, 0);
    for (auto &a: A) cin >> a;

    int cnt = 0;
    bool exist = false;
    while (!exist) {
        for (size_t i=0; i<A.size(); ++i) {
            if (A[i] % 2 != 0) {
                exist = true;
                break;
            }
            A[i] /= 2;
        }
        if (!exist) ++cnt;
    }
    cout << cnt << endl;
}
