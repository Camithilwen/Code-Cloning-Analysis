#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_N = 100009;

int N, A[MAX_N];

int same_hat[MAX_N]; // same_hat[i]: 同色の帽子をi人が被っているような色の種類数

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    REP(i, N) same_hat[i] = 0;
    same_hat[0] = 3;

    ll num_comb = 1;

    REP(i, N) {
        num_comb = num_comb * same_hat[A[i]] % MOD;
        same_hat[A[i]]--;
        same_hat[A[i] + 1]++;
    }

    PRINT(num_comb);

    return 0;
}