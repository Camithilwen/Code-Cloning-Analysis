#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto& a : A) {
        cin >> a;
    }
    for (auto& b : B) {
        cin >> b;
    }
    vector<int> cnt(N + 1, 0);
    for (auto& a : A) {
        ++cnt[a];
    }
    for (auto& b : B) {
        ++cnt[b];
    }
    rep(i, 0, N) {
        if (cnt[i + 1] > N) {
            cout << "No" << endl;
            return 0;
        }
    }
    reverse(all(B));
    int same_val = 0;
    rep(i, 0, N) {
        if (A[i] == B[i]) {
            same_val = A[i];
            break;
        }
    }
    if (same_val) {
        vector<int> idx_buf;
        rep(i, 0, N) {
            if (B[i] != same_val && A[i] != same_val) {
                idx_buf.push_back(i);
            }
        }
        rep(i, 0, N) {
            if (A[i] == B[i]) {
                int target = idx_buf.back();
                idx_buf.pop_back();
                swap(B[i], B[target]);
            }
        }
    }
    cout << "Yes" << endl;
    rep(i, 0, N) {
        cout << B[i] << " \n"[i + 1 == N];
    }
    return 0;
}