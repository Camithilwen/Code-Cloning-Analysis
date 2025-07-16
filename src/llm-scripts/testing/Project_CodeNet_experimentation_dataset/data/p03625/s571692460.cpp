#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    Rep(i, N) cin >> A[i];
    Sort(A);
    int index = A.size() - 1;
    ll e1 = 0, e2 = 0;
    while (index >= 1) {
        if (A[index] == A[index - 1]) {
            e1 = A[index];
            index -= 2;
            break;
        }
        index--;
    }
    while (index >= 1) {
        if (A[index] == A[index - 1]) {
            e2 = A[index];
            break;
        }
        index--;
    }
    cout << e1 * e2 << endl;
    return 0;
}