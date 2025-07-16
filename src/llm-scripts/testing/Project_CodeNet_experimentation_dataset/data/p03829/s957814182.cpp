#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    for ( int i = 0; i < N; i++ ) cin >> X.at(i);

    long long ans = 0;
    for ( int i = 0; i < N-1; i++ ) {
        int dist = X.at(i+1) - X.at(i);
        long long walk_cost = (long long)A * dist;
        long long tele_cost = B;
        if ( walk_cost < tele_cost ) ans += walk_cost;
        else ans += tele_cost;
    }

    cout << ans << endl;
    return 0;
}
