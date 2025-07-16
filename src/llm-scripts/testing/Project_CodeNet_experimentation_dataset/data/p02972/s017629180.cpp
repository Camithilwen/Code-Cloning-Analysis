#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

const int mod = 1000000007;

int main()
{
    int N;
    cin >> N;
    vector<bool> a(N + 1);

    for (int i = 1; i <= N; i++) {
        int ai;
        cin >> ai;
        if (ai == 1) {
            a[i] = false;
        } else {
            a[i] = true;
        }
    }

    vector<bool> c(N + 1, false); //すくなくとも1つはiの倍数（i自身）があるのでfalse(割ったあまりが1)
    vector<vector<int>> divisor(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            divisor[j].push_back(i);
        }
    }

    vector<int> b;
    for (int i = N; i >= 1; i--) {
        if (a[i] == c[i]) {
            b.push_back(i);
            for (int d : divisor[i]) {
                c[d] = !c[d];
            }
        }
    }

    reverse(b.begin(), b.end());
    int M = b.size();
    cout << M << endl;
    rep(i, M)
    {
        printf("%d%c", b[i], i == M - 1 ? '\n' : ' ');
    }

    return 0;
}
