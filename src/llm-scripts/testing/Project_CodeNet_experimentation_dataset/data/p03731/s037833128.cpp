#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, T; cin >> N >> T;
    vector<int> t(N);
    rep(i, N){
        cin >> t[i];
    }

    int ans = t[N-1] + T;
    for (int i = 1; i < N; i++){
        int d = t[i] - t[i-1];
        if(d > T){
            ans -= d-T;
        }
    }

    cout << ans << endl;

    return 0;
}