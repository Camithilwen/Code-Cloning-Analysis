#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

int main() {
    int N, A[200000], B[200000];
    cin >> N;
    map<int, int> mii;
    REP(i, N) {
        cin >> A[i];
        mii[A[i]]++;
    }
    REP(i, N) {
        cin >> B[i];
        mii[B[i]]++;
    }
    for (auto p : mii) {
        if (p.second > N) {
            cout << "No" << endl;
            return 0;
        }
    }

    int C[200001] = {}, D[200001] = {};
    REP(i, N) {
        C[A[i]]++;
        D[B[i]]++;
    }
    REP(i, N) {
        C[i + 1] += C[i];
        D[i + 1] += D[i];
    }

    int offset = 0;
    REP(i, N) {
        offset = max(D[i + 1] - C[i], offset);
    }
    cout << "Yes" << endl;
    REP(i, N) {
        cout << B[(i + offset) % N] << " ";
    }
    cout << endl;
}