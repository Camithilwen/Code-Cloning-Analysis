#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template<class T> ostream& operator<<(ostream& os, const vector<T>& vec) { for (auto &vi: vec) os << vi << " "; return os; }

int main() {
    vector<int> ab(2);
    for (auto &abi: ab) cin >> abi;
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        ab[(i & 1) ^ 1] += ab[i & 1] >>= 1;
    }
    cout << ab << endl;
    return 0;
}
