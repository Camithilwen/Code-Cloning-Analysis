#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    uint N;
    long long x;
    cin >> N >> x;

    vector<long long> a(N, 0);
    long long sum = 0;
    for (auto &c: a) {
        cin >> c;
        sum += c;
    }

    if (sum < x) {
        cout << a.size() - 1 << endl;
    }
    else if (sum == x) {
        cout << a.size() << endl;
    }
    // sum > x
    else {
        sort(a.begin(), a.end());
        int numHappy = 0;
        for (size_t i=0; i<a.size(); ++i) {
            x -= a[i];
            if (x >= 0)  ++numHappy;
            else break;
        }
        cout << numHappy << endl;
    }
}
