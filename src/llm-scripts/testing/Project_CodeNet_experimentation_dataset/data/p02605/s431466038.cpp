#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+5; 

void solve() {
    int res = N*100;
    int n; cin >> n;
    vector<int> X(n), Y(n);
    string d(n,'?');
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i] >> d[i];
    }
    auto rotate = [&](){
        for (int i = 0; i < n; i++) {
            if (d[i] == 'R') d[i] = 'U';
            else if (d[i] == 'U') d[i] = 'L';
            else if (d[i] == 'L') d[i] = 'D';
            else d[i] = 'R';

            swap(X[i], Y[i]);
            X[i] = N - X[i];
        }
    };
    // -> <-
    auto ck0 = [&](){
        vector<vector<int>> evs(N+1);
        for (int i = 0; i < n; i++) {
            if (d[i]=='L' || d[i]=='R') {
                evs[Y[i]].push_back(i);
            }
        }
        for (auto& a: evs) {
            sort(a.begin(), a.end(), [&](auto& u, auto& v){
                return X[u] < X[v];
            });
            int n = a.size();
            for (int i = 1; i < n; i++) {
                if (d[a[i-1]] == 'R' && d[a[i]] == 'L') {
                    res = min(res, (X[a[i]] - X[a[i-1]]) * 5);
                }
            }
        }
    };
    // ->
    //   ^
    auto ck1 = [&](){
        vector<vector<int>> evs(N*2);
        for (int i = 0; i < n; i++) {
            if (d[i] == 'R' || d[i] == 'U') {
                evs[X[i]+Y[i]].push_back(i);
            }
        }
        for (auto& a: evs) {
            sort(a.begin(), a.end(), [&](auto& u, auto& v){
                return X[u] < X[v];
            });
            int n = a.size();
            for (int i = 1; i < n; i++) {
                if (d[a[i-1]] == 'R' && d[a[i]] == 'U') {
                    res = min(res, (X[a[i]] - X[a[i-1]]) * 10);
                }
            }
        }
    };
    for (int _ = 0; _ < 4; _++) {
        ck0();ck1();rotate();
    }
    if (res == N*100) cout << "SAFE";
    else cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
